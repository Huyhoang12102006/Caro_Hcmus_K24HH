#pragma once
#include <Windows.h>
#include "move.h"
#include <iostream>
using namespace std;


void vebutton(int x, int y, int m, bool visible = true)
{
    if (visible) {
        //Hàng 1
        TextColor(240 | 5);
        for (int i = 0; i < 22; i++) {
            gotoXY(x + i, y + 1);
            cout << char(220);
        }
        //Hàng 2
        gotoXY(x, y + 2);
        cout << char(219);
        gotoXY(x + 21, y + 2);
        cout << char(219);
        //Hàng 3
        gotoXY(x, y + 3);
        cout << char(223);
        for (int i = 0; i < 3; i++) {
            gotoXY(x + 1 + i, y + 3);
            cout << char(219);
        }
        for (int i = 0; i < 3; i++) {
            gotoXY(x + 4 + i, y + 3);
            cout << char(223);
        }
        for (int i = 0; i < 2; i++) {
            gotoXY(x + 7 + i, y + 3);
            cout << char(219);
        }
        for (int i = 0; i < 4; i++) {
            gotoXY(x + 9 + i, y + 3);
            cout << char(223);
        }
        for (int i = 0; i < 2; i++) {
            gotoXY(x + 13 + i, y + 3);
            cout << char(219);
        }
        for (int i = 0; i < 3; i++) {
            gotoXY(x + 15 + i, y + 3);
            cout << char(223);
        }
        for (int i = 0; i < 3; i++) {
            gotoXY(x + 18 + i, y + 3);
            cout << char(219);
        }
        gotoXY(x + 21, y + 3);
        cout << char(223);
        //Hàng 4
        gotoXY(x + 2, y + 4);
        cout << char(219);
        gotoXY(x + 6, y + 4);
        cout << char(219);
        gotoXY(x + 9, y + 4);
        cout << char(219);
        gotoXY(x + 12, y + 4);
        cout << char(219);
        gotoXY(x + 15, y + 4);
        cout << char(219);
        gotoXY(x + 19, y + 4);
        cout << char(219);
        //Hàng 5
        gotoXY(x + 2, y + 5);
        cout << char(219);
        gotoXY(x + 6, y + 5);
        cout << char(219);
        gotoXY(x + 9, y + 5);
        cout << char(219);
        gotoXY(x + 12, y + 5);
        cout << char(219);
        gotoXY(x + 15, y + 5);
        cout << char(219);
        gotoXY(x + 19, y + 5);
        cout << char(219);
        //Hàng 6
        gotoXY(x + 2, y + 6);
        cout << char(219);
        gotoXY(x + 5, y + 6);
        cout << char(219);
        for (int i = 0; i < 10; i++) {
            gotoXY(x + 6 + i, y + 6);
            cout << char(223);
        }
        gotoXY(x + 16, y + 6);
        cout << char(219);
        gotoXY(x + 19, y + 6);
        cout << char(219);
        //Hàng 7
        gotoXY(x + 2, y + 7);
        cout << char(219);
        for (int i = 0; i < 2; i++) {
            gotoXY(x + 3 + i, y + 7);
            cout << char(220);
        }
        gotoXY(x + 5, y + 7);
        cout << char(219);
        gotoXY(x + 8, y + 7);
        cout << char(220);
        gotoXY(x + 13, y + 7);
        cout << char(220);
        gotoXY(x + 16, y + 7);
        cout << char(219);
        for (int i = 0; i < 2; i++) {
            gotoXY(x + 17 + i, y + 7);
            cout << char(220);
        }
        gotoXY(x + 19, y + 7);
        cout << char(219);
        //Hàng 8
        gotoXY(x + 5, y + 8);
        cout << char(219);
        for (int i = 0; i < 10; i++) {
            gotoXY(x + 6 + i, y + 8);
            cout << char(220);
        }
        gotoXY(x + 16, y + 8);
        cout << char(219);
        // hàng 9
        gotoXY(x + 7, y + 9);
        cout << char(219) << char(219);
        gotoXY(x + 13, y + 9);
        cout << char(219) << char(219);
    }
    else {
        // Xóa button bằng cách vẽ khoảng trắng đè lên
        for (int j = 1; j <= 9; j++) {
            for (int i = 0; i < 22; i++) {
                gotoXY(x + i, y + j);
                cout << ' '; // Vẽ khoảng trắng
            }
        }
    }
    TextColor(240); // Đặt lại màu mặc định
}


