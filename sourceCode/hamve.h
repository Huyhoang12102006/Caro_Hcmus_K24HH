#pragma once
#include "fstream"
#include "Windows.h"
#include <iostream>
#include "move.h"
#include"dohoamenu.h"
#include<string>
#include<sstream>
using namespace std;
// Hàm đọc dữ liệu từ file vào mảng hai chiều
void read(ifstream& in, int a[][200], int gh_n, int gh_m) {
    for (int i = 0; i < gh_n; i++) {
        for (int j = 0; j < gh_m; j++) {
            in >> a[i][j];
        }
    }
}

// Hàm vẽ


void Thinking(int x, int y) {

    ifstream in;
    in.open("Thinking.txt", ios::in);
    int a[200][200];
    int dong_ve; // số dòng
    int cot_ve; // số cột
    in >> dong_ve;
    in >> cot_ve;
    read(in, a, dong_ve, cot_ve);

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

void Wearing_Glass(int x, int y) {


    ifstream in;
    in.open("Wearing_Glass.txt", ios::in);
    int a[200][200];
    int dong_ve; // số dòng
    int cot_ve; // số cột
    in >> dong_ve;
    in >> cot_ve;
    read(in, a, dong_ve, cot_ve);

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

void crying(int x, int y) {


    ifstream in;
    in.open("crying.txt", ios::in);
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


// Hàm tách dòng từ chuỗi nhiều dòng
vector<string> splitLines(const string& text) {
    vector<string> lines;
    istringstream stream(text);
    string line;
    while (getline(stream, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Hàm vẽ WIN
void win(int startX, int startY) {
    // Đảm bảo mã hóa UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Chuỗi ASCII Art WIN
    TextColor(240 | 4);
    const char* winText = u8R"(
██╗    ██╗██╗███╗   ██╗
██║    ██║██║████╗  ██║
██║ █╗ ██║██║██╔██╗ ██║
██║███╗██║██║██║╚██╗██║
╚███╔███╔╝██║██║ ╚████║
 ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝
)";
    // Tách dòng và in
    vector<string> lines = splitLines(winText);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i);
        cout << lines[i];
    }
}

// Hàm vẽ LOSE
void lose(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8);

    // Chuỗi ASCII Art LOSE
    const char* loseText = u8R"(
██╗      ██████╗ ███████╗███████╗
██║     ██╔═══██╗██╔════╝██╔════╝
██║     ██║   ██║███████╗█████╗  
██║     ██║   ██║╚════██║██╔══╝  
███████╗╚██████╔╝███████║███████╗
╚══════╝ ╚═════╝ ╚══════╝╚══════╝
)";
    // Tách dòng và in
    vector<string> lines = splitLines(loseText);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i);
        cout << lines[i];
    }
}
// Hàm vẽ DRAW
void draw(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8);
    const char* drawText = u8R"(
██████╗ ██████╗  █████╗ ██╗    ██╗
██╔══██╗██╔══██╗██╔══██╗██║    ██║
██║  ██║██████╔╝███████║██║ █╗ ██║
██║  ██║██╔══██╗██╔══██║██║███╗██║
██████╔╝██║  ██║██║  ██║╚███╔███╔╝
╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝
)";
    vector<string> lines = splitLines(drawText);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i);
        cout << lines[i];
    }
}
void vePVP(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8);
    const char* pvptext = u8R"(
██████╗ ██╗   ██╗██████╗ 
██╔══██╗██║   ██║██╔══██╗
██████╔╝██║   ██║██████╔╝
██╔═══╝ ╚██╗ ██╔╝██╔═══╝ 
██║      ╚████╔╝ ██║     
╚═╝       ╚═══╝  ╚═╝     
                         
)";
    vector<string> lines = splitLines(pvptext);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i);
        cout << lines[i];
    }
}
void vePVE(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8);
    const char* pvetext = u8R"(
██████╗ ██╗   ██╗███████╗
██╔══██╗██║   ██║██╔════╝
██████╔╝██║   ██║█████╗  
██╔═══╝ ╚██╗ ██╔╝██╔══╝  
██║      ╚████╔╝ ███████╗
╚═╝       ╚═══╝  ╚══════╝                                              
)";
    vector<string> lines = splitLines(pvetext);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i);
        cout << lines[i];
    }
}
void hainguoi(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8);
    const char* haitext = u8R"(
                                     ███             
                                        ███          
                                                     
                                   ███══╗   ██   ██╗ 
                                      ██║     ██╗╚═╝ 
██████╗     ███╗   ██╗ ██████╗ ██╗   ██╔╝██████═╣██╗ 
╚════██╗    ████╗  ██║██╔════╝ ██║   ██║██╔═══██╗██║ 
 █████╔╝    ██╔██╗ ██║██║  ███╗██║   ██║██║   ██║██║ 
██╔═══╝     ██║╚██╗██║██║   ██║██║   ██║██║   ██║██║ 
███████╗    ██║ ╚████║╚██████╔╝╚██████╔╝╚██████╔╝██║ 
╚══════╝    ╚═╝  ╚═══╝ ╚═════╝  ╚═════╝  ╚═════╝ ╚═╝                                             
)";
    vector<string> lines = splitLines(haitext);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i);
        cout << lines[i];
    }
}
void choivoimay(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8);
    const char* maytext = u8R"(
              ██╗           
             ██╔╝           
             ╚═╝            
