#pragma once
#include <stdio.h>
#include <conio.h>
#include <ctime> 
#include <iostream>
#include <windows.h>  
#include "move.h"
#include "dohoamenu.h"
#include "pvceasy.h"
#include "playgame.h"
#include "savegame.h"
#include "PvPtime.h"
#include "PVC(hard).h"
#include "menuviet.h"
#define BOARD_SIZE 16
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15
using namespace std;
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
void setConsoleColor(int background, int text)
{
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
}
// Hàm display_text hiển thị dòng chữ tại vị trí với màu sắc tùy thuộc vào trạng thái highlighted
void menu_pve();
void menu_pvp();
void menu_new_game();
void hienmenu();
void resetGame();
void playGame();
void saveGame();
void loadGame();
void updateBoardAfterChange();

// Hàm display_text hiển thị dòng chữ tại vị trí với màu sắc tùy thuộc vào trạng thái highlighted
void display_text(int x, int y, const string& nd, bool highlighted, int width)
{
    if (highlighted) {
        TextColor(240 | 2);// Màu chữ vàng nếu được chọn
    }
    else {
        TextColor(240 | 1); // Màu chữ xám nếu không được chọn
    }

    int padding = (width - nd.length()) / 2;
    gotoXY(x + padding, y);
    cout << nd;

    TextColor(240 | 7);  // Đặt lại màu chữ sau khi hiển thị
}

// Hàm vẽ khung cho lựa chọn menu
void draw_frame(int x, int y, int width, bool highlighted)
{
    gotoXY(x - 3, y);
    if (highlighted) {
        TextColor(240 | 2); // Khung vàng nếu được chọn
    }
    else {
        TextColor(240 | 0); // Khung đen nếu không được chọn
    }

    cout << "== " << string(width, ' ') << " ==";
    TextColor(240 | 7);  // Đặt lại màu chữ sau khi vẽ khung
}

