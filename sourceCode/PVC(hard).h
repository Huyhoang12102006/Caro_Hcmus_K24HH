#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "board.h"
#include "ChuO.h"
#include "ChuX.h"
#include "cup.h"
#include "playgame.h"
#include"hamve.h"

using namespace std;

// Kiểm tra nước đi tiềm năng để chặn chuỗi liên tiếp của người chơi
pair<int, int> checkBlockingMove(char player, int requiredConsecutive) {
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (board[row][col] == ' ') {
				board[row][col] = player;
				// Kiểm tra các hướng
				int directions[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };
				for (auto& d : directions) {
					int count = 1;
					for (int step = 1; step <= 4; step++) {
						int r = row + step * d[0];
						int c = col + step * d[1];
						if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == player)
							count++;
						else break;
					}
					for (int step = 1; step <= 4; step++) {
						int r = row - step * d[0];
						int c = col - step * d[1];
						if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == player)
							count++;
						else break;
					}
					if (count >= requiredConsecutive) {
						board[row][col] = ' ';
						return { row, col };
					}
				}
				board[row][col] = ' ';
			}
		}
	}
	return { -1, -1 };
}

// Tìm nước đi tốt nhất cho máy gần vị trí người chơi
pair<int, int> findBestMove(int lastRow, int lastCol) {
	// Chặn nếu người chơi có 4 quân liên tiếp
	pair<int, int> move = checkBlockingMove('X', 4);
	if (move.first != -1) return move;

	// Chặn nếu người chơi có 3 quân liên tiếp
	move = checkBlockingMove('X', 3);
	if (move.first != -1) return move;

	// Đánh gần vị trí người chơi đi cuối cùng
	vector<pair<int, int>> nearbyMoves;
	for (int dr = -1; dr <= 1; dr++) {
		for (int dc = -1; dc <= 1; dc++) {
			if (dr == 0 && dc == 0) continue;

			int newRow = lastRow + dr;
			int newCol = lastCol + dc;
			if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE && board[newRow][newCol] == ' ') {
				nearbyMoves.push_back({ newRow, newCol });
			}
		}
	}

	if (!nearbyMoves.empty()) {
		return nearbyMoves[rand() % nearbyMoves.size()];
	}

	// Đánh ô trống đầu tiên nếu không tìm được nước đi gần
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (board[row][col] == ' ') {
				return { row, col };
			}
		}
	}
	return { -1, -1 };
}

void playGamehard() {
	vector<int> toado;
	vector<char> xo;
	int x = 48, y = 2; // Tọa độ ban đầu của con trỏ (ô đầu tiên trong bảng)
	int row = 0, col = 0; // Vị trí tương ứng trong mảng board
	char input;
	// khối hàm điều chỉnh hiển thị mà kích thước ...(7 hàm)
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


	
	Thinking(15, 22);
	gotoXY(26, 23);
//	cout << ' ';
	gotoXY(26, 24);
	//cout << ' ';
	Wearing_Glass(125, 22);

	while (true) {
		gotoXY(x, y); // Di chuyển con trỏ đến tọa độ hiện tại
		input = _getch(); // Lấy phím từ người dùng
		
		if (input == 'B' || input == 'b' || input == 27) { // Nếu nhấn B, b hoặc ESC
			system("cls");
			hienmenu(); // Quay lại menu chính
			return;
		}

		if (input == 13 && board[row][col] == ' ') {

			clearRegion(113, 22, 155, 50);
			Thinking(125, 22);// vẽ icon suy nghĩ
			gotoXY(141, 26);
			cout << ' ';
			gotoXY(141, 25);
			cout << ' ';
			Wearing_Glass(15, 22);

			if (sfx == 1) {
				PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);

			}
			gotoXY(x, y);
			TextColor(240 | 4);
			board[row][col] = 'X';
			cout << 'X';

			// Kiểm tra và highlight chiến thắng theo chiều ngang
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
			// kiểm tra và highlight chiến thắng theo chiều dọc 
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
			//kiểm tra highlight chiến thắng theo chéo chính
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

			//kiểm tra highlight chiến thắng theo chéo phụ
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
			//máy đánh
			pair<int, int> aiMove = findBestMove(row, col);
			if (aiMove.first == -1) {
				PlaySound(TEXT("draw.wav"), NULL, SND_ASYNC | SND_FILENAME);
				gotoXY(0, BOARD_SIZE * 2); // Di chuyển con trỏ xuống cuối bảng để thông báo
				cout << "DRAW" << endl;
			}
			Sleep(730);

			clearRegion(1, 22, 40, 50);
			Thinking(15, 22);
			gotoXY(31, 25);
			cout << ' ';
			gotoXY(31, 26);
			cout << ' ';
			Wearing_Glass(125, 22);

			x =48 + aiMove.second * 4;
			y = 2 + aiMove.first * 2;
			row = aiMove.first;
			col = aiMove.second;

			gotoXY(x, y);
			if (sfx == 1) {
				PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);

			}
			TextColor(240 | 1);

			cout << 'O';
			board[aiMove.first][aiMove.second] = 'O';

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
			// kiểm tra và highlight chiến thắng theo chiều dọc 
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
			//kiểm tra highlight chiến thắng theo chéo chính
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
			//kiểm tra highlight chiến thắng theo chéo phụ
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
			break;
		}
		// Điều khiển di chuyển con trỏ bằng các phím mũi tên
		if (input == -32) { // Phím mũi tên trả về mã -32, sau đó là mã của từng mũi tên
			input = _getch();
			switch (input) {
			case 72: // Mũi tên lên
				if (y > 2) { y -= 2; row--; } // Di chuyển lên trên (mỗi ô cách nhau 2 dòng)
				break;
			case 80: // Mũi tên xuống
				if (y < (BOARD_SIZE * 2) - 1) { y += 2; row++; } // Di chuyển xuống
				break;
			case 75: // Mũi tên trái
				if (x > 48) { x -= 4; col--; } // Di chuyển sang trái (mỗi ô cách nhau 4 ký tự)
				break;
			case 77: // Mũi tên phải
				if (x < (BOARD_SIZE * 4) - 2 + 45) { x += 4; col++; } // Di chuyển sang phải
				break;
			}
		}
	}
}