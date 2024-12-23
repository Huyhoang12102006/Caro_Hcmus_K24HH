#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>
#include <windows.h>  
#include <conio.h>
#include "changeconsole.h"
#include "board.h"
#include "savegame.h"
#include "ChuO.h"
#include "ChuX.h"
#include "cup.h"
#include "menu.h"
#include "button.h"
#include"hamve.h"
using namespace std;

void resetGame() {
	// Reset lại bàn cờ
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			board[i][j] = ' ';  // Khởi tạo lại bàn cờ (tất cả ô đều trống)
		}
	}
	// Reset lại các bước đi và người chơi
	toado.clear();
	xo.clear();
	currentPlayer = 'X';  // Bắt đầu ván mới với người chơi X
}

void updateBoardAfterChange() {
	mtx.lock();
	drawBoard(); // Vẽ lại bảng
	for (size_t i = 0; i < toado.size(); i += 2) {
		gotoXY(toado[i], toado[i + 1]); // Đến tọa độ x, y
		TextColor(240 | ((xo[i / 2] == 'X') ? 4 : 1)); // Đỏ cho X, xanh cho O
		cout << xo[i / 2];
	}
	mtx.unlock();
}

void playGame() {
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}

	int i = 0, j = 0, dem = xo.size();
	int x = 48, y = 2;
	char currentPlayer = (dem % 2 == 0) ? 'X' : 'O';
	int row = 0, col = 0;
	char input;

	//Khối hàm điều chỉnh hiển thị mà kích thước ...(7 hàm)
	system("cls");
	SetConsoleOutputCP(437);
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
	drawBoard();
	updateBoardAfterChange();
	vebutton(47, 33, 1, true);
	gotoXY(53, 35); cout << "'B' : BACK";
	vebutton(89, 33, 1, true);
	gotoXY(92, 35); cout << "'S' : SAVE GAME";

	bool isBlue = true;
	bool isRed = false;

	if (currentPlayer == 'X') {
		clearRegion(1, 22, 40, 50);
		Wearing_Glass(125, 22);
		gotoXY(31, 25);
		cout << ' ';
		gotoXY(31, 26);
		cout << ' ';
		Thinking(15, 22);
	}
	else if (currentPlayer == 'O') {
		clearRegion(113, 22, 155, 48);
		Wearing_Glass(15, 22);
		gotoXY(141, 26);
		cout << ' ';
		gotoXY(141, 25);
		cout << ' ';
		Thinking(125, 22);
	}

	while (true) {
		gotoXY(x, y); // Di chuyển con trỏ đến tọa độ hiện tại
		input = _getch(); // Lấy phím từ người dùng

		if (input == 'B' || input == 'b' || input == 27) { // Nếu nhấn B, b hoặc ESC
			system("cls");
			hienmenu(); // Quay lại menu chính
			return;
		}
		//Lưu game
		if (input == 'S' || input == 's') { // Nhấn S để lưu game
			vebutton(47, 33, 1, false);
			vebutton(89, 33, 1, false);
			saveGame();
			system("cls");
			hienmenu();
		}
		if (input == 13 && board[row][col] == ' ') { // Nhấn Enter để đánh dấu ô hiện tại
			 // hàm vẽ mặt khóc mặt cười.
			if (sfx == 1) {
				PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
			}
			if (currentPlayer == 'X') {
				clearRegion(113, 22, 155, 50);
				Thinking(125, 22);// vẽ icon suy nghĩ
				gotoXY(141, 26);
				cout << ' ';
				gotoXY(141, 25);
				cout << ' ';
				Wearing_Glass(15, 22);
			}
			else if (currentPlayer == 'O') {
				clearRegion(1, 22, 40, 50);
				Thinking(15, 22);
				gotoXY(31, 25);
				cout << ' ';
				gotoXY(31, 26);
				cout << ' ';
				Wearing_Glass(125, 22);
			}

			toado.push_back(x);
			toado.push_back(y);
			xo.push_back(currentPlayer);
			dem += 1;
			cout << currentPlayer;
			board[row][col] = currentPlayer; // Lưu vào mảng board

			// Cập nhật màu của chữ X sau mỗi lượt đánh
			isBlue = !isBlue;
			VeChuO(121, 1, isBlue);
			isRed = !isRed; // Đổi trạng thái màu
			VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
			updateBoardAfterChange();

			// Kiểm tra và highlight chiến thắng theo chiều ngang
			if (checkWinngang(row, col)) {
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
				}
				isBlue = !isBlue;
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				highlightWinningCells(row, col, currentPlayer, 0, 1);
				if (currentPlayer == 'X') {
					VeCup(7, 21);
					clearRegion(113, 22, 155, 50);
					crying(125, 22);
					win(13, 36);
					lose(118, 36);
				}
				else if (currentPlayer == 'O') {
					VeCup(115, 21);
					clearRegion(1, 22, 40, 50);
					crying(15, 22);
					win(118, 36);
					lose(10, 36);
				}
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			// kiểm tra và highlight chiến thắng theo chiều dọc 
			if (checkWindoc(row, col)) {
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
				}
				isBlue = !isBlue;
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				highlightWinningCells(row, col, currentPlayer, 1, 0);
				if (currentPlayer == 'X') {
					VeCup(7, 21);
					clearRegion(113, 22, 155, 50);
					crying(125, 22);
					win(13, 36);
					lose(118, 36);
				}
				else if (currentPlayer == 'O') {
					VeCup(115, 21);
					clearRegion(1, 22, 40, 50);
					crying(15, 22);
					win(118, 36);
					lose(10, 36);
				}
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			if (checkWinchinh(row, col)) {
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
				}
				isBlue = !isBlue;
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				highlightWinningCells(row, col, currentPlayer, 1, 1);
				if (currentPlayer == 'X') {
					VeCup(7, 21);
					clearRegion(113, 22, 155, 50);
					crying(125, 22);
					win(13, 36);
					lose(118, 36);
				}
				else if (currentPlayer == 'O') {
					VeCup(115, 21);
					clearRegion(1, 22, 40, 50);
					crying(15, 22);
					win(118, 36);
					lose(10, 36);
				}
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			//kiểm tra highlight chiến thắng theo chéo phụ
			if (checkWinphu(row, col)) {
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
				}
				isBlue = !isBlue;
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				highlightWinningCells(row, col, currentPlayer, 1, -1);
				if (currentPlayer == 'X') {
					VeCup(7, 21);
					clearRegion(113, 22, 155, 50);
					crying(125, 22);
					win(13, 36);
					lose(118, 36);
				}
				else if (currentPlayer == 'O') {
					VeCup(115, 21);
					clearRegion(1, 22, 40, 50);
					crying(15, 22);
					win(118, 36);
					lose(10, 36);
				}
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				break;
			}
			// hàm xử lý hòa, cần thêm đồ họa
			int cnt = 0;
			for (int i = 0; i < 16; i++) {
				for (int j = 0; j < 16; j++) {
					if (board[i][j] != ' ') {
						cnt += 1;
					}
				}
			}
			if (cnt == 16 * 16) {
				if (nen % 2 == 1) {
					PlaySound(TEXT("draw"), NULL, SND_ASYNC | SND_FILENAME);
				}
				Sleep(3700);
				if (nen % 2 == 1) {
					PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
				}
				
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				
				VeCup(7, 21);
				VeCup(115, 21);
				clearRegion(113, 50, 155, 70);
				clearRegion(1, 50, 40, 70);
				TextColor(240 | 4);
				draw(5, 36);
				draw(118, 36);
				break;
			}
			// Chuyển lượt chơi
			currentPlayer = (dem % 2 == 0) ? 'X' : 'O';
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