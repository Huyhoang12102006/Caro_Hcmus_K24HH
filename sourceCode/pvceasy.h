#pragma once
#include "board.h"
#include <iostream>
#include "changeconsole.h"
#include "button.h"
#include "cup.h"
#include "ChuX.h"
#include "ChuO.h"
#include "menu.h"
#include"hamve.h"
#include "playgame.h"

void hienmenu();
void VeChuO(int x, int y, bool isGray = false);
void VeChuX(int x, int y, bool isGray = false);
void updateBoardAfterChange_2(const std::vector<int>& toado, const std::vector<char>& xo) {
	for (size_t i = 0; i < toado.size(); i++) {
		int row = toado[i] / BOARD_SIZE;
		int col = toado[i] % BOARD_SIZE;

		board[row][col] = xo[i]; // Cập nhật lại trạng thái mảng `board`
		gotoXY(37 + col * 4, 1 + row * 2); // Di chuyển tới đúng tọa độ hiển thị
		if (xo[i] == 'X') {
			TextColor(240 | 4); // Màu của X
		}
		else if (xo[i] == 'O') {
			TextColor(240 | 1); // Màu của O
		}
		cout << xo[i];
	}
	drawBoard(); // Vẽ lại bảng
}

//máy đánh
pair<int, int> maydanh(int row, int col) {
	pair<int, int> maydanh;
	if (board[row][col - 1] == ' ' && col - 1 >= 0) {
		return { row,col - 1 };
	}
	else if (board[row][col + 1] == ' ' && col + 1 <= 17) {
		return{ row,col + 1 };
	}
	else if (board[row + 1][col] == ' ' && row + 1 <= 17) {
		return{ row + 1,col };
	}
	else if (board[row - 1][col] == ' ' && row - 1 >= 0) {
		return{ row - 1,col };
	}
	else if (board[row - 1][col - 1] == ' ' && row - 1 >= 0 && col - 1 >= 0) {
		return{ row - 1,col - 1 };
	}
	else if (board[row + 1][col + 1] == ' ' && row + 1 <= 17 && col + 1 <= 17) {
		return{ row + 1, col + 1 };
	}
	else if (board[row + 1][col - 1] == ' ' && row + 1 <= 17 && col - 1 >= 0) {
		return{ row + 1,col - 1 };
	}
	else if (board[row - 1][col + 1] == ' ' && col + 1 <= 17 && row - 1 >= 0) {
		return{ row - 1,col + 1 };
	}
	else {
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				if (board[i][j] == ' ') {
					return{ i,j };
				}
				else {
					return{ -1,-1 };
				}
			}
		}
	}
}

void playeasy();
void backcontinue();