███╗   ███╗ █████╗ ██╗   ██╗
████╗ ████║██╔══██╗╚██╗ ██╔╝
██╔████╔██║███████║ ╚████╔╝ 
██║╚██╔╝██║██╔══██║  ╚██╔╝  
██║ ╚═╝ ██║██║  ██║   ██║   
╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝                                              
)";
    vector<string> lines = splitLines(maytext);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i);
        cout << lines[i];
    }
}
void chunewgame(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8); // Đặt chế độ UTF-8 để hiển thị đúng ký tự đặc biệt

    // Tên chuỗi được đổi để phản ánh nội dung
    const char* newGameArt = u8R"(
███╗   ██╗███████╗██╗    ██╗     ██████╗  █████╗ ███╗   ███╗███████╗
████╗  ██║██╔════╝██║    ██║    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝
██╔██╗ ██║█████╗  ██║ █╗ ██║    ██║  ███╗███████║██╔████╔██║█████╗  
██║╚██╗██║██╔══╝  ██║███╗██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  
██║ ╚████║███████╗╚███╔███╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗
╚═╝  ╚═══╝╚══════╝ ╚══╝╚══╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝
)";

    // Tách từng dòng từ chuỗi newGameArt
    vector<string> lines = splitLines(newGameArt);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i); // Di chuyển con trỏ tới tọa độ cần in
        cout << lines[i];          // In dòng hiện tại
    }
}
void chuvanmoi(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8); // Đặt chế độ UTF-8 để hiển thị đúng ký tự đặc biệt

    // Tên chuỗi được đổi để phản ánh nội dung
    const char* newGameArtV = u8R"(
                                             ██╗      
                                            ██╔╝      
            ██╗                             ╚═╝       
           ██╔╝                              ███   ██╗
           ╚═╝                                  ██╗╚═╝
██╗   ██╗ █████╗ ███╗   ██╗    ███╗   ███╗ ██████═╣██╗
██║   ██║██╔══██╗████╗  ██║    ████╗ ████║██╔═══██║██║
██║   ██║███████║██╔██╗ ██║    ██╔████╔██║██║   ██║██║
╚██╗ ██╔╝██╔══██║██║╚██╗██║    ██║╚██╔╝██║██║   ██║██║
 ╚████╔╝ ██║  ██║██║ ╚████║    ██║ ╚═╝ ██║╚██████╔╝██║
  ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═══╝    ╚═╝     ╚═╝ ╚═════╝ ╚═╝
)";

    // Tách từng dòng từ chuỗi newGameArt
    vector<string> lines = splitLines(newGameArtV);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i); // Di chuyển con trỏ tới tọa độ cần in
        cout << lines[i];          // In dòng hiện tại
    }
}
void khungmenu(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8); // Đặt chế độ UTF-8 để hiển thị đúng ký tự đặc biệt

    // Tên chuỗi được đổi để phản ánh nội dung
    const char* khungmenutxt = u8R"(
╔════════════════════════════╗
║                            ║
╠════════════════════════════╣
║                            ║
╠════════════════════════════╣
║                            ║
╠════════════════════════════╣
║                            ║
╠════════════════════════════╣
║                            ║
╚════════════════════════════╝)";

    // Tách từng dòng từ chuỗi newGameArt
    vector<string> lines = splitLines(khungmenutxt);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i); // Di chuyển con trỏ tới tọa độ cần in
        cout << lines[i];          // In dòng hiện tại
    }
}
void khungnewgame(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8); // Đặt chế độ UTF-8 để hiển thị đúng ký tự đặc biệt

    // Tên chuỗi được đổi để phản ánh nội dung
    const char* khungnewtxt = u8R"(
╔════════════════╗
║                ║
╠════════════════╣
║                ║
╠════════════════╣
║                ║
╚════════════════╝)";

    // Tách từng dòng từ chuỗi newGameArt
    vector<string> lines = splitLines(khungnewtxt);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i); // Di chuyển con trỏ tới tọa độ cần in
        cout << lines[i];          // In dòng hiện tại
    }
}
void khungnewgameV(int startX, int startY) {
    SetConsoleOutputCP(CP_UTF8); // Đặt chế độ UTF-8 để hiển thị đúng ký tự đặc biệt

    // Tên chuỗi được đổi để phản ánh nội dung
    const char* khungnewVtxt = u8R"(
╔════════════════════╗
║                    ║
╠════════════════════╣
║                    ║
╠════════════════════╣
║                    ║
╚════════════════════╝)";

    // Tách từng dòng từ chuỗi newGameArt
    vector<string> lines = splitLines(khungnewVtxt);
    for (size_t i = 0; i < lines.size(); ++i) {
        gotoXY(startX, startY + i); // Di chuyển con trỏ tới tọa độ cần in
        cout << lines[i];          // In dòng hiện tại
    }
}
void ground(int x, int y) {
    // system("cls");
     //system("Color F0");

    ifstream in;
    in.open("ground.txt", ios::in);
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
void santa(int x, int y) {
    // system("cls");
     //system("Color F0");

    ifstream in;
    in.open("santa.txt", ios::in);
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
void pine(int x, int y) {
    // system("cls");
     //system("Color F0");

    ifstream in;
    in.open("pine.txt", ios::in);
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
void snowman(int x, int y) {
    // system("cls");
     //system("Color F0");

    ifstream in;
    in.open("snowman.txt", ios::in);
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
void iconnoel(int x, int y) {
    // system("cls");
     //system("Color F0");

    ifstream in;
    in.open("iconnoel.txt", ios::in);
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
void chill(int x, int y) {
    // system("cls");
     //system("Color F0");

    ifstream in;
    in.open("chillguy.txt", ios::in);
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