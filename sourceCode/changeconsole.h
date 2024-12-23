#pragma once
#include "Windows.h"

//void SetWindowSize(SHORT width, SHORT height)
//{
//    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    SMALL_RECT WindowSize;
//    WindowSize.Top = 0;
//    WindowSize.Left = 0;
//    WindowSize.Right = width-1;
//    WindowSize.Bottom = height-1;
//
//    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
//}
//


void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

}

void SetConsoleFontSize(int fontWidth, int fontHeight) {
    // Lấy handle của console output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Cấu trúc để lưu thông tin về font
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX); // Kích thước cấu trúc

    // Lấy thông tin hiện tại của font console
    GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

    // Thay đổi chiều rộng và chiều cao của font
    cfi.dwFontSize.X = fontWidth;  // Chiều rộng font
    cfi.dwFontSize.Y = fontHeight; // Chiều cao font

    // Áp dụng cài đặt mới
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void setConsoleFont(const wchar_t* fontName, int fontSize) {
    // Lấy handle của console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        cout << "Failed to get console handle." << endl;
        return;
    }

    // Cấu trúc CONSOLE_FONT_INFOEX để thay đổi font chữ
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    if (!GetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
        cout << "Failed to get current console font." << endl;
        return;
    }

    // Đặt font chữ
    wcscpy_s(cfi.FaceName, fontName);
    cfi.dwFontSize.X = fontSize; // Chiều rộng của ký tự
    cfi.dwFontSize.Y = fontSize; // Chiều cao của ký tự

    // Áp dụng font chữ mới
    if (!SetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
        cout << "Failed to set new console font." << endl;
    }
}

void fixConsoleScroll() {
    // Lấy handle của console hiện tại
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Lấy kích thước hiện tại của console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Điều chỉnh kích thước buffer bằng với kích thước cửa sổ
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = csbi.srWindow.Right - csbi.srWindow.Left;
    rect.Bottom = csbi.srWindow.Bottom - csbi.srWindow.Top;

    SetConsoleWindowInfo(hConsole, TRUE, &rect);
    SetConsoleScreenBufferSize(hConsole, { rect.Right + 1, rect.Bottom + 1 });
}