// Hàm hiển thị màn hình chi tiết và quay lại menu khi nhấn phím Esc
void display_screen(const string& title)
{
    //   ShowCur(false);
    TextColor(240 | 1);
    gotoXY(40, 12);
    cout << "This is the " << title << " screen.";
    gotoXY(40, 14);
    cout << "Press Esc to return to the main menu...";
    while (true)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == 27) // Phím Esc được nhấn
            {
                return;
            }
        }
    }
}
void howtoplay()
{
    if (nen % 2 == 1) {
        PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

    }
    system("cls");  // Xóa màn hình trước đó
    SetConsoleOutputCP(CP_UTF8); // Đảm bảo mã hóa đúng
    TextColor(240 | 1); // Đặt màu nền trắng và chữ đen
    std::cout << u8R"(                   
                                                                                                                                      
                                                                                                                                              
                                         ██╗  ██╗ ██████╗ ██╗    ██╗    ████████╗ ██████╗     ██████╗ ██╗      █████╗ ██╗   ██╗              
                                         ██║  ██║██╔═══██╗██║    ██║    ╚══██╔══╝██╔═══██╗    ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝              
                        ╔══════════════  ███████║██║   ██║██║ █╗ ██║       ██║   ██║   ██║    ██████╔╝██║     ███████║ ╚████╔╝ ═══════════╗  
                        ║                ██╔══██║██║   ██║██║███╗██║       ██║   ██║   ██║    ██╔═══╝ ██║     ██╔══██║  ╚██╔╝             ║  
                        ║                ██║  ██║╚██████╔╝╚███╔███╔╝       ██║   ╚██████╔╝    ██║     ███████╗██║  ██║   ██║              ║  
                        ║                ╚═╝  ╚═╝ ╚═════╝  ╚══╝╚══╝        ╚═╝    ╚═════╝     ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝              ║  
                        ║                                                                                                                 ║  
                        ║                                                                                                                 ║  
                        ║═════════════════════════════════════════════════════════════════════════════════════════════════════════════════║  
                        ║                                                                                                                 ║  
                        ║   Align exactly 5 consecutive marks (X or O) in a straight line horizontally, vertically, or diagonally to win. ║  
                        ║   Players alternate turns, placing one mark (X or O) on an empty cell of the 20x20 board.                       ║  
                        ║   In time limit mode, each player has 30 seconds per move; exceeding the time results in an automatic loss.     ║  
                        ║                                                                                                                 ║  
                        ║═════════════════════════════════════════════════════════════════════════════════════════════════════════════════║  
                        ║                                                                                                                 ║  
                        ║                                      ╔═══╗                  ╔═══╗                                               ║  
                        ║                                      ║ ▲ ║                  ║ ▲ ║  : Go Up                                      ║  
                        ║                                  ╔═══╬═══╬═══╗              ╚═══╝                                               ║  
                        ║                                  ║ ◄ ║ ▼ ║ ► ║              ╔═══╗                                               ║  
                        ║                                  ╚═══╩═══╩═══╝              ║ ▼ ║  : Go Down                                    ║  
                        ║                                                             ╚═══╝                                               ║  
                        ║                                Navigation Button            ╔═══╗                                               ║  
                        ║                                                             ║ ► ║  : Go Right                                   ║  
                        ║                                                             ╚═══╝                                               ║  
                        ║                                                             ╔═══╗                                               ║  
                        ║                                                             ║ ◄ ║  : Go Left                                    ║  
                        ║                                                             ╚═══╝                                               ║  
                        ║                                ╔═══════╗                    ╔═══════╗                                           ║  
                        ║                                ║ ENTER ║ : Select           ║  Esc  ║ : Go back                                 ║  
                        ║                                ╚═══════╝                    ╚═══════╝                                           ║  
                        ║                                                                                                                 ║  
                        ║                                      Press Esc to return the Main Menu                                          ║  
                        ║                                                                                                                 ║  
                        ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝  
                                                                                                                                             
                                                                                                                              
                                )";
	setConsoleColor(BLUE, BRIGHT_WHITE);
	gotoXY(79, 11);
	cout << "  RULES  ";
	gotoXY(78, 17);
	cout << "  CONTROLS  ";
    // Vẽ nút BACK
    int x = 30, y = 36; // Tọa độ của nút BACK
    int choice = 0;     // 0: chưa hiển thị mũi tên, 1: BACK được chọn

    gotoXY(x, y);
    TextColor(240 | 4); // Nền đỏ, chữ trắng
    cout << " BACK ";
    TextColor(240 | 1); // Khôi phục màu mặc định

    // Vòng lặp xử lý sự kiện phím
    while (true) {
        if (_kbhit()) {
            char c = _getch();

            // Xử lý phím Enter
            if (c == 13 && choice == 1) { // Enter khi mũi tên đang trỏ BACK
                system("cls");
                hienmenu();  // Quay lại menu chính
                return;
            }

            // Xử lý phím lên/xuống
            if (c == 72 || c == 80) { // Phím lên (72) hoặc xuống (80)
                // Nếu mũi tên chưa hiển thị, bắt đầu hiển thị
                if (choice == 0) {
                    gotoXY(x - 3, y);
                    TextColor(240 | 3);
                    cout << "->";
                    choice = 1;
                }
            }
        }
    }
}

void load_game()
{
    if (nen % 2 == 1) {
        PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

    }
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    TextColor(240 | 5);
    cout << u8R"(
                                                                                                             
                                                                                                             
                                                                                                             
                                                                                                             
                                                                                                             
                                     ██╗      ██████╗  █████╗ ██████╗      ██████╗  █████╗ ███╗   ███╗███████╗███████╗           
                                     ██║     ██╔═══██╗██╔══██╗██╔══██╗    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔════╝           
                                     ██║     ██║   ██║███████║██║  ██║    ██║  ███╗███████║██╔████╔██║█████╗  ███████╗           
                         ╔═══════════██║     ██║   ██║██╔══██║██║  ██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ╚════██║══════════╗
                         ║           ███████╗╚██████╔╝██║  ██║██████╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗███████║          ║
                         ║           ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝          ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ║                                                                                                      ║
                         ╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝
                                                                                                             
                                                                                                             
                                )";
	void iconnoel(int x, int y);
	loadGame();
	char input;
	while (true) {
		input = _getch(); // Nhận phím từ người dùng
		if (input == 'B' || input == 'b' || input == 27) { // Nếu nhấn 'B' hoặc 'b' hoặc phím ESC
			system("cls");  // Xóa màn hình
			hienmenu();  // Hiển thị menu chính
			return;  // Quay lại menu chính
		}
	}
	

}

