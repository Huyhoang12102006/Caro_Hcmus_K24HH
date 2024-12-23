#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>
#include <windows.h>  
#include <conio.h>
#include "changeconsole.h"
#include "board.h"
#include <io.h>
#include <fcntl.h>
#include "hamve.h"
#include <locale>
#include <codecvt>
#include "ChuO.h"
#include "ChuX.h"
#include "menu.h"
#include "playgame.h"
#include <thread>
#include <chrono>
#include <atomic>
#include <conio.h>
#include <mutex>
using namespace std;
bool timeOut = false; // Cờ báo hiệu hết thời gian
bool stopTimer = false; // Cờ để dừng bộ đếm thời gian khi cần
mutex mtx; // Dùng để đồng bộ dữ liệu giữa các luồng
void playGame();
void saveGame();
void loadGame();
void hienmenu();
void updateBoardAfterChange();

void updateBoardAfterChangetime(const std::vector<int>& toado, const std::vector<char>& xo) {
	//mtx.lock();
	SetConsoleOutputCP(437);
	drawBoard(); // Vẽ lại bảng
	for (size_t i = 0; i < toado.size(); i += 2) {
		gotoXY(toado[i], toado[i + 1]); // Đến tọa độ x, y
		TextColor(240 | ((xo[i / 2] == 'X') ? 4 : 1)); // Đỏ cho X, xanh cho O
		cout << xo[i / 2];
	}
	//mtx.unlock();
}

void countdownTimer(int duration) {
	int countdown = duration;
	while (countdown > 0) {
		if (stopTimer) return; // Dừng nếu cờ được bật
		mtx.lock();
		if (language == 1) {
			gotoXY(67, 41);
			TextColor(240 | 4);
			SetConsoleOutputCP(CP_UTF8);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "YOU HAVE " << countdown << " SECONDS LEFT";
		}
		else {
			gotoXY(72, 41);
			TextColor(240 | 4);
			SetConsoleOutputCP(CP_UTF8);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << u8"BẠN CÒN " << countdown << u8" GIÂY";
		}
		mtx.unlock();
		this_thread::sleep_for(chrono::seconds(1));
		countdown--;
	}

	mtx.lock();
	if (!stopTimer) {
		timeOut = true; // Báo hiệu hết thời gian
		// Hiển thị dòng chữ TIME OUT!!!
		if (language == 1) {
			gotoXY(67, 41);
			cout << "                         ";
			gotoXY(74, 41);
			TextColor(240 | 4);
			SetConsoleOutputCP(CP_UTF8);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "TIME OUT!!";
		}
		else {
			gotoXY(67, 41);
			cout << "                         ";
			gotoXY(74, 41);
			SetConsoleOutputCP(CP_UTF8);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << u8"HẾT GIỜ!!";
		}
	}
	mtx.unlock();
}

