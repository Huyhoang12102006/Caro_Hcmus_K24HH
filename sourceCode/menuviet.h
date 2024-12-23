#pragma once
#include "menu.h"
#include "playgame.h"
#include"dohoamenu.h"
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

void menu_pveV();
void menu_pvpV();
void menu_new_gameV();
void hienmenu();
void hienmenuV();
void playGame();
void saveGame();
void loadGame();
void updateBoardAfterChange();
using namespace std;

void setConsoleColor(int background, int text);
// Hàm display_text hiển thị dòng chữ tại vị trí với màu sắc tùy thuộc vào trạng thái highlighted
void display_textV(int x, int y, const string& nd, bool highlighted, int width)
{
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);

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
void draw_frameV(int x, int y, int width, bool highlighted)
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

void howtoplayV()
{
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	system("cls");  // Xóa màn hình trước đó
	SetConsoleOutputCP(CP_UTF8); // Đảm bảo mã hóa đúng
	TextColor(240 | 1); // Đặt màu nền trắng và chữ đen
	std::cout << u8R"(                                                                                                                                           
                                                                                                                                 
                                                     ██╗                                                                             
                                                    ██╔╝                                         ███═╗                               
                                                    ╚═╝                                            ██║                               
                                           ██████╗ █████╗  ██████╗██╗  ██╗     ██████╗██╗  ██╗ ██████║ ██╗                           
                                          ██╔════╝██╔══██╗██╔════╝██║  ██║    ██╔════╝██║  ██║██╔═══██╗██║                           
                ╔════════════════════════ ██║     ███████║██║     ███████║    ██║     ███████║██║   ██║██║ ═══════════════════════╗  
                ║                         ██║     ██╔══██║██║     ██╔══██║    ██║     ██╔══██║██║   ██║██║                        ║  
                ║                         ╚██████╗██║  ██║╚██████╗██║  ██║    ╚██████╗██║  ██║╚██████╔╝██║                        ║  
                ║                          ╚═════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝     ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝                        ║  
                ║                                                                                                                 ║  
                ║                                                                                                                 ║  
                ║═════════════════════════════════════════════════════════════════════════════════════════════════════════════════║  
                ║                                                                                                                 ║  
                ║                                                                                                                 ║  
                ║                                                                                                                 ║  
                ║                                                                                                                 ║  
                ║                                                                                                                 ║  
                ║                                                                                                                 ║  
                ║═════════════════════════════════════════════════════════════════════════════════════════════════════════════════║  
                ║                                                                                                                 ║  
                ║                                                     ╔═══╗                  ╔═══╗                                ║  
                ║                                                     ║ ▲ ║                  ║ ▲ ║  :                             ║  
                ║              ███████████████                    ╔═══╬═══╬═══╗              ╚═══╝                                ║  
                ║             █████████████████                   ║ ◄ ║ ▼ ║ ► ║              ╔═══╗                                ║  
                ║           ███  ████████████████                 ╚═══╩═══╩═══╝              ║ ▼ ║  :                             ║  
                ║         ███      ███████     ████                                          ╚═══╝                                ║  
                ║         █████  ██████████████████                                          ╔═══╗                                ║  
                ║         █████████████████████████                                          ║ ► ║  :                             ║  
                ║         █████████       █████████                                          ╚═══╝                                ║  
                ║         ███████           ███████                                          ╔═══╗                                ║  
                ║           ███               ███                                            ║ ◄ ║  :                             ║  
                ║                                                                            ╚═══╝                                ║  
                ║                                               ╔═══════╗                    ╔═══════╗                            ║  
                ║                                               ║ ENTER ║ :                  ║  Esc  ║ :                          ║  
                ║                                               ╚═══════╝                    ╚═══════╝                            ║  
                ║                                                                                                                 ║  
                ║                                                                                                                 ║  
                ║                                                                                                                 ║  
                ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝  
                                                                                                                                        
                                                                                                                          )";
	setConsoleColor(BLUE, BRIGHT_WHITE);
	gotoXY(70, 20);
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"  ĐIỀU KHIỂN  ";
	gotoXY(71, 13);
	wcout << L"  LUẬT CHƠI  ";
	TextColor(240 | BLUE);
	gotoXY(22, 15);
	wcout << L" Xếp chính xác 5 dấu (X hoặc O) liên tiếp trên một đường thẳng ngang, dọc, hoặc chéo để thắng.  ";
	gotoXY(22, 16);
	wcout << L" Người chơi thay phiên nhau, đặt một dấu (X hoặc O) vào ô trống trên bàn cờ kích thước 20x20.  ";
	gotoXY(22, 17);
	wcout << L" Trong chế độ giới hạn thời gian, mỗi người chơi có 30 giây cho mỗi lượt; vượt quá sẽ thua ngay lập tức.  ";
	gotoXY(69, 28);
	wcout << L" Nút điều hướng ";
	gotoXY(106, 23);
	wcout << L"Đi lên";
	gotoXY(106, 26);
	wcout << L"Đi xuống";
	gotoXY(106, 29);
	wcout << L"Đi qua phải";
	gotoXY(106, 32);
	wcout << L"Đi qua trái";
	gotoXY(109, 35);
	wcout << L"Quay lại";
	gotoXY(80, 35);
	wcout << L"Chọn/ Đánh";
	_setmode(_fileno(stdout), _O_TEXT);

	// Vẽ nút BACK
	int x = 23, y = 39; // Tọa độ của nút BACK
	int choice = 0;     // 0: chưa hiển thị mũi tên, 1: BACK được chọn

	gotoXY(x, y);
	TextColor(240 | 4); // Nền đỏ, chữ trắng
	cout << u8" TRỞ VỀ ";
	TextColor(240 | 1); // Khôi phục màu mặc định

	// Vòng lặp xử lý sự kiện phím
	while (true) {
		if (_kbhit()) {
			char c = _getch();

			// Xử lý phím Enter
			if (c == 13 && choice == 1) { // Enter khi mũi tên đang trỏ BACK
				system("cls");
				hienmenuV();
				if (exitall) {
					return;
				}
				;  // Quay lại menu chính
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
void load_gameV()
{
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	}
	system("cls");  // Xóa màn hình trước đó
	SetConsoleOutputCP(CP_UTF8); // Đảm bảo mã hóa đúng
	TextColor(240 | 5); // Đặt màu nền trắng và chữ đen
	// Hiển thị nội dung "About Us"
	std::cout << u8R"(                                                                                                                                     
                                                                                                                                     
                                                                   ██╗                                                               
                                                                    █║                    ██                                         
                                                                   █╔╝                   █╔╗█                                        
                                                                   ╚╝                    ╚╝╚╝                                        
                                                       ████████╗ █████╗ ██╗    ██╗     ███████╗███╗   ██╗                            
                                                       ╚══██╔══╝██╔══██╗██║    ██║     ██╔════╝████╗  ██║                            
                                                          ██║   ███████║██║    ██║     █████╗  ██╔██╗ ██║                            
                           ╔═══════════════════════════   ██║   ██╔══██║██║    ██║     ██╔══╝  ██║╚██╗██║ ════════════════════════╗  
                           ║                              ██║   ██║  ██║██║    ███████╗███████╗██║ ╚████║                         ║  
                           ║                              ╚═╝   ╚═╝  ╚═╝╚═╝    ╚══════╝╚══════╝╚═╝  ╚═══╝                         ║  
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
void about_usV()
{
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	}
	// Vẽ màn hình "About Us"
	system("cls");  // Xóa màn hình trước đó
	SetConsoleOutputCP(CP_UTF8); // Đảm bảo mã hóa đúng
	// TextColor(240 | 1); // Đặt màu nền trắng và chữ đen

	// Hiển thị nội dung "About Us"
	std::cout << u8R"(                                                             
                                                                                    
                                                                                 
                                 
                                                                  ██                                                                       
                                                                 █╔╗█                                   ██╗                                
                                                                 ╚╝╚╝                                   ╚═╝                                
                                              ████████╗██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗     ████████╗██╗███╗   ██╗                      
                                              ╚══██╔══╝██║  ██║██╔═══██╗████╗  ██║██╔════╝     ╚══██╔══╝██║████╗  ██║                      
                                                 ██║   ███████║██║   ██║██╔██╗ ██║██║  ███╗       ██║   ██║██╔██╗ ██║                      
                          ╔══════════════════════██║   ██╔══██║██║   ██║██║╚██╗██║██║   ██║       ██║   ██║██║╚██╗██║════════════════════╗ 
                          ║                      ██║   ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝       ██║   ██║██║ ╚████║                    ║ 
                          ║                      ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝        ╚═╝   ╚═╝╚═╝  ╚═══╝                    ║ 
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
	gotoXY(91, 14);
	setConsoleColor(BLACK, BRIGHT_WHITE);
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L" NHÓM 5 - Cơ sở lập trình ";
	TextColor(240 | RED);
	gotoXY(87, 16);
	wcout << L"           ĐỒ ÁN CỜ CARO       ";
	gotoXY(85, 18);
	TextColor(240 | BLACK);
	_setmode(_fileno(stdout), _O_TEXT);

	cout << u8R"(─────────═════           ═════────────)";
	_setmode(_fileno(stdout), _O_U16TEXT);
	gotoXY(85 + 15, 18);
	wcout << L"HƯỚNG DẪN";
	gotoXY(92, 20);
	wcout << L"PhD. Trương Toàn Thịnh";
	_setmode(_fileno(stdout), _O_TEXT);
	gotoXY(85, 22);
	cout << u8R"(──────────═════         ═════─────────)";
	_setmode(_fileno(stdout), _O_U16TEXT);
	gotoXY(85 + 16, 22); wcout << L"TÁC GIẢ";

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
	int x = 32, y = 36;
	int choice = 0;

	gotoXY(x, y);
	TextColor(240 | 4); // Nền đỏ, chữ trắng
	cout << u8" TRỞ VỀ ";
	TextColor(240 | 1); // Khôi phục màu mặc định

	// Vòng lặp xử lý sự kiện phím
	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (c == 13 && choice == 1) {
				system("cls");
				hienmenuV();
				if (exitall) {
					return;
				}
				return;
			}
			if (c == 72 || c == 80) {
				if (choice == 0) {
					gotoXY(x - 3, y);
					TextColor(240 | 3);
					std::cout << "->";
					choice = 1;
				}
			}
		}
	}
}
// Hàm hỗ trợ
void drawOptionV(int x, int y, const string& text, int color) {
	gotoXY(x, y);
	TextColor(color);
	cout << text;
}
void clearLineV(int x, int y, int length) {
	gotoXY(x, y);
	for (int i = 0; i < length; i++) {
		cout << " ";
	}
}

