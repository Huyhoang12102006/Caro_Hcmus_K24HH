
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // Nếu bạn sử dụng _getch()
#include "playgame.h"
#include "cup.h"
#include "ChuX.h"
#include "ChuO.h"
#include "hamve.h"
#include "menu.h"
#include "menuviet.h"
#include "board.h"
#include <queue>
#include <filesystem>
#include <algorithm>
using namespace std;

char currentPlayer;  // Người chơi hiện tại ('X' hoặc 'O')
vector<int> toado;   // Danh sách tọa độ của các lượt đi
vector<char> xo;     // Danh sách ký hiệu của các lượt đi (X hoặc O)
void saveGame() {
	gotoXY(120, 30);
    SetConsoleOutputCP(CP_UTF8); // Đảm bảo mã hóa đúng
    TextColor(240 | 2);
    cout << u8R"(




                                                              ░█▀▀░█▀█░█░█░█▀▀░░░█▀▀░█▀█░█▄█░█▀▀
                                                              ░▀▀█░█▀█░▀▄▀░█▀▀░░░█░█░█▀█░█░█░█▀▀
                                             ╔════════════════░▀▀▀░▀░▀░░▀░░▀▀▀░░░▀▀▀░▀░▀░▀░▀░▀▀▀═══════════════╗
                                             ║                                                                 ║
                                             ║                                                                 ║
                                             ║                                                                 ║
                                             ╚═════════════════════════════════════════════════════════════════╝
)";
	string saveDir = "savegames";
	filesystem::create_directory(saveDir);
	vector<string> saveFiles;

	// Liệt kê các file hiện có
	for (const auto& entry : filesystem::directory_iterator(saveDir)) {
		saveFiles.push_back(entry.path().string());
	}

	// Nếu vượt quá 5 file, xóa file cũ nhất
	if (saveFiles.size() >= 5) {
		filesystem::remove(saveFiles.front());
	}

	// Nhập tên file mới
	gotoXY(50, 39);
	string gameName;
	cout << "Enter a name for the saved game (<10 characters): ";
	getline(cin, gameName);
	if (gameName.size() > 10) gameName = gameName.substr(0, 10);

	string fileName = saveDir + "/" + gameName + ".txt";
	ofstream outFile(fileName);
	if (!outFile.is_open()) {
		cerr << "Error: Unable to save game!" << endl;
		return;
	}

	// Lưu dữ liệu
	outFile << currentPlayer << endl; // Lưu người chơi hiện tại

	// Lưu trạng thái bảng
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			outFile << board[i][j]; // Lưu ký tự
		}
		outFile << endl; // Kết thúc dòng
	}

	// Lưu các bước đi (tọa độ và ký hiệu)
	for (size_t i = 0; i < toado.size(); i += 2) {
		outFile << toado[i] << " " << toado[i + 1] << " " << xo[i / 2] << std::endl;
	}

	outFile.close();
	cout << "Game saved as " << gameName << "!" << std::endl;
}

// Hàm in chuỗi căn giữa
void printCentered(const string& text, int row) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	if (GetConsoleScreenBufferInfo(hConsole, &consoleInfo)) {
		int screenWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
		int textLength = text.size();
		int x = (screenWidth - textLength) / 2;
		gotoXY(x, row);
		cout << text;
	}
}