void backcontinue() {
	char tam;
	bool cnt = true;
	while (true) {
		tam = _getch();
		if (tam == 75) {
			cnt = false;
			continue;
		}
		else if (tam == 77) {
			cnt = true;
			continue;
		}
		else if (tam == 13 && cnt == true) {
			system("cls");
			resizeConsole(1150, 750);
			system("color f0");
			fixConsoleScroll();
			setConsoleFont(L"Consolas", 16);
			FixConsoleWindow();
			matrixboard();    // Khởi tạo bảng trống
			drawBoard();   // Vẽ bảng cờ caro 18x18
			drawXplayer();
			drawYplayer();
			playeasy();    // Bắt đầu trò chơi
			return;
		}
		else if (tam == 13 && cnt == false) {
			return;
		}
	}
}
//hàm chơi game
void playeasy() {
	int x = 48, y = 2; // Tọa độ ban đầu của con trỏ (ô đầu tiên trong bảng)
	int row = 0, col = 0; // Vị trí tương ứng trong mảng board
	char input;

	// Các vector lưu trạng thái bàn cờ
	vector<int> toado; // Lưu tọa độ các nước đã đi
	vector<char> xo;   // Lưu ký hiệu tương ứng (X hoặc O)

	// Thiết lập giao diện
	SetConsoleOutputCP(437);
	system("cls");
	resizeConsole(1150, 750);
	system("color f0");
	fixConsoleScroll();
	setConsoleFont(L"Consolas", 16);
	FixConsoleWindow();
	VeChuO(121, 1);
	VeChuX(7, 1);
	SetConsoleOutputCP(437); // Đặt bảng mã ANSI
	SetConsoleCP(437);

	matrixboard();
	drawBoard();   // Vẽ bảng cờ caro 18x18
	vebutton(68, 33, 1, true);
	gotoXY(74, 35); cout << "'B' : BACK";



	// vẽ hình thinking cho x mà mắt kính cho O
	Thinking(15, 22);
	gotoXY(26, 23);
	//	cout << ' ';
	gotoXY(26, 24);
	//cout << ' ';
	Wearing_Glass(125, 22);


	while (true) {
		gotoXY(x, y);
		input = _getch();

		if (input == 13 && board[row][col] == ' ') { // Người chơi đánh X

			clearRegion(113, 22, 155, 50);
			Thinking(125, 22);// vẽ icon suy nghĩ
			gotoXY(141, 26);
			cout << ' ';
			gotoXY(141, 25);
			cout << ' ';
			Wearing_Glass(15, 22);

			// Lưu trạng thái nước đi
			board[row][col] = 'X';
			toado.push_back(row * BOARD_SIZE + col); // Lưu tọa độ
			xo.push_back('X');

			if (sfx == 1) {
				PlaySound(TEXT("move.wav"), NULL, SND_ASYNC | SND_FILENAME);
			}
			gotoXY(x, y);
			TextColor(240 | 4);
			cout << 'X';

			// Kiểm tra thắng
			if (checkWinngang(row, col)) {
				highlightWinningCells(row, col, 'X', 0, 1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);

				}
				VeCup(7, 21);
				clearRegion(113, 22, 155, 50);
				crying(125, 22);
				win(13, 36);
				lose(118, 36);
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			if (checkWindoc(row, col)) {
				highlightWinningCells(row, col, 'X', 1, 0);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);

				}
				VeCup(7, 21);
				clearRegion(113, 22, 155, 50);
				crying(125, 22);
				win(13, 36);
				lose(118, 36);
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			if (checkWinchinh(row, col)) {
				highlightWinningCells(row, col, 'X', 1, 1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);

				}
				VeCup(7, 21);
				clearRegion(113, 22, 155, 50);
				crying(125, 22);
				win(13, 36);
				lose(118, 36);

				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			if (checkWinphu(row, col)) {
				highlightWinningCells(row, col, 'X', 1, -1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);

				}
				VeCup(7, 21);
				clearRegion(113, 22, 155, 50);
				crying(125, 22);
				win(13, 36);
				lose(118, 36);
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}



			// Máy đánh O
			pair<int, int> tdmaydanh = maydanh(row, col);
			//if (tdmaydanh.first == -1) {
			//	PlaySound(TEXT("draw.wav"), NULL, SND_ASYNC | SND_FILENAME);
			//	gotoXY(0, BOARD_SIZE * 2); // Thông báo hòa
			//	cout << "DRAWN" << endl;
			//	Sleep(3700);
			//	if (nen == 1) {
			//		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME);
			//	}
			//	backcontinue();
			//	return;
			//}
	

			Sleep(730);
		
			clearRegion(1, 22, 40, 50);
			Thinking(15, 22);
			gotoXY(31, 25);
			cout << ' ';
			gotoXY(31, 26);
			cout << ' ';
			Wearing_Glass(125, 22);

			x = 48 + tdmaydanh.second * 4;
			y = 2 + tdmaydanh.first * 2;
			row = tdmaydanh.first;
			col = tdmaydanh.second;

			// Lưu trạng thái nước đi của máy
			board[row][col] = 'O';
			toado.push_back(row * BOARD_SIZE + col); // Lưu tọa độ
			xo.push_back('O');

			gotoXY(x, y);
			TextColor(240 | 1);
			cout << 'O';

			if (sfx == 1) {
				PlaySound(TEXT("move.wav"), NULL, SND_ASYNC | SND_FILENAME);
			}

			// Kiểm tra thắng
			if (checkWinngang(row, col)) {
				highlightWinningCells(row, col, 'O', 0, 1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);

				}
				VeCup(115, 21);
				clearRegion(1, 22, 40, 50);
				crying(15, 22);
				win(118, 36);
				lose(10, 36);
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			if (checkWindoc(row, col)) {
				highlightWinningCells(row, col, 'O', 1, 0);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);

				}
				VeCup(115, 21);
				clearRegion(1, 22, 40, 50);
				crying(15, 22);
				win(118, 36);
				lose(10, 36);
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			if (checkWinchinh(row, col)) {
				highlightWinningCells(row, col, 'O', 1, 1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);

				}
				VeCup(115, 21);
				clearRegion(1, 22, 40, 50);
				crying(15, 22);
				win(118, 36);
				lose(10, 36);
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			if (checkWinphu(row, col)) {
				highlightWinningCells(row, col, 'O', 1, -1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);

				}
				VeCup(115, 21);
				clearRegion(1, 22, 40, 50);
				crying(15, 22);
				win(118, 36);
				lose(10, 36);
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}

			int dem = 0;
			for (int i = 0; i < 16; i++) {
				for (int j = 0; j < 16; j++) {
					if (board[i][j] != ' ') {
						dem += 1;
					}
				}
			}
			if (dem == 16 * 16) {
				VeCup(7, 21);
				VeCup(115, 21);
				draw(10, 36);
				draw(118, 36);
				break;
			}
		}
		else if (input == 27) { // Nhấn ESC để thoát
			gia = 1;
			break;
		}
		else if (input == 'B' || input == 'b' || input == 27) { // Nếu nhấn B, b hoặc ESC
			system("cls");
			hienmenu(); // Quay lại menu chính
			return;
		}
		// Điều khiển di chuyển con trỏ
		if (input == -32) {
			input = _getch();
			switch (input) {
			case 72: // Mũi tên lên
				if (y > 2) { y -= 2; row--; }
				break;
			case 80: // Mũi tên xuống
				if (y < (BOARD_SIZE * 2) - 1) { y += 2; row++; }
				break;
			case 75: // Mũi tên trái
				if (x > 48) { x -= 4; col--; }
				break;
			case 77: // Mũi tên phải
				if (x < (BOARD_SIZE * 4) - 2 + 45) { x += 4; col++; }
				break;
			}
		}
	}
}

