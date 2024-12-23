#pragma once
#include <Windows.h>
#include<iostream>
using namespace std;
// các biến toàn cục
int nen = 1, sfx = 1, language=1;
int* tam = &language;

// xử lý hiển thị khi đã cài đặt trước đó ở "setting" 
int* nenptr = &nen;
int* sfxptr = &sfx;
int* languageptr = &language;
// biến back để các con trỏ trỏ tới và quay về
int back;
bool backngonngu = false;
bool exitall = false;
// biến toàn cục chuỗi thắng 
int achievement = 0;
//xử lý bug hiện lại menu
int gia = 0;


void gotoXY(int x, int y) {
    COORD coord; // Cấu trúc tọa độ
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}
// Hàm thay đổi màu nền tại vị trí hiện tại
static void ColorPix(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Lấy thông tin của console hiện tại
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    // Lấy thông tin về thuộc tính màu sắc
    WORD currentAttributes = consoleInfo.wAttributes;

    // Kết hợp màu nền mới với màu chữ hiện tại
    WORD newColor = (currentAttributes & 0x0F) | (color << 4); // shift màu nền vào vị trí cần thiết
    SetConsoleTextAttribute(hConsole, newColor);
    cout << " ";
}
//hàm xóa hình vẻ or nội dung từ (x1,y1) đến (x2,y2)

void clearRegion(int x1, int y1, int x2, int y2) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    DWORD charsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // Lấy thông tin buffer hiện tại
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    for (int y = y1; y <= y2; ++y) {
        coord.X = x1;
        coord.Y = y;
        // Ghi đè khoảng trống lên dòng
        FillConsoleOutputCharacter(hConsole, ' ', x2 - x1 + 1, coord, &charsWritten);
    }
}