void about_us()
{
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	}
	system("cls");  // Xóa màn hình trước đó
	SetConsoleOutputCP(CP_UTF8); // Đảm bảo mã hóa đúng
	std::cout << u8R"(                                                             
                                                                                    
                                                                                                                                                                                                             
                                                                                                                            
                                                                                                                                 
                                                                                                                                
                                                █████╗ ██████╗  ██████╗ ██╗   ██╗████████╗    ██╗   ██╗███████╗                         
                                               ██╔══██╗██╔══██╗██╔═══██╗██║   ██║╚══██╔══╝    ██║   ██║██╔════╝                         
                                               ███████║██████╔╝██║   ██║██║   ██║   ██║       ██║   ██║███████╗                         
                       ╔═══════════════════════██╔══██║██╔══██╗██║   ██║██║   ██║   ██║═══════██║   ██║╚════██║═══════════════════════╗ 
                       ║                       ██║  ██║██████╔╝╚██████╔╝╚██████╔╝   ██║       ╚██████╔╝███████║                       ║ 
                       ║                       ╚═╝  ╚═╝╚═════╝  ╚═════╝  ╚═════╝    ╚═╝        ╚═════╝ ╚══════╝                       ║ 
                       ║                                                                                                              ║ 
                       ║                                                                                                              ║ 
                       ║                                                                                                              ║ 
                       ║                                                                                                              ║ 
                       ║      █▓▓█████████████████████▓▓█                                                                             ║ 
                       ║      █▓▓██                 ██▓▓█  ▒██████████▒                                                               ║ 
                       ║      █▓▓██                 ██▓▓█  ▒██████████▒                                                               ║ 
                       ║      █▓▓██    ██     ██    ██▓▓█  ▒██      ██▒                                                               ║ 
                       ║      █▓▓██        █        ██▓▓█  ▒██████████▒                                                               ║ 
                       ║      █▓▓██     █     █     ██▓▓█  ▒██      ██▒                                                               ║ 
                       ║      █▓▓██      █████      ██▓▓█  ▒██████████▒                                                               ║ 
                       ║      █▓▓██                 ██▓▓█  ▒██████████▒                                                               ║ 
                       ║      █▓▓█████████████████████▓▓█  ▒██████████▒                                                               ║ 
                       ║                ░█████░            ▒██████████▒                                                               ║ 
                       ║             █████████████         ▒██████████▒                                                               ║ 
                       ║                                                                                                              ║ 
                       ║                                                                                                              ║ 
                       ║       _  _     ___   __  __   _   _    ___                    ___  _  _    _____ _______ _______ ____        ║ 
                       ║      | || |   / __| |  \/  | | | | |  / __|                  |__ \| || |  / ____|__   __|__   __|___ \       ║ 
                       ║      | __ |  | (__  | |\/| | | |_| |  \__ \                     ) | || |_| |       | |     | |    __) |      ║ 
                       ║      |_||_|   \___| |_|__|_|  \___/   |___/                    / /|__   _| |       | |     | |   |__ <       ║ 
                       ║     _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|                  / /_   | | | |____   | |     | |   ___) |      ║ 
                       ║     "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'                 |____|  |_|  \_____|  |_|     |_|  |____/       ║ 
                       ║                                                                                                              ║ 
                       ║                                                                                                              ║ 
                       ╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ 
                                                                                                                                
                                                                                                                                          
                                                                                                                                                              
                                                                                 
	                                )";
	gotoXY(85, 14);
	setConsoleColor(BLACK, BRIGHT_WHITE);
	cout << " Group 5 - Fundamentals of programming ";
	TextColor(240 | RED);
	gotoXY(85, 16);
	cout << u8R"(           PROJECT CARO CHESS       )";
	gotoXY(85, 18);
	TextColor(240 | BLACK);
	cout << u8R"(─────────═════ INSTRUCTOR ═════────────)";
	_setmode(_fileno(stdout), _O_U16TEXT);
	gotoXY(92, 20);
	wcout << L"PhD. Trương Toàn Thịnh";
	_setmode(_fileno(stdout), _O_TEXT);
	gotoXY(85, 22);
	cout << u8R"(──────────═════ AUTHORS ═════─────────)";
	// Đặt chế độ UTF-8 cho console
	_setmode(_fileno(stdout), _O_U16TEXT);  // Đổi từ _O_U8TEXT sang _O_U16TEXT
	gotoXY(91, 24);
	TextColor(240 | 1);
	wcout << L"24120248 - Phí Hoàng Đức";
	gotoXY(91, 25);
	wcout << L"24120239 - Phí Công Tuấn";
	gotoXY(91, 26);
	wcout << L"24120245 - Trần Lê Đức Việt";
	gotoXY(91, 27);
	wcout << L"24120315 - Phạm Huy Hoàng";
	_setmode(_fileno(stdout), _O_TEXT);
	// Vẽ nút BACK
	int x = 30, y = 36; // Tọa độ của nút BACK
	int choice = 0;     // 0: chưa hiển thị mũi tên, 1: BACK được chọn

	gotoXY(x, y);
	TextColor(240 | 4); // Nền đỏ, chữ trắng
	cout << " BACK ";
	TextColor(240 | 1); // Khôi phục màu mặc định

	// Vòng lặp xử lý sự kiện phím
	while (true) {
		if (_kbhit()) {
			char c = _getch();

			// Xử lý phím Enter
			if (c == 13 && choice == 1) { // Enter khi mũi tên đang trỏ BACK
				system("cls");
				hienmenu();  // Quay lại menu chính
				if (exitall) {
					return;
				}
				return;
			}

			// Xử lý phím lên/xuống
			if (c == 72 || c == 80) { // Phím lên (72) hoặc xuống (80)
				// Nếu mũi tên chưa hiển thị, bắt đầu hiển thị
				if (choice == 0) {
					gotoXY(x - 3, y);
					TextColor(240 | 3); // Mũi tên xanh
					std::cout << "->";
					choice = 1; // Đặt trạng thái đang chọn BACK
				}
			}
		}
	}
}
// Hàm hỗ trợ
void drawOption(int x, int y, const string& text, int color) {
	gotoXY(x, y);
	TextColor(color);
	cout << text;
}
void clearLine(int x, int y, int length) {
	gotoXY(x, y);
	for (int i = 0; i < length; i++) {
		cout << " ";
	}
}