void PVPtime() {
	vector<int> toado;
	vector<char> xo;
	int i = 0, j = 0;
	int x = 48, y = 2; // Tọa độ ban đầu của con trỏ (ô đầu tiên trong bảng)
	int row = 0, col = 0; // Vị trí tương ứng trong mảng board
	char currentPlayer = 'X'; // Bắt đầu với người chơi X
	char input;
	int dem = 0;
	bool breakall = false;

	//Khối hàm điều chỉnh hiển thị mà kích thước ...(7 hàm) 
	SetConsoleOutputCP(437);
	system("cls");
	resizeConsole(1150, 750);
	system("color f0");
	fixConsoleScroll();
	setConsoleFont(L"Consolas", 16);
	FixConsoleWindow();
	VeChuO(121, 1);
	VeChuX(7, 1);
	SetConsoleCP(437);
	matrixboard();
	drawBoard();
	vebutton_2(68, 33, 1, true);
	gotoXY(74, 35); cout << "'B' : BACK";

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
	thread timer;

	bool isBlue = true; // Biến trạng thái để luân phiên giữa đỏ và xám
	bool isRed = false; // Biến trạng thái để luân phiên giữa đỏ và xám

	while (true) {
		gotoXY(x, y); // Di chuyển con trỏ đến tọa độ hiện tại
		input = _getch(); // Lấy phím từ người dùng

		if (input == 'B' || input == 'b' || input == 27) { // Nếu nhấn B, b hoặc ESC
			stopTimer = true; // Dừng bộ đếm thời gian
			if (timer.joinable()) {
				timer.join(); // Đảm bảo dừng luồng
			}
			system("cls");
			hienmenu(); // Quay lại menu
			return;
		}

		if (breakall) {
			while (true) {
				if (_kbhit()) {
					char key = _getch();
					if (key == 'B' || key == 'b' || key == 27) { // Nhấn B hoặc ESC
						system("cls");
						hienmenu(); // Quay lại menu
						return;
					}
				}
			}
		}


		stopTimer = false;
		timeOut = false;

		if (!timer.joinable()) { // Chỉ tạo luồng nếu nó chưa chạy
			timer = thread(countdownTimer, 15);
		}

		while (!timeOut) {
			mtx.lock();
			gotoXY(x, y); // Di chuyển con trỏ đến tọa độ hiện tại
			mtx.unlock();
			if (_kbhit()) {

				input = _getch(); // Lấy phím từ người dùng
				mtx.lock();
				
				if (input == 'B' || input == 'b' || input == 27) { // Nếu nhấn B, b hoặc ESC
					stopTimer = true; // Dừng bộ đếm thời gian
					if (timer.joinable()) {
						timer.join(); // Đảm bảo dừng luồng
					}
					system("cls");
					hienmenu(); // Quay lại menu
					return;
				}

				if (input == 13 && board[row][col] == ' ') { // Nhấn Enter để đánh dấu ô hiện tại
					if (sfx == 1) {
						PlaySound(TEXT("move.wav"), NULL, SND_ASYNC | SND_FILENAME);
					}
					toado.push_back(x);
					toado.push_back(y);
					xo.push_back(currentPlayer);
					TextColor(240 | 3);
					//dem += 1;
					cout << currentPlayer;
					board[row][col] = currentPlayer; // Lưu vào mảng board

					gotoXY((currentPlayer == 'X') ? 10 : 120, 40);
					cout << "                           ";

					// Cập nhật màu của chữ X sau mỗi lượt đánh
					mtx.unlock();
					isBlue = !isBlue;
					VeChuO(121, 1, isBlue);
					mtx.lock();

					isRed = !isRed; // Đổi trạng thái màu
					mtx.unlock();
					VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)

					mtx.lock();
					mtx.unlock();

					SetConsoleOutputCP(437);
					updateBoardAfterChangetime(toado, xo);
					mtx.lock();

					// Kiểm tra và highlight chiến thắng theo chiều ngang
					if (checkWinngang(row, col)) {
						if (nen % 2 == 1) {
							PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
						}
						isBlue = !isBlue;
						VeChuO(121, 1, isBlue);
						isRed = !isRed; // Đổi trạng thái màu
						VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
						updateBoardAfterChangetime(toado, xo);
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
						stopTimer = true;
						mtx.unlock();
						breakall = true;
						while (true) {
							if (_kbhit()) {
								char key = _getch();
								if (key == 'B' || key == 'b' || key == 27) { // Nhấn B hoặc ESC
									stopTimer = true;
									system("cls");
									hienmenu(); // Quay lại menu
									return;
								}
							}
						}
						break;
					}
					if (checkWindoc(row, col)) {
						if (nen % 2 == 1) {
							PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
						}
						isBlue = !isBlue;
						VeChuO(121, 1, isBlue);
						isRed = !isRed; // Đổi trạng thái màu
						VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
						updateBoardAfterChangetime(toado, xo);
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
						stopTimer = true;
						mtx.unlock();
						breakall = true;
						while (true) {
							if (_kbhit()) {
								char key = _getch();
								if (key == 'B' || key == 'b' || key == 27) { // Nhấn B hoặc ESC
									stopTimer = true;
									system("cls");
									hienmenu(); // Quay lại menu
									return;
								}
							}
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
						updateBoardAfterChangetime(toado, xo);
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
						stopTimer = true;
						mtx.unlock();
						breakall = true;
						while (true) {
							if (_kbhit()) {
								char key = _getch();
								if (key == 'B' || key == 'b' || key == 27) { // Nhấn B hoặc ESC
									stopTimer = true;
									system("cls");
									hienmenu(); // Quay lại menu
									return;
								}
							}
						}
						break;
					}
					if (checkWinphu(row, col)) {
						if (nen % 2 == 1) {
							PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
						}
						isBlue = !isBlue;
						VeChuO(121, 1, isBlue);
						isRed = !isRed; // Đổi trạng thái màu
						VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
						updateBoardAfterChangetime(toado, xo);
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
						stopTimer = true;
						mtx.unlock();
						breakall = true;
						while (true) {
							if (_kbhit()) {
								char key = _getch();
								if (key == 'B' || key == 'b' || key == 27) { // Nhấn B hoặc ESC
									stopTimer = true;
									system("cls");
									hienmenu(); // Quay lại menu
									return;
								}
							}
						}
						break;
					}
					if (currentPlayer == 'X') {
						clearRegion(117, 22, 155, 50);
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
					//Xử lí hòa
					int dem = 0;
					for (int i = 0; i < 16; i++) {
						for (int j = 0; j < 16; j++) {
							if (board[i][j] != ' ') {
								dem += 1;
							}
						}
					}
					if (dem == 16 * 16) {
						if (nen % 2 == 1) {
							PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
						}
						VeCup(7, 21);
						VeCup(115, 21);
						draw(5, 36);
						draw(118, 36);
						Sleep(3700);
						if (nen % 2 == 1) {
							PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
						}
						stopTimer = true;
						mtx.unlock();
						breakall = true;
						while (true) {
							if (_kbhit()) {
								char key = _getch();
								if (key == 'B' || key == 'b' || key == 27) { // Nhấn B hoặc ESC
									stopTimer = true;
									system("cls");
									hienmenu(); // Quay lại menu
									return;
								}
							}
						}
						break;
					}
					//Chuyển lượt chơi
					currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
					stopTimer = true; // Dừng bộ đếm thời gian
					mtx.unlock();
					break;
				}
				else if (input == 27) { // Nhấn ESC để thoát
					stopTimer = true; // Dừng bộ đếm thời gian
					mtx.unlock();
					if (timer.joinable()) timer.join();
					return;
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
				SetConsoleOutputCP(437);
				mtx.unlock();
			}
		}
		// Khi hết thời gian
		if (timeOut || breakall) {
			//mtx.lock();
			lock_guard<mutex> guard(mtx);
			stopTimer = true;
			if (timer.joinable()) {
				timer.join(); // Dừng luồng hiện tại
			}
			//mtx.unlock();
			if (nen % 2 == 1) {
				PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
			}
			isBlue = !isBlue;
			VeChuO(121, 1, isBlue);
			isRed = !isRed; // Đổi trạng thái màu
			VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
			updateBoardAfterChangetime(toado, xo);

			if (currentPlayer == 'O') {
				VeCup(7, 21);
				clearRegion(113, 22, 155, 50);
				crying(125, 22);
				win(13, 36);
				lose(118, 36);
			}
			else if (currentPlayer == 'X') {
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
		// Kết thúc luồng đếm thời gian nếu nó vẫn chạy
		if (timer.joinable()) {
			stopTimer = true;
			timer.join();
		}
	}
	// Đảm bảo tất cả luồng dừng khi thoát
	if (timer.joinable()) {
		timer.join();
	}
	return;
}