void loadGame() {
	string saveDir = "savegames";
	vector<string> saveFiles;

	// Liệt kê file
	for (const auto& entry : filesystem::directory_iterator(saveDir)) {
		//saveFiles.push_back(entry.path().string());
		saveFiles.push_back(entry.path().stem().string());
	}

	// Thêm tùy chọn "Back" vào cuối danh sách
	saveFiles.push_back("BACK");

	if (saveFiles.empty()) {
		printCentered("No saved games found!", 15);
		return;
	}

	int selected = 0;
	int baseRow = 17; // Dòng đầu tiên của danh sách
	gotoXY(64, 15);
	printCentered("----CHOOSE A SAVED GAME----", 15);

	// In danh sách lần đầu
	for (size_t i = 0; i < saveFiles.size() - 1; ++i) {
		printCentered(saveFiles[i], baseRow + i * 2);
	}

	TextColor(240 | 4);
	printCentered("BACK", baseRow + (saveFiles.size() - 1) * 2);
	TextColor(240 | 5);


	while (true) {
		// Cập nhật dòng hiện tại
		gotoXY(72, baseRow + selected*2);
		cout << "->";
		printCentered(saveFiles[selected], baseRow + selected * 2);

		// Đảm bảo chỉ thay đổi màu chữ khi không phải là "BACK"
		if (saveFiles[selected] == "BACK") {
			TextColor(240 | 4);  // Đặt lại màu mặc định cho các game khác
			printCentered(saveFiles[selected], baseRow + selected * 2);
		}
		else {
			TextColor(240 | 5);  // Đặt lại màu mặc định cho các game khác
			printCentered(saveFiles[selected], baseRow + selected * 2);
		}

		char input = _getch();

		// Trả lại dòng trước đó về trạng thái bình thường
		gotoXY(72, baseRow + selected*2);
		cout << "  ";
		printCentered(saveFiles[selected], baseRow + selected * 2);

		if (input == 72 && selected > 0) { // Lên
			--selected;
		}
		else if (input == 80 && selected < saveFiles.size() - 1) { // Xuống
			++selected;
		}
		else if (input == 13) { // Enter
			if (saveFiles[selected] == "BACK") {
				system("cls");
				hienmenu();
			}
			else {
				cout << "\nYou selected: " << saveFiles[selected] << endl;
				break;
			}
		}
	}

	// Ghép lại đường dẫn đầy đủ
	string selectedFile = saveDir + "/" + saveFiles[selected] + ".txt";

	// Đọc file được chọn
	ifstream inFile(selectedFile);
	if (!inFile.is_open()) {
		cerr << "Error: Unable to load game!" << endl;
		return;
	}

	// Đọc người chơi hiện tại
	inFile >> currentPlayer;
	inFile.ignore(); // Bỏ ký tự xuống dòng sau currentPlayer

	// Đọc trạng thái bảng
	for (int i = 0; i < BOARD_SIZE; ++i) {
		string line;
		getline(inFile, line);
		for (int j = 0; j < BOARD_SIZE; ++j) {
			board[i][j] = line[j];
		}
	}

	// Đọc tọa độ và người chơi
	toado.clear();
	xo.clear();
	int a, b;
	char player;
	while (inFile >> a >> b >> player) {
		toado.push_back(a);
		toado.push_back(b);
		xo.push_back(player);
	}

	inFile.close();
	cout << "Game loaded successfully!" << std::endl;

	// Cập nhật trạng thái
	updateBoardAfterChange();
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
	SetConsoleOutputCP(437); // Đặt bảng mã ANSI
	SetConsoleCP(437);
	vebutton(47, 33, 1, true);
	gotoXY(53, 35); cout << "'B' : BACK";
	vebutton(89, 33, 1, true);
	gotoXY(92, 35); cout << "'S' : SAVE GAME";

	bool isBlue; // Biến trạng thái để luân phiên giữa đỏ và xám
	bool isRed; // Biến trạng thái để luân phiên giữa đỏ và xám
	if (dem % 2 == 0) {
		isBlue = true;
		isRed = false;
	}
	else {
		isBlue = false;
		isRed = true;
	}
	VeChuO(1, 1, isBlue);
	VeChuX(1, 1, isRed);

	if (!toado.empty() && !xo.empty()) {
		updateBoardAfterChange(); // Vẽ lại bảng từ dữ liệu đã tải
	}
	else {
		matrixboard(); // Khởi tạo bảng mới
		drawBoard();
	}

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
			dem++;
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
				isBlue = !isBlue;
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				highlightWinningCells(row, col, currentPlayer, 0, 1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
				}
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
				isBlue = !isBlue;
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				highlightWinningCells(row, col, currentPlayer, 1, 0);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
				}
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
				isBlue = !isBlue;
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				highlightWinningCells(row, col, currentPlayer, 1, 1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
				}
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
				isBlue = !isBlue;
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				highlightWinningCells(row, col, currentPlayer, 1, -1);
				if (nen % 2 == 1) {
					PlaySound(TEXT("victory"), NULL, SND_ASYNC | SND_FILENAME);
				}
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
				VeChuO(121, 1, isBlue);
				isRed = !isRed; // Đổi trạng thái màu
				VeChuX(7, 1, isRed); // Vẽ lại chữ X với màu mới (đỏ hoặc xám)
				updateBoardAfterChange();
				VeCup(7, 21);
				VeCup(115, 21);
				draw(10, 36);
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