// Vẽ icon mặt trong setting
void iconne(int x, int y) {
	// system("cls");
	 //system("Color F0");

	ifstream in;
	in.open("icon.txt", ios::in);
	int a[200][200];
	int dong_ve; // số dòng
	int cot_ve; // số cột
	in >> dong_ve;
	in >> cot_ve;
	docdata(in, a, dong_ve, cot_ve);

	for (int i = 0; i < dong_ve; i = i + 2) {
		gotoXY(x, y + i / 2);
		for (int j = 0; j < cot_ve; j++) {
			setColor(a[i][j], a[i + 1][j]);
			SetConsoleOutputCP(CP_UTF8);
			cout << u8"▀"; // Sử dụng ký tự "▀" để vẽ ô
		}
		cout << endl;
	}
	in.close();
}

void display_setting()
{
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	}
	SetConsoleOutputCP(CP_UTF8);
	std::cout << u8R"(                   






                                                                                                                 
                                                ███████╗███████╗████████╗████████╗██╗███╗   ██╗ ██████╗ ███████╗         
                                                ██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗  ██║██╔════╝ ██╔════╝         
                                                ███████╗█████╗     ██║      ██║   ██║██╔██╗ ██║██║  ███╗███████╗         
                             ╔═════════════════ ╚════██║██╔══╝     ██║      ██║   ██║██║╚██╗██║██║   ██║╚════██║ ═════════════════╗
                             ║                  ███████║███████╗   ██║      ██║   ██║██║ ╚████║╚██████╔╝███████║                  ║
                             ║                  ╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝                  ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ║                                                                                                    ║
                             ╚════════════════════════════════════════════════════════════════════════════════════════════════════╝
                                                                           
                                )";

	//Biến 3 lựa chọn sfx, music, language
	int a = 3;
	if (nen == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME);
	}
	gotoXY(40, 12);
	char contro;
	//Vị trí music mode
	gotoXY(25 + 40, 28 - 18 + 7);
	TextColor(240 | 0);
	cout << "MUSIC MODE:  ";
	TextColor(240 | 4);
	gotoXY(90, 28 - 18 + 7);
	string d1 = (*nenptr == 1) ? "ON" : "OFF";
	cout << d1;
	//Vị trí sound effect
	gotoXY(25 + 40, 32 - 18 + 7);
	TextColor(240 | 0);
	cout << "SFX:  ";
	TextColor(240 | 4);
	gotoXY(90, 32 - 18 + 7);
	string d2 = (*sfxptr == 1) ? "ON" : "OFF";
	cout << d2;
	//Language
	gotoXY(25 + 40, 36 - 18 + 7);
	TextColor(240 | 0);
	cout << "LANGUAGE:  ";
	TextColor(240 | 4);
	gotoXY(90, 36 - 18 + 7);
	string d3 = (*languageptr == 1) ? "ENGLISH" : "VIETNAMESE";
	cout << d3;
	//Vẽ icon
	iconne(35, 18);
	// nút back
	gotoXY(25 + 40, 40 - 18 + 7);
	TextColor(240 | 0);
	cout << "BACK";

	while (true) {
		contro = _getch();
		if (contro == 13) {
			if (sfx == 1) {
				PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
			}
			*tam = (*tam % 2 == 1) ? 0 : 1;
			if (tam == &sfx) {
				clearLine(90, 32 - 18 + 7, 5);
				string c = (*tam == 1) ? "ON" : "OFF";
				gotoXY(90, 32 - 18 + 7);
				TextColor(240 | 4);
				cout << c;
			}
			if (tam == &nen) {
				clearLine(90, 28 - 18 + 7, 5);
				string c = (*tam == 1) ? "ON" : "OFF";
				gotoXY(90, 28 - 18 + 7);
				TextColor(240 | 4);
				cout << c;
			}
			if (tam == &language) {
				clearLine(90, 36 - 18 + 7, 10);
				string c = (*tam == 1) ? "ENGLISH" : "VIETNAMESE";
				gotoXY(90, 36 - 18 + 7);
				TextColor(240 | 4);
				cout << c;
			}
			if (tam == &back) {
				system("cls");
				hienmenu();  // Quay lại menu chính
				if (exitall) {
					return;
				}
				return;
			}
			continue;
		}

		else if (contro == 72) {
			a = (a == 1) ? a : a - 1;
			if (sfx == 1) {
				PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
			}
			if (a == 1) {
				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 28 - 18 + 7);
				cout << "->";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 32 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 36 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 40 - 18 + 7);
				cout << "   ";

				tam = &nen;
				continue;

			}
			if (a == 2) {
				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 28 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 32 - 18 + 7);
				cout << "->";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 36 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 40 - 18 + 7);
				cout << "   ";

				tam = &sfx;
				continue;

			}
			if (a == 3) {
				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 28 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 32 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 36 - 18 + 7);
				cout << "->";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 40 - 18 + 7);
				cout << "   ";
				tam = &language;
				continue;

			}
			if (a == 4) {
				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 28 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 32 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 36 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 40 - 18 + 7);
				cout << "->";

				tam = &back;
				continue;

			}
		}
		else if (contro == 80) {
			a = (a == 4) ? a : a + 1;
			if (sfx == 1) {
				PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
			}
			if (a == 1) {
				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 28 - 18 + 7);
				cout << "->";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 32 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 36 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 40 - 18 + 7);
				cout << "   ";
				tam = &nen;
				continue;

			}
			if (a == 2) {
				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 28 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 32 - 18 + 7);
				cout << "->";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 36 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 40 - 18 + 7);
				cout << "   ";
				tam = &sfx;
				continue;

			}
			if (a == 3) {
				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 28 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 32 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 36 - 18 + 7);
				cout << "->";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 40 - 18 + 7);
				cout << "   ";
				tam = &language;
				continue;

			}
			if (a == 4) {
				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 28 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 32 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 36 - 18 + 7);
				cout << "   ";

				TextColor(240 | 3);
				gotoXY(25 + 40 - 5, 40 - 18 + 7);
				cout << "->";

				tam = &back;
				continue;

			}
		}
	}
}

