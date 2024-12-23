#pragma once
#include <iostream>
#include"move.h"
using namespace std;

#define BOARD_SIZE 16
const float toadobang = 46;

// Mảng lưu trạng thái của bảng cờ
char board[BOARD_SIZE][BOARD_SIZE];
void matrixboard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Mã ASCII của các ký tự:
int ngang = 205;     // Ký tự '─'
int doc = 186;       // Ký tự '│'

int top_left_corner = 201;     // Ký tự '┌'
int top_right_corner = 187;    // Ký tự '┐'
int bottom_left_corner = 200;  // Ký tự '└'
int bottom_right_corner = 188; // Ký tự '┘'
int cross = 206;               // Ký tự '┼'
int left_cross = 204;          // Ký tự '├'
int right_cross = 185;         // Ký tự '┤'
int top_cross = 203;           // Ký tự '┬'
int bottom_cross = 202;        // Ký tự '┴'

// Hàm vẽ bảng cờ caro
void drawBoard() {
    SetConsoleOutputCP(437); // Đặt mã hóa đầu ra UTF-8
    SetConsoleCP(437);
    TextColor(240 | 0);
    int u = 1;
    // Vẽ cạnh trên
    gotoXY(toadobang, u);
    cout << char(top_left_corner);
    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        cout << char(ngang) << char(ngang) << char(ngang);
        cout << char(top_cross); // Ký tự nối trên
    }
    cout << char(ngang) << char(ngang) << char(ngang) << char(top_right_corner) << endl;
    ++u;
    // Vẽ các dòng giữa

    for (int row = 0; row < BOARD_SIZE - 1; row++) {
        gotoXY(toadobang, u);
        // Vẽ dòng nội dung
        for (int col = 0; col < BOARD_SIZE; col++) {
            cout << char(doc); // Ký tự dọc
            cout << "   "; // Khoảng trống giữa các ô
        }
        cout << char(doc) << endl;
        ++u;
        // Vẽ dòng chia bảng
        gotoXY(toadobang, u);
        cout << char(left_cross);
        for (int i = 0; i < BOARD_SIZE - 1; i++) {
            cout << char(ngang) << char(ngang) << char(ngang);
            cout << char(cross); // Ký tự nối giữa
        }
        cout << char(ngang) << char(ngang) << char(ngang) << char(right_cross) << endl;
        ++u;
    }

    // Vẽ dòng cuối cùng
    gotoXY(toadobang, u);
    for (int col = 0; col < BOARD_SIZE; col++) {
        cout << char(doc); // Ký tự dọc
        cout << "   "; // Khoảng trống giữa các ô
    }
    cout << char(doc) << endl;
    ++u;
    // Vẽ cạnh dưới
    gotoXY(toadobang, u);
    cout << char(bottom_left_corner);
    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        cout << char(ngang) << char(ngang) << char(ngang);
        cout << char(bottom_cross); // Ký tự nối dưới
    }
    cout << char(ngang) << char(ngang) << char(ngang) << char(bottom_right_corner) << endl;
}

// Hàm kiểm tra theo một hướng cụ thể
bool checkDirection(int row, int col, int dRow, int dCol) {
    char player = board[row][col];
    int count = 0;

    // Kiểm tra 4 ô trước và sau vị trí hiện tại
    for (int i = -4; i <= 4; i++) {
        int r = row + i * dRow;
        int c = col + i * dCol;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == player) {
            count++;
            if (count == 5) return true; // Nếu có 5 ô liên tiếp
        }
        else {
            count = 0; // Đặt lại đếm nếu gặp ô không khớp
        }
    }
    return false;
}

//Hàm kiểm tra chiến thắng
bool checkWinngang(int row, int col) {
    return checkDirection(row, col, 0, 1); // Ngang
}
bool checkWindoc(int row, int col) {
    return  checkDirection(row, col, 1, 0);  // Dọc
}
bool checkWinchinh(int row, int col) {
    return checkDirection(row, col, 1, 1);  // Chéo chính
}
bool checkWinphu(int row, int col) {
    return checkDirection(row, col, 1, -1); // Chéo phụ
}


//void highlightWinningCells(int row, int col, char currentPlayer, int dRow, int dCol) {
//    int r = row, c = col;
//    // Highlight ô trung tâm
//    gotoXY(48 + c * 4, 2 + r * 2);
//    TextColor(10 | 15);
//    cout << currentPlayer;
//
//    // Highlight 4 ô phía trước
//    for (int i = 1; i <= 4; i++) {
//        r += dRow;
//        c += dCol;
//        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == currentPlayer) {
//            gotoXY(48 + c * 4, 2 + r * 2);
//            TextColor(10 | 15);
//            cout << currentPlayer;
//        }
//        else {
//            break;
//        }
//    }
//    // Reset lại r, c và highlight 4 ô phía sau
//    r = row;
//    c = col;
//    for (int i = 1; i <= 4; i++) {
//        r -= dRow;
//        c -= dCol;
//        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == currentPlayer) {
//            gotoXY(48 + c * 4, 2+ r * 2);
//            TextColor(10 | 15);
//            cout << currentPlayer;
//        }
//        else {
//            break;
//        }
//    }
//}
void highlightWinningCells(int row, int col, char currentPlayer, int dRow, int dCol) {
    int r = row, c = col;

    // Màu sắc dựa trên người thắng
    int color;
    if (currentPlayer == 'X') {
        color = (4 << 4) | 7; // Nền đỏ, chữ trắng
    }
    else if (currentPlayer == 'O') {
        color = (1 << 4) | 7; // Nền xanh nước biển, chữ trắng
    }
    else {
        return; // Nếu không phải X hoặc O, không làm gì
    }

    // Highlight ô trung tâm và 2 ô pixel bên cạnh
    gotoXY(48 + c * 4, 2 + r * 2);
    TextColor(color);
    cout << currentPlayer;

    // Highlight nền 2 ô pixel bên cạnh
    for (int i = -1; i <= 1; i += 2) { // -1 và +1 cho 2 bên
        gotoXY(48 + c * 4 + i, 2 + r * 2); // Dịch ngang
        TextColor(color);
        cout << " "; // In khoảng trống để đổi màu nền
    }

    // Highlight 4 ô phía trước
    for (int i = 1; i <= 4; i++) {
        r += dRow;
        c += dCol;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == currentPlayer) {
            gotoXY(48 + c * 4, 2 + r * 2);
            TextColor(color);
            cout << currentPlayer;

            // Highlight nền 2 ô pixel bên cạnh
            for (int j = -1; j <= 1; j += 2) {
                gotoXY(48 + c * 4 + j, 2 + r * 2);
                TextColor(color);
                cout << " ";
            }
        }
        else {
            break;
        }
    }

    // Reset lại r, c và highlight 4 ô phía sau
    r = row;
    c = col;
    for (int i = 1; i <= 4; i++) {
        r -= dRow;
        c -= dCol;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == currentPlayer) {
            gotoXY(48 + c * 4, 2 + r * 2);
            TextColor(color);
            cout << currentPlayer;

            // Highlight nền 2 ô pixel bên cạnh
            for (int j = -1; j <= 1; j += 2) {
                gotoXY(48 + c * 4 + j, 2 + r * 2);
                TextColor(color);
                cout << " ";
            }
        }
        else {
            break;
        }
    }
}