void vebutton_2(int x, int y, int m, bool visible = true)
{
    if (visible) {
        //Hàng 1
        TextColor(240 | 5);
        for (int i = 0; i < 22; i++) {
            gotoXY(x + i, y + 1);
            cout << char(220);
        }
        //Hàng 2
        gotoXY(x, y + 2);
        cout << char(219);
        gotoXY(x + 21, y + 2);
        cout << char(219);
        //Hàng 3
        gotoXY(x, y + 3);
        cout << char(223);
        for (int i = 0; i < 3; i++) {
            gotoXY(x + 1 + i, y + 3);
            cout << char(219);
        }
        for (int i = 0; i < 3; i++) {
            gotoXY(x + 4 + i, y + 3);
            cout << char(223);
        }
        for (int i = 0; i < 2; i++) {
            gotoXY(x + 7 + i, y + 3);
            cout << char(219);
        }
        for (int i = 0; i < 4; i++) {
            gotoXY(x + 9 + i, y + 3);
            cout << char(223);
        }
        for (int i = 0; i < 2; i++) {
            gotoXY(x + 13 + i, y + 3);
            cout << char(219);
        }
        for (int i = 0; i < 3; i++) {
            gotoXY(x + 15 + i, y + 3);
            cout << char(223);
        }
        for (int i = 0; i < 3; i++) {
            gotoXY(x + 18 + i, y + 3);
            cout << char(219);
        }
        gotoXY(x + 21, y + 3);
        cout << char(223);
        //Hàng 4
        gotoXY(x + 2, y + 4);
        cout << char(219);
        gotoXY(x + 6, y + 4);
        cout << char(219);
        gotoXY(x + 9, y + 4);
        cout << char(219);
        gotoXY(x + 12, y + 4);
        cout << char(219);
        gotoXY(x + 15, y + 4);
        cout << char(219);
        gotoXY(x + 19, y + 4);
        cout << char(219);
        //Hàng 5
        gotoXY(x + 2, y + 5);
        cout << char(219);
        gotoXY(x + 6, y + 5);
        cout << char(219);
        gotoXY(x + 9, y + 5);
        cout << char(219);
        gotoXY(x + 12, y + 5);
        cout << char(219);
        gotoXY(x + 15, y + 5);
        cout << char(219);
        gotoXY(x + 19, y + 5);
        cout << char(219);
        //Hàng 6
        gotoXY(x + 2, y + 6);
        cout << char(219);
        gotoXY(x + 5, y + 6);
        cout << char(219);
        for (int i = 0; i < 10; i++) {
            gotoXY(x + 6 + i, y + 6);
            cout << char(223);
        }
        gotoXY(x + 16, y + 6);
        cout << char(219);
        gotoXY(x + 19, y + 6);
        cout << char(219);
        //Hàng 7
        gotoXY(x + 2, y + 7);
        cout << char(219);
        for (int i = 0; i < 2; i++) {
            gotoXY(x + 3 + i, y + 7);
            cout << char(220);
        }
        gotoXY(x + 5, y + 7);
        cout << char(219);
        for (int i = 0; i < 10; i++) {
            cout << char(220);
        }
        gotoXY(x + 16, y + 7);
        cout << char(219);
        for (int i = 0; i < 2; i++) {
            gotoXY(x + 17 + i, y + 7);
            cout << char(220);
        }
        gotoXY(x + 19, y + 7);
        cout << char(219);
        for (int i = 0; i < 5; i++) {
            cout << char(220);
        }

        gotoXY(x - 3, y + 7);
        for (int i = 0; i < 5; i++) {
            cout << char(220);
        }

        //Hàng 8
        gotoXY(x - 3, y + 8);
        cout << char(219);
        gotoXY(x + 24, y + 8);
        cout << char(219);

        //Hàng 9
        gotoXY(x - 3, y + 9);
        for (int i = 0; i < 28; i++) {
            cout << char(223);
        }
    }
    else {
        // Xóa button bằng cách vẽ khoảng trắng đè lên
        for (int j = 1; j <= 9; j++) {
            for (int i = 0; i < 22; i++) {
                gotoXY(x + i, y + j);
                cout << ' '; // Vẽ khoảng trắng
            }
        }
    }
    TextColor(240); // Đặt lại màu mặc định
}