void menu_new_game();
void menu_pve();

void menu_pvp() {
	SetColor(0, 15);
	khungnewgame(38, 18);
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	vePVP(35, 10);
	chill(85, 10);

	// Vị trí trung tâm màn hình
	int centerX = 40; // X trung tâm (thay đổi giá trị nếu cần để cân đối màn hình của bạn)
	int centerY = 20; // Y trung tâm

	// Khởi tạo tùy chọn chế độ chơi PvP
	vector<string> options = { "NO LIMIT", "TIME LIMIT","BACK" };
	int num_options = options.size();
	int current_choice = 0;
	
	// Vẽ tất cả các lựa chọn ban đầu
	for (int i = 0; i < num_options; ++i) {
		gotoXY(centerX, centerY + i * 2);
		if (i == current_choice) {
			TextColor(240 | 2); // Màu sáng khi được chọn
			cout << "-> " << options[i];
		}
		else {
			TextColor(240 | 1); // Màu xám khi không được chọn
			cout << "   " << options[i];
		}
		TextColor(240 | 7); // Đặt lại màu sau khi hiển thị
	}

	// Vòng lặp điều khiển menu
	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) { // Kiểm tra phím mũi tên
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				c = _getch();
				if (c == 72) { // Mũi tên trái
					current_choice = (current_choice - 1 + num_options) % num_options;
				}
				else if (c == 80) { // Mũi tên phải
					current_choice = (current_choice + 1) % num_options;
				}
			}
			else if (c == 13) { // Phím Enter được nhấn
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				system("cls");
				system("color F0");
				if (options[current_choice] == "TIME LIMIT") {
					PVPtime();
					while (true) {
						if (_kbhit()) {
							char c = _getch();
							if (c == 'b' || c == 'B') {
								system("cls");
								menu_pvp();
								return;
							}
						}
					}
				}
				else if (options[current_choice] == "NO LIMIT") {
					vector<int> toado;
					vector<char> xo;
					resetGame();
					playGame();
					while (true) {
						if (_kbhit()) {
							char c = _getch();
							if (c == 'b' || c == 'B') {
								system("cls");
								menu_pvp();
								return;
							}
							else {
								continue;
							}
						}
					}
				}
				else if (options[current_choice] == "BACK") {
					// Quay lại menu chính
					system("cls");
					menu_new_game();
					return;
				}
			}
			else if (c == 27) { // Phím Esc được nhấn
				// Thoát khỏi menu và quay lại menu PvP/PvE
				system("cls");
				menu_new_game();
				return;
			}

			// Vẽ lại menu với trạng thái được cập nhật
			for (int i = 0; i < num_options; ++i) {
				gotoXY(centerX, centerY + i * 2);
				if (i == current_choice) {
					TextColor(240 | 2); // Màu sáng khi được chọn
					cout << "-> " << options[i];
				}
				else {
					TextColor(240 | 1); // Màu xám khi không được chọn
					cout << "   " << options[i];
				}
				TextColor(240 | 7); // Đặt lại màu sau khi hiển thị
			}
		}
	}
}
void menu_pve() {
	SetColor(0, 15);
	khungnewgame(37, 18);
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	vePVE(35, 10);
	chill(85, 10);

	// Vị trí trung tâm màn hình
	int centerX = 41; // X trung tâm (thay đổi giá trị nếu cần để cân đối màn hình của bạn)
	int centerY = 20; // Y trung tâm

	// Khởi tạo tùy chọn chế độ chơi
	vector<string> options = { "EASY", "HARD", "BACK" };
	int num_options = options.size();
	int current_choice = 0;

	// Vẽ tất cả các lựa chọn ban đầu
	for (int i = 0; i < num_options; ++i) {
		gotoXY(centerX, centerY + i * 2);
		if (i == current_choice) {
			TextColor(240 | 2); // Màu sáng khi được chọn
			cout << "-> " << options[i];
		}
		else {
			TextColor(240 | 1); // Màu xám khi không được chọn
			cout << "   " << options[i];
		}
		TextColor(240 | 7); // Đặt lại màu sau khi hiển thị
	}

	// Vòng lặp điều khiển menu
	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) { // Kiểm tra phím mũi tên
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				c = _getch();
				if (c == 72) { // Mũi tên lên
					current_choice = (current_choice - 1 + num_options) % num_options;
				}
				else if (c == 80) { // Mũi tên xuống
					current_choice = (current_choice + 1) % num_options;
				}
			}
			else if (c == 13) { // Phím Enter được nhấn
				system("cls");
				system("color F0");
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				if (options[current_choice] == "EASY") {
					system("cls");
					playeasy();

					while (true) {
						if (_kbhit()) {
							char c = _getch();
							if (c == 'B' || c == 'b') {
								system("cls");
								menu_pve();
								return;
							}
						}
					}
				}
				else if (options[current_choice] == "HARD") {
					// Gọi hàm để xử lý chế độ HARD
					system("cls");
					playGamehard();

					while (true) {
						if (_kbhit()) {
							char c = _getch();
							if (c == 'B' || c == 'b') {
								system("cls");
								menu_pve();
								return;
							}
						}
					}
				}
				else if (options[current_choice] == "BACK") {
					// Quay lại menu chính
					system("cls");
					menu_new_game();
					return;
				}
			}
			else if (c == 27) { // Phím Esc được nhấn
				// Thoát khỏi menu và quay lại menu PvP/PvE
				system("cls");
				menu_new_game();
				return;
			}
			// Vẽ lại menu với trạng thái được cập nhật
			for (int i = 0; i < num_options; ++i) {
				gotoXY(centerX, centerY + i * 2);
				if (i == current_choice) {
					TextColor(240 | 2); // Màu sáng khi được chọn
					cout << "-> " << options[i];
				}
				else {
					TextColor(240 | 1); // Màu xám khi không được chọn
					cout << "   " << options[i];
				}
				TextColor(240 | 7); // Đặt lại màu sau khi hiển thị
			}
		}
	}
}