void display_settingV() {
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	SetConsoleOutputCP(CP_UTF8);
		std::cout << u8R"(                                                                                                                                         
                                                                                                                                         
                                                                              ██╗                                                        
                                                                             ██╔╝                                                        
                                                                          ██ ╚═╝                       ██                                
                                                                         █╔╗█                         █╔╗█                               
                                                                         ╚╝╚╝                         ╚╝╚╝                               
                                                   ████████╗██╗  ██╗██╗███████╗████████╗    ██╗      █████╗ ██████╗                      
                                                   ╚══██╔══╝██║  ██║██║██╔════╝╚══██╔══╝    ██║     ██╔══██╗██╔══██╗                     
                                                      ██║   ███████║██║█████╗     ██║       ██║     ███████║██████╔╝                     
                                 ╔═══════════════════ ██║   ██╔══██║██║██╔══╝     ██║       ██║     ██╔══██║██╔═══╝═══════════════════╗  
                                 ║                    ██║   ██║  ██║██║███████╗   ██║       ███████╗██║  ██║██║                       ║  
                                 ║                    ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝   ╚═╝       ╚══════╝╚═╝  ╚═╝╚═╝                       ║  
                                 ║                                                                     ██╗                            ║  
                                 ║                                                                     ╚═╝                            ║  
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
	//Vẽ icon
	void iconne(int x, int y);
	iconne(37, 18);
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
	cout << u8"TRẠNG THÁI ÂM NHẠC";
	TextColor(240 | 4);
	gotoXY(90, 28 - 18 + 7);
	string d1 = (*nenptr == 1) ? u8"BẬT" : u8"TẮT";
	cout << d1;
	//Vị trí sound effect
	gotoXY(25 + 40, 32 - 18 + 7);
	TextColor(240 | 0);
	cout << u8"SFX:  ";
	TextColor(240 | 4);
	gotoXY(90, 32 - 18 + 7);
	string d2 = (*sfxptr == 1) ? u8"BẬT" : u8"TẮT";
	cout << d2;
	//Language
	gotoXY(25 + 40, 36 - 18 + 7);
	TextColor(240 | 0);
	cout << u8"NGÔN NGỮ";
	TextColor(240 | 4);
	gotoXY(90, 36 - 18 + 7);
	string d3 = (*languageptr == 1) ? u8"TIẾNG ANH" : u8"TIẾNG VIỆT";
	cout << d3;

	// nút back
	gotoXY(25 + 40, 40 - 18 + 7);
	TextColor(240 | 0);
	cout << u8"TRỞ VỀ";

	while (true) {
		contro = _getch();
		if (contro == 13) {
			if (sfx == 1) {
				PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
			}
			*tam = (*tam % 2 == 1) ? 0 : 1;
			if (tam == &sfx) {
				clearLineV(90, 32 - 18 + 7, 5);
				string c = (*tam == 1) ? u8"BẬT" : u8"TẮT";
				gotoXY(90, 32 - 18 + 7);
				TextColor(240 | 4);
				cout << c;
			}
			if (tam == &nen) {
				clearLineV(90, 28 - 18 + 7, 5);
				string c = (*tam == 1) ? u8"BẬT" : u8"TẮT";
				gotoXY(90, 28 - 18 + 7);
				TextColor(240 | 4);
				cout << c;
			}
			if (tam == &language) {
				clearLineV(90, 36 - 18 + 7, 10);
				string c = (*tam == 1) ? u8"TIẾNG ANH" : u8"TIẾNG VIỆT";
				gotoXY(90, 36 - 18 + 7);
				TextColor(240 | 4);
				cout << c;
			}
			if (tam == &back) {
				system("cls");
				hienmenuV();  // Quay lại menu chính
				if (exitall) {
					return;
				}
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

//void menu_new_gameV();
//void menu_pveV();
//void menu_pvpV();

void menu_new_gameV() {
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);
	chuvanmoi(53, 2);
	iconnoel(20, 4);
	iconnoel(125, 4);
	snowman(10, 22);
	pine(67, 22);
	santa(100, 32);
	ground(0, 42);
	SetColor(0, 15);
	khungnewgameV(71, 11);
	// Vị trí trung tâm màn hình
	int centerX = 73; // X trung tâm (thay đổi giá trị nếu cần để cân đối màn hình của bạn)
	int centerY = 13; // Y trung tâm

	// Khởi tạo tùy chọn chế độ chơi
	vector<string> options = { u8"HAI NGƯỜI CHƠI", u8"CHƠI VỚI MÁY", u8"TRỞ LẠI"};
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
				system("cls");
				system("color F0");
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				if (options[current_choice] == u8"HAI NGƯỜI CHƠI") {
					// Gọi hàm để xử lý chế độ PvP
					system("cls");
					menu_pvpV();
					return;
				}
				else if (options[current_choice] == u8"CHƠI VỚI MÁY") {
					// Gọi hàm để xử lý chế độ PvE
					system("cls");
					menu_pveV();
					return;
				}
				else if (options[current_choice] == u8"TRỞ LẠI") {
					system("cls");
					hienmenuV();
					return;
				}
			}
			else if (c == 27) { // Phím Esc được nhấn
				system("cls");
				hienmenuV();
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

void menu_pvpV() {
	SetColor(0, 15);
	khungnewgame(38, 23);
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);
	hainguoi(20, 10);
	chill(85, 10);
	// Vị trí trung tâm màn hình
	int centerX = 40; // X trung tâm (thay đổi giá trị nếu cần để cân đối màn hình của bạn)
	int centerY = 25; // Y trung tâm
	vector<int> toado;
	vector<char> xo;
	// Khởi tạo tùy chọn chế độ chơi PvP
	vector<string> options = { u8"BÌNH THƯỜNG", u8"CỜ NHANH", u8"TRỞ LẠI" };
	int num_options = options.size();
	int current_choice = 0;
	//bool keep_running = true;

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
				system("cls");
				system("color F0");
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				if (options[current_choice] == u8"BÌNH THƯỜNG") {
					vector<int> toado;
					vector<char> xo;
					playGame();
					while (true) {
						if (_kbhit()) {
							char c = _getch();
							if (c == 'b' || c == 'B') {
								system("cls");
								menu_pvpV();
								return;
							}
						}
					}
				}
				else if (options[current_choice] == u8"CỜ NHANH") {
					PVPtime();
					while (true) {
						if (_kbhit()) {
							char c = _getch();
							if (c == 'B' || c == 'b') {
								system("cls");
								menu_pvpV();
								return;
							}
						}
					}
				}
				else if (options[current_choice] == u8"TRỞ LẠI") {
					system("cls");
					menu_new_gameV();
					return;
				}
			}
			else if (c == 27) { // Phím Esc được nhấn
				// Thoát khỏi menu và quay lại menu PvP/PvE
				system("cls");
				menu_new_gameV();
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
void menu_pveV() {
	SetColor(0, 15);
	khungnewgame(37, 23);
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);
	choivoimay(33, 10);
	chill(85, 10);
	// Vị trí trung tâm màn hình
	int centerX = 40; // X trung tâm (thay đổi giá trị nếu cần để cân đối màn hình của bạn)
	int centerY = 25; // Y trung tâm

	// Khởi tạo tùy chọn chế độ chơi
	vector<string> options = { u8"DỄ", u8"KHÓ", u8"TRỞ LẠI"};
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
				
				c = _getch();
				if (c == 72) { // Mũi tên lên
					if (sfx == 1) {
						PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
					}
					current_choice = (current_choice - 1 + num_options) % num_options;
				}
				else if (c == 80) { // Mũi tên xuống
					if (sfx == 1) {
						PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
					}
					current_choice = (current_choice + 1) % num_options;
				}
			}
			else if (c == 13) { // Phím Enter được nhấn
				system("cls");
				system("color F0");
				if (sfx == 1) {
					PlaySound(TEXT("move"), NULL, SND_ASYNC | SND_FILENAME);
				}
				if (options[current_choice] == u8"DỄ") {
					system("cls");
					playeasy();

					while (true) {
						// Giữ màn hình EASY cho đến khi người dùng nhấn Esc để thoát
						if (_kbhit()) {
							char c = _getch();
							if (c == 'B' || c == 'b') {
								system("cls");
								menu_pveV();
								return;
							}
						}
					}
				}
				else if (options[current_choice] == u8"KHÓ") {
					system("cls");
					playGamehard();

					while (true) {
						if (_kbhit()) {
							char c = _getch();
							if (c == 'B' || c == 'b') {
								system("cls");
								menu_pveV();
								return;
							}
						}
					}
				}
				else if (options[current_choice] == u8"TRỞ LẠI") {
					system("cls");
					menu_new_gameV();
					return;
				}
			}
			else if (c == 27) { // Phím Esc được nhấn
				system("cls");
				menu_new_gameV();
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

void hienmenuV() {
	if (exitall) {
		return;
	}
	if (nen % 2 == 1) {
		PlaySound(TEXT("backgroundmusic"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	if (language == 1) {
		hienmenu();
		return;
	}
	system("cls");
	resizeConsole(1150, 750);
	system("color f0");
	fixConsoleScroll();
	setConsoleFont(L"Consolas", 16);
	FixConsoleWindow();
	SetConsoleOutputCP(437);
	dohoamenu();
	khungmenu(65, 16);
	Red_Ranger(30, 16);
	Hero(110, 16);
	SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_TEXT);
	int x = 70, y = 18; // Tọa độ menu
	vector<string> labels = { u8"     VÁN MỚI", u8"   TẢI GAME", u8"	 HƯỚNG DẪN CHƠI", u8"  THÔNG TIN", u8"     THIẾT LẬP" };
	int sl = labels.size(); // Số lượng menu
	int xp = x, yp = y;     // Tọa độ hiện tại
	int xcu = xp, ycu = yp; // Tọa độ cũ
	bool kt = true;

	// Hiển thị menu lần đầu
	for (int i = 0; i < sl; ++i) {
		draw_frameV(x, y + i * 2, 20, (i == 0)); // Dòng đầu được chọn
		display_textV(x, y + i * 2, labels[i], (i == 0), 20);
	}

	while (true) {
		if (kt) {
			// Làm nổi bật lựa chọn hiện tại
			draw_frameV(xcu, ycu, 20, false);
			display_textV(xcu, ycu, labels[(ycu - y) / 2], false, 20);

			xcu = xp;
			ycu = yp;

			draw_frameV(xp, yp, 20, true);
			display_textV(xp, yp, labels[(yp - y) / 2], true, 20);
			kt = false;
		}
		if (_kbhit()) {
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
				if (labels[(yp - y) / 2] == u8"     VÁN MỚI") {
					menu_new_gameV();
					hienmenuV();
					if (exitall) {
						return;
					}
				}
				else if (labels[(yp - y) / 2] == u8"   TẢI GAME") {
					load_gameV();
					if (exitall) {
						return;
					}
				}
				else if (labels[(yp - y) / 2] == u8"  THÔNG TIN") {
					about_usV();
					if (exitall) {
						return;
					}
				}
				else if (labels[(yp - y) / 2] == u8"	 HƯỚNG DẪN CHƠI") {
					howtoplayV();
					if (exitall) {
						return;
					}
				}
				else if (labels[(yp - y) / 2] == u8"     THIẾT LẬP") {
					display_settingV();
					if (exitall) {
						return;
					}
				}
				// Quay lại menu
				system("cls");
				system("color f0");
				for (int i = 0; i < sl; ++i) {
					draw_frameV(x, y + i * 2, 20, (i == (yp - y) / 2));
					display_textV(x, y + i * 2, labels[i], (i == (yp - y) / 2), 20);
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


/*


												  ██╗
					██╗                          ██╔╝
				   ██╔╝                          ╚═╝ ███
				   ╚═╝                                 ██
	   ██╗   ██╗ █████╗ ███╗   ██╗    ███╗   ███╗ ██████╗ ██╗
	   ██║   ██║██╔══██╗████╗  ██║    ████╗ ████║██╔═══██╗██║
	   ██║   ██║███████║██╔██╗ ██║    ██╔████╔██║██║   ██║██║
	   ╚██╗ ██╔╝██╔══██║██║╚██╗██║    ██║╚██╔╝██║██║   ██║██║
		╚████╔╝ ██║  ██║██║ ╚████║    ██║ ╚═╝ ██║╚██████╔╝██║
		 ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═══╝    ╚═╝     ╚═╝ ╚═════╝ ╚═╝
















																																			   
																																			   
															 ╔════════════════                                                                 ═══════════════════╗
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
															 ║                                                                                                    ║
															 ║                                                                                                    ║
															 ╚════════════════════════════════════════════════════════════════════════════════════════════════════╝




































						  ██
							██                   ██
						  ██                    █╔╗█
												╚╝╚╝
			  ████████╗ █████╗ ██╗    ██╗     ███████╗███╗   ██╗
			  ╚══██╔══╝██╔══██╗██║    ██║     ██╔════╝████╗  ██║
				 ██║   ███████║██║    ██║     █████╗  ██╔██╗ ██║
				 ██║   ██╔══██║██║    ██║     ██╔══╝  ██║╚██╗██║
				 ██║   ██║  ██║██║    ███████╗███████╗██║ ╚████║
				 ╚═╝   ╚═╝  ╚═╝╚═╝    ╚══════╝╚══════╝╚═╝  ╚═══╝











								  ██╗
								 ██╔╝
							  ██ ╚═╝                       ██
							 █╔╗█                         █╔╗█
							 ╚╝╚╝                         ╚╝╚╝
	   ████████╗██╗  ██╗██╗███████╗████████╗    ██╗      █████╗ ██████╗
	   ╚══██╔══╝██║  ██║██║██╔════╝╚══██╔══╝    ██║     ██╔══██╗██╔══██╗
		  ██║   ███████║██║█████╗     ██║       ██║     ███████║██████╔╝
		  ██║   ██╔══██║██║██╔══╝     ██║       ██║     ██╔══██║██╔═══╝
		  ██║   ██║  ██║██║███████╗   ██║       ███████╗██║  ██║██║
		  ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝   ╚═╝       ╚══════╝╚═╝  ╚═╝╚═╝
														   ██╗
															╚╝

















					 ██                                    ██╗
					  ██                                  ██╔╝
														  ╚═╝
  ████████╗██╗  ██╗ █████╗ ███╗   ██╗██╗  ██╗    ████████╗██╗ ██████╗██╗  ██╗
  ╚══██╔══╝██║  ██║██╔══██╗████╗  ██║██║  ██║    ╚══██╔══╝██║██╔════╝██║  ██║
	 ██║   ███████║███████║██╔██╗ ██║███████║       ██║   ██║██║     ███████║
	 ██║   ██╔══██║██╔══██║██║╚██╗██║██╔══██║       ██║   ██║██║     ██╔══██║
	 ██║   ██║  ██║██║  ██║██║ ╚████║██║  ██║       ██║   ██║╚██████╗██║  ██║
	 ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝       ╚═╝   ╚═╝ ╚═════╝╚═╝  ╚═╝
















																		  */