void menu_new_game() {
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}

	// Vị trí trung tâm màn hình
	int centerX = 75; // X trung tâm (thay đổi giá trị nếu cần để cân đối màn hình của bạn)
	int centerY = 13; // Y trung tâm
	chunewgame(48, 5);
	iconnoel(20, 4);
	iconnoel(125, 4);
	snowman(10, 22);
	pine(67, 22);
	santa(100, 32);
	ground(0, 42);
	SetColor(0, 15);
	khungnewgame(70, 11);
	// Khởi tạo tùy chọn chế độ chơi
	vector<string> options = { "PvP", "PvE", "BACK" };
	int num_options = options.size();
	int current_choice = 0; // Lựa chọn hiện tại

	// Vẽ tất cả các lựa chọn ban đầu kèm mũi tên
	for (int i = 0; i < num_options; ++i) {
		gotoXY(centerX, centerY + i * 2);
		if (i == current_choice) {
			TextColor(240 | 2); // Màu sáng khi được chọn
			cout << "-> " << options[i];
		}
		else {
			TextColor(240 | 1); // Màu xám khi không được chọn
			cout << "   " << options[i];
		}
		TextColor(240 | 7); // Đặt lại màu sau khi hiển thị
	}

	
	// Vòng lặp điều khiển menu
	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) { // Kiểm tra phím mũi tên
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				c = _getch();
				if (c == 72) { // Mũi tên lên
					current_choice = (current_choice - 1 + num_options) % num_options;
				}
				else if (c == 80) { // Mũi tên xuống
					current_choice = (current_choice + 1) % num_options;
				}
			}
			else if (c == 13) { // Phím Enter được nhấn
				system("cls");
				system("color F0");
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				if (options[current_choice] == "PvP") {
					// Gọi hàm để xử lý chế độ PvP
					system("cls");
					menu_pvp();
					return;
				}
				else if (options[current_choice] == "PvE") {
					// Gọi hàm để xử lý chế độ PvE
					system("cls");
					menu_pve();
					return;
				}
				else if (options[current_choice] == "BACK") {
					// Quay lại menu chính
					system("cls");
					hienmenu();
					return;
				}
			}
			else if (c == 27) { // Phím Esc được nhấn
				// Quay lại menu chính
				system("cls");
				hienmenu();
				return;
			}

			// Vẽ lại menu với trạng thái được cập nhật
			for (int i = 0; i < num_options; ++i) {
				gotoXY(centerX, centerY + i * 2);
				if (i == current_choice) {
					TextColor(240 | 2); // Màu sáng khi được chọn
					cout << "-> " << options[i];
				}
				else {
					TextColor(240 | 1); // Màu xám khi không được chọn
					cout << "   " << options[i];
				}
				TextColor(240 | 7); // Đặt lại màu sau khi hiển thị
			}
		}
	}
}

void hienmenu() {
	if (exitall) {
		return;
	}
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	if (language == 0) {
		SetConsoleOutputCP(CP_UTF8);
		_setmode(_fileno(stdout), _O_TEXT);
		hienmenuV();
		return;
	}
	SetConsoleOutputCP(850); // Bảng mã ANSI
	SetConsoleCP(850);       // Đầu vào tương ứng

	system("cls");
	resizeConsole(1150, 750);
	system("color f0");
	fixConsoleScroll();
	setConsoleFont(L"Consolas", 16);
	FixConsoleWindow();
	dohoamenu();
	khungmenu(65, 16);
	Red_Ranger(30, 16);
	Hero(110, 16);
	

	int x = 70, y = 18; // Tọa độ menu
	vector<string> labels = { "NEW GAME", "LOAD GAME", "HOW TO PLAY", "ABOUT", "SETTINGS" };
	int sl = labels.size(); // Số lượng menu
	int xp = x, yp = y;     // Tọa độ hiện tại
	int xcu = xp, ycu = yp; // Tọa độ cũ
	bool kt = true;

	// Hiển thị menu lần đầu
	for (int i = 0; i < sl; ++i) {
		draw_frame(x, y + i * 2, 20, (i == 0)); // Dòng đầu được chọn
		display_text(x, y + i * 2, labels[i], (i == 0), 20);
	}

	while (true) {
		if (kt) {
			// Làm nổi bật lựa chọn hiện tại
			draw_frame(xcu, ycu, 20, false);
			display_text(xcu, ycu, labels[(ycu - y) / 2], false, 20);

			xcu = xp;
			ycu = yp;

			draw_frame(xp, yp, 20, true);
			display_text(xp, yp, labels[(yp - y) / 2], true, 20);
			kt = false;
		}


		if (_kbhit()) {
			// Kiểm tra nếu có phím được nhấn

			if (sfx == 1) {
				PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);

			}
			char c = _getch();
			if (c == -32) { // Phím mũi tên
				c = _getch();
				if (c == 72) { // Lên
					kt = true;
					yp = (yp > y) ? (yp - 2) : (y + 2 * (sl - 1));
				}
				else if (c == 80) { // Xuống
					kt = true;
					yp = (yp < y + 2 * (sl - 1)) ? (yp + 2) : y;
				}
			}
			else if (c == 13) { // Enter
				system("cls");
				system("color f0");
				if (labels[(yp - y) / 2] == "NEW GAME") {
					menu_new_game();
					hienmenu();
					if (exitall) {
						return;
					}
				}
				else if (labels[(yp - y) / 2] == "LOAD GAME") {
					load_game();
					if (exitall) {
						return;
					}
				}
				else if (labels[(yp - y) / 2] == "ABOUT") {
					about_us();
					if (exitall) {
						return;
					}
				}
				else if (labels[(yp - y) / 2] == "HOW TO PLAY") {
					howtoplay();
					if (exitall) {
						return;
					}
				}
				else if (labels[(yp - y) / 2] == "SETTINGS") {
					display_setting();
					if (exitall) {
						return;
					}
				}

				// Quay lại menu
				system("cls");
				system("color f0");
				for (int i = 0; i < sl; ++i) {
					draw_frame(x, y + i * 2, 20, (i == (yp - y) / 2));
					display_text(x, y + i * 2, labels[i], (i == (yp - y) / 2), 20);
				}
				kt = true;
			}
			else if (c == 27) { // Esc
				system("cls");
				system("color f0");
				exitall = true;
				return;
			}
		}
	}
}