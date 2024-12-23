#pragma once
#include<iostream>
#include<Windows.h>
#include<iostream>
#include"changeconsole.h"
#include"move.h"
using namespace std;

void SetTextColor(int textColor) {
    cout << "\033[38;5;" << textColor << "m";  // Chỉ thay đổi màu chữ
}
void SetColor(int textColor, int bgColor) {
    cout << "\033[38;5;" << textColor << "m"  // Màu chữ
        << "\033[48;5;" << bgColor << "m";   // Màu nền
}
//Pixel color
void mau(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD currentAttributes = consoleInfo.wAttributes;
    WORD newColor = (currentAttributes & 0x0F) | (color << 4);
    SetConsoleTextAttribute(hConsole, newColor);
    cout << " ";
}
// Hàm đọc dữ liệu từ file vào mảng hai chiều
void docdata(ifstream& in, int a[][200], int gh_n, int gh_m) {
    for (int i = 0; i < gh_n; i++) {
        for (int j = 0; j < gh_m; j++) {
            in >> a[i][j];
        }
    }
}
// Hàm thiết lập màu sắc chữ và nền
void setColor(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorCode = textColor + (backgroundColor * 16);
    SetConsoleTextAttribute(hConsole, colorCode);
}
void Hero(int x, int y) {
    // system("cls");
     //system("Color F0");

    ifstream in;
    in.open("Hero.txt", ios::in);
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
void Red_Ranger(int x, int y) {
    // system("cls");
     //system("Color F0");

    ifstream in;
    in.open("Red_Ranger.txt", ios::in);
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
void dohoamenu() {
    //0 -> 76 = 78 -> 154 => 77 mid
    //0 -> 43
    system("color f0");
    char soc = 177;
    char ngang = 205;
    char doc = 186;
    char td = 200;
    char tt = 201;
    char pt = 187;
    char pd = 188;

    //Khung1
    gotoXY(38, 0);
    int m = 0;
    while (m < 12) {
        for (int i = 0; i < 80; i++) {
            mau(7);
        }
        m++;
        gotoXY(38, m);
    }

    ////Chu C:
    SetTextColor(124);
    gotoXY(80 + 4 - 26, 5 - 3); cout << pt;
    gotoXY(71 + 4 - 26, 4 - 3);
    for (int i = 0; i < 8; i++) {
        cout << ngang;
    }
    gotoXY(79 + 4 - 26, 4 - 3); cout << pt;
    gotoXY(71 + 4 - 26, 4 - 3); cout << tt;
    gotoXY(71 + 4 - 26, 5 - 3); cout << pd;
    gotoXY(70 + 4 - 26, 5 - 3); cout << ngang;
    gotoXY(69 + 4 - 26, 5 - 3); cout << tt;
    gotoXY(69 + 4 - 26, 6 - 3); cout << pd;
    gotoXY(68 + 4 - 26, 6 - 3); cout << tt;
    gotoXY(68 + 4 - 26, 7 - 3); int z = 7 - 3;
    for (int i = 0; i < 4; i++) {
        for (int i = 0; i < 1; i++) {
            cout << doc;
        }
        gotoXY(68 + 4 - 26, z);
        z++;
    }
    gotoXY(69 + 4 - 26, 11 - 3); cout << td;
    gotoXY(68 + 4 - 26, 10 - 3); cout << td;
    gotoXY(73 + 4 - 26, 11 - 3);
    for (int i = 0; i < 5; i++) { cout << ngang; }
    cout << pd;
    gotoXY(78 + 4 - 26, 10 - 3); cout << tt; cout << ngang; cout << pt;
    ///////////////////////////////////
    SetTextColor(55);
    gotoXY(72 + 1 + 4 - 26, 5 + 1 - 3);
    for (int i = 0; i < 8; i++) cout << soc;
    gotoXY(70 + 1 + 4 - 26, 6 + 1 - 3);
    int u = 7 + 1 - 3;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            cout << soc;
        }
        cout << endl;
        gotoXY(70 + 1 + 4 - 26, u);
        u++;
    }
    gotoXY(69 + 1 + 4 - 26, 1 + 7 - 3);
    int w = 7 + 1 - 3;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 1; j++) {
            cout << soc;
        }
        cout << endl;
        gotoXY(69 + 1 + 4 - 26, w);
        w++;
    }
    gotoXY(72 + 1 + 4 - 26, 12 + 1 - 3);
    for (int i = 0; i < 8; i++) cout << soc;

    gotoXY(79 + 1 + 4 - 26, 6 + 1 - 3);
    for (int i = 0; i < 2; i++) cout << soc;
    gotoXY(79 + 1 + 4 - 26, 11 + 1 - 3);
    for (int i = 0; i < 2; i++) cout << soc;
    ///////////////////////////////////
    gotoXY(72 + 4 - 26, 5 - 3);
    for (int i = 0; i < 8; i++) mau(4);
    gotoXY(70 + 4 - 26, 6 - 3);
    int x = 7 - 3;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            mau(4);
        }
        cout << endl;
        gotoXY(70 + 4 - 26, x);
        x++;
    }
    gotoXY(69 + 4 - 26, 7 - 3);
    int y = 7 - 3;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 1; j++) {
            mau(4);
        }
        cout << endl;
        gotoXY(69 + 4 - 26, y);
        y++;
    }
    gotoXY(72 + 4 - 26, 12 - 3);
    for (int i = 0; i < 8; i++) mau(4);
    gotoXY(79 + 4 - 26, 6 - 3);
    for (int i = 0; i < 2; i++) mau(4);
    gotoXY(79 + 4 - 26, 11 - 3);
    for (int i = 0; i < 2; i++) mau(4);
    mau(7); //reset color

    //Chu A: 
    SetTextColor(124);
    gotoXY(97 + 4 - 26, 5 - 3); cout << pt;
    gotoXY(89 + 4 - 26, 4 - 3); for (int i = 0; i < 7; i++) { cout << ngang; } cout << pt;
    gotoXY(88 + 4 - 26, 4 - 3); cout << tt;
    gotoXY(88 + 4 - 26, 5 - 3); cout << pd;
    gotoXY(87 + 4 - 26, 5 - 3); cout << tt;
    gotoXY(87 + 4 - 26, 6 - 3); cout << doc;
    gotoXY(87 + 4 - 26, 7 - 3); cout << doc;
    gotoXY(87 + 4 - 26, 8 - 3); cout << pd;
    gotoXY(86 + 4 - 26, 8 - 3); cout << tt;
    gotoXY(86 + 4 - 26, 9 - 3); cout << doc; gotoXY(86 + 4 - 26, 10 - 3); cout << doc;
    gotoXY(86 + 4 - 26, 11 - 3); cout << doc; gotoXY(86 + 4 - 26, 12 - 3); cout << td;
    //////////////////////////////////////////
    SetTextColor(55);
    gotoXY(90 + 4 - 26, 6 - 3); for (int i = 0; i < 6; i++) cout << soc;
    gotoXY(90 + 4 - 26, 7 - 3); cout << soc;
    gotoXY(98 + 4 - 26, 7 - 3); cout << soc;
    gotoXY(98 + 4 - 26, 8 - 3); cout << soc;
    gotoXY(99 + 4 - 26, 10 - 3); cout << soc;
    gotoXY(99 + 4 - 26, 11 - 3); cout << soc;
    gotoXY(99 + 4 - 26, 12 - 3); cout << soc;
    gotoXY(99 + 4 - 26, 13 - 3); cout << soc;
    gotoXY(97 + 4 - 26, 13 - 3); cout << soc;
    gotoXY(98 + 4 - 26, 13 - 3); cout << soc;
    gotoXY(90 + 4 - 26, 9 - 3); for (int i = 0; i < 6; i++) cout << soc;
    gotoXY(90 + 4 - 26, 10 - 3); cout << soc;
    gotoXY(90 + 4 - 26, 11 - 3); cout << soc;
    gotoXY(90 + 4 - 26, 12 - 3); cout << soc;
    gotoXY(90 + 4 - 26, 13 - 3); cout << soc;
    gotoXY(88 + 4 - 26, 13 - 3); cout << soc;
    gotoXY(89 + 4 - 26, 13 - 3); cout << soc;
    ///////////////////////////////////////////
    gotoXY(89 + 4 - 26, 5 - 3); for (int i = 0; i < 8; i++) mau(4);
    gotoXY(88 + 4 - 26, 6 - 3);
    int p = 7 - 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            mau(4);
        }
        cout << endl;
        gotoXY(88 + 4 - 26, p);
        p++;
    }
    gotoXY(90 + 4 - 26, 8 - 3);
    for (int i = 0; i < 7; i++) {
        mau(4);
    }
    gotoXY(87 + 4 - 26, 9 - 3);
    int q = 9 - 3;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            mau(4);
        }
        cout << endl;
        gotoXY(87 + 4 - 26, q);
        q++;
    }
    gotoXY(96 + 4 - 26, 6 - 3);
    int b = 7 - 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            mau(4);
        }
        cout << endl;
        gotoXY(96 + 4 - 26, b);
        b++;
    }
    gotoXY(96 + 4 - 26, 9 - 3);
    int c = 9 - 3;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            mau(4);
        }
        cout << endl;
        gotoXY(96 + 4 - 26, c);
        c++;
    }
    mau(7); //reset color

    //Chu R:
    SetTextColor(55);
    gotoXY(106 + 4 - 26, 6 - 3); for (int i = 0; i < 8; i++) cout << soc;
    gotoXY(106 + 4 - 26, 7 - 3); int e = 7 - 3;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            cout << soc;
        }
        cout << endl;
        gotoXY(106 + 4 - 26, e);
        e++;
    }
    gotoXY(112 + 1 + 4 - 26, 1 + 6 - 3); cout << soc; cout << soc;
    gotoXY(112 + 1 + 4 - 26, 7 + 1 - 3); cout << soc; cout << soc;
    gotoXY(105 + 1 + 4 - 26, 1 + 8 - 3); for (int i = 0; i < 8; i++) cout << soc;
    gotoXY(110 + 1 + 4 - 26, 9 + 1 - 3); cout << soc; cout << soc;
    gotoXY(111 + 1 + 4 - 26, 1 + 10 - 3); cout << soc; cout << soc;
    gotoXY(111 + 1 + 4 - 26, 1 + 11 - 3); cout << soc; cout << soc;
    gotoXY(111 + 1 + 4 - 26, 12 + 1 - 3); cout << soc; cout << soc; cout << soc;
    ///////////////////////////////////
    SetTextColor(124);
    gotoXY(113 + 4 - 26, 5 - 3); cout << pt;
    gotoXY(112 + 4 - 26, 4 - 3); cout << pt;
    gotoXY(105 + 4 - 26, 4 - 3); for (int i = 0; i < 7; i++) cout << ngang;
    gotoXY(104 + 4 - 26, 4 - 3); cout << tt;
    gotoXY(104 + 4 - 26, 5 - 3); int t = 6 - 3;
    for (int i = 0; i < 7; i++) {
        for (int i = 0; i < 1; i++) {
            cout << doc;
        }
        gotoXY(104 + 4 - 26, t);
        t++;
    }
    gotoXY(104 + 4 - 26, 12 - 3); cout << td;
    /////////////////////////////////////
    gotoXY(105 + 4 - 26, 5 - 3); for (int i = 0; i < 8; i++) mau(4);
    gotoXY(105 + 4 - 26, 6 - 3); int r = 6 - 3;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            mau(4);
        }
        cout << endl;
        gotoXY(105 + 4 - 26, r);
        r++;
    }
    gotoXY(112 + 4 - 26, 6 - 3); mau(4); mau(4);
    gotoXY(112 + 4 - 26, 7 - 3); mau(4); mau(4);
    gotoXY(105 + 4 - 26, 8 - 3); for (int i = 0; i < 8; i++) mau(4);
    gotoXY(110 + 4 - 26, 9 - 3); mau(4); mau(4);
    gotoXY(111 + 4 - 26, 10 - 3); mau(4); mau(4);
    gotoXY(111 + 4 - 26, 11 - 3); mau(4); mau(4);
    gotoXY(111 + 4 - 26, 12 - 3); mau(4); mau(4); mau(4);
    mau(7); //reset color

    //Chu O:
    SetTextColor(124);
    gotoXY(130 + 4 - 26, 5 - 3); cout << ngang; cout << pt;
    gotoXY(129 + 4 - 26, 4 - 3); cout << pt;
    gotoXY(122 + 4 - 26, 4 - 3); for (int i = 0; i < 7; i++) cout << ngang;
    gotoXY(121 + 4 - 26, 4 - 3); cout << tt;
    gotoXY(121 + 4 - 26, 5 - 3); cout << pd; gotoXY(120 + 4 - 26, 5 - 3); cout << ngang;
    gotoXY(119 + 4 - 26, 5 - 3); cout << tt;
    gotoXY(119 + 4 - 26, 6 - 3); int v = 6 - 3;
    for (int i = 0; i < 7; i++) {
        for (int i = 0; i < 1; i++) {
            cout << doc;
        }
        gotoXY(119 + 4 - 26, v);
        v++;
    }
    gotoXY(119 + 4 - 26, 12 - 3); cout << td; cout << ngang; cout << ngang;
    //////////////////////////////////////
    SetTextColor(55);
    gotoXY(122 + 1 + 4 - 26, 1 + 5 - 3); for (int i = 0; i < 8; i++) cout << soc;
    gotoXY(120 + 1 + 4 - 26, 1 + 6 - 3);
    int f = 7 + 1 - 3;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            cout << soc;
        }
        cout << endl;
        gotoXY(120 + 1 + 4 - 26, f);
        f++;
    }
    gotoXY(122 + 1 + 4 - 26, 1 + 12 - 3); for (int i = 0; i < 8; i++) cout << soc;
    gotoXY(129 + 1 + 4 - 26, 1 + 6 - 3);
    int d = 7 + 1 - 3;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            cout << soc;
        }
        cout << endl;
        gotoXY(129 + 1 + 4 - 26, d);
        d++;
    }
    //////////////////////////////////////////
    gotoXY(122 + 4 - 26, 5 - 3); for (int i = 0; i < 8; i++) mau(4);
    gotoXY(120 + 4 - 26, 6 - 3);
    int h = 7 - 3;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            mau(4);
        }

        gotoXY(120 + 4 - 26, h);
        h++;
    }
    gotoXY(122 + 4 - 26, 12 - 3); for (int i = 0; i < 8; i++) mau(4);
    gotoXY(129 + 4 - 26, 6 - 3);
    int k = 7 - 3;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            mau(4);
        }
        cout << endl;
        gotoXY(129 + 4 - 26, k);
        k++;
    }
    SetColor(0, 15); //reset color

    ////Khung2
    //gotoXY(100, 20);
    //int j = 20;
    //while (j < 40 - 4) {
    //    for (int i = 0; i < 50; i++) {
    //        mau(7);
    //    }
    //    gotoXY(100, j);
    //    j++;
    //}
    ////Controller
    //gotoXY(140 - 40, 28 - 4 - 4); mau(0); mau(0); mau(0); mau(0); gotoXY(186 - 40, 28 - 4 - 4); mau(0); mau(0); mau(0); mau(0);
    //gotoXY(140 - 40, 29 - 4 - 4); mau(0); mau(0); mau(0); mau(0); gotoXY(186 - 40, 29 - 4 - 4); mau(0); mau(0); mau(0); mau(0);
    //gotoXY(144 - 40, 27 - 4 - 4); for (int i = 0; i < 42; i++) mau(0);
    //gotoXY(144 - 40, 26 - 4 - 4); for (int i = 0; i < 42; i++) mau(0);
    //gotoXY(140 - 40, 37 - 4 - 4); mau(0); mau(0); mau(0); mau(0); gotoXY(186 - 40, 37 - 4 - 4); mau(0); mau(0); mau(0); mau(0);
    //gotoXY(140 - 40, 38 - 4 - 4); mau(0); mau(0); mau(0); mau(0); gotoXY(186 - 40, 38 - 4 - 4); mau(0); mau(0); mau(0); mau(0);
    //gotoXY(154 - 40, 37 - 4 - 4); for (int i = 0; i < 22; i++) mau(0);
    //gotoXY(154 - 40, 38 - 4 - 4); for (int i = 0; i < 22; i++) mau(0);
    //gotoXY(144 - 40, 39 - 4 - 4); for (int i = 0; i < 10; i++) mau(0); gotoXY(144 - 40, 40 - 4 - 4); for (int i = 0; i < 10; i++) mau(0);
    //gotoXY(176 - 40, 39 - 4 - 4); for (int i = 0; i < 10; i++) mau(0); gotoXY(176 - 40, 40 - 4 - 4); for (int i = 0; i < 10; i++) mau(0);

    //gotoXY(136 - 40, 30 - 4 - 4); int s = 30 - 4 - 4;
    //for (int i = 0; i < 8; i++) {
    //    for (int i = 0; i < 4; i++) {
    //        mau(0);
    //    }
    //    gotoXY(136 - 40, s);
    //    s++;
    //}
    ////+ black
    //gotoXY(150 - 40, 30 - 4 - 4); mau(0); mau(0); mau(0); mau(0); gotoXY(150 - 40, 31 - 4 - 4); mau(0); mau(0); mau(0); mau(0);
    //gotoXY(146 - 40, 32 - 4 - 4); for (int i = 0; i < 12; i++) mau(0); gotoXY(146 - 40, 33 - 4 - 4); for (int i = 0; i < 12; i++) mau(0);
    //gotoXY(150 - 40, 34 - 4 - 4); mau(0); mau(0); mau(0); mau(0); gotoXY(150 - 40, 35 - 4 - 4); mau(0); mau(0); mau(0); mau(0);

    //gotoXY(160 - 40, 29 - 4 - 4); mau(0); mau(0);
    //gotoXY(168 - 40, 29 - 4 - 4); mau(0); mau(0);

    ////+ color
    //gotoXY(176 - 40, 30 - 4 - 4); mau(1); mau(1); mau(1); mau(1); gotoXY(176, 31 - 4); mau(1); mau(1); mau(1); mau(1);
    //gotoXY(172 - 40, 32 - 4 - 4); mau(2); mau(2); mau(2); mau(2); gotoXY(180, 32 - 4); mau(6); mau(6); mau(6); mau(6);
    //gotoXY(172 - 40, 33 - 4 - 4); mau(2); mau(2); mau(2); mau(2); gotoXY(180, 33 - 4); mau(6); mau(6); mau(6); mau(6);
    //gotoXY(176 - 40, 34 - 4 - 4); mau(4); mau(4); mau(4); mau(4); gotoXY(176, 35 - 4); mau(4); mau(4); mau(4); mau(4);
    //gotoXY(190 - 40, 30 - 4 - 4); int s1 = 30 - 4 - 4;
    //for (int i = 0; i < 8; i++) {
    //    for (int i = 0; i < 4; i++) {
    //        mau(0);
    //    }
    //    gotoXY(190 - 40, s1);
    //    s1++;
    //}
//     //Ve kiem
//     gotoXY(30 - 11 - 6, 17 - 3 - 1); for (int i = 0; i < 4; i++) { mau(0); }
//     gotoXY(64 - 11 - 6, 17 - 3 - 1); for (int i = 0; i < 4; i++) { mau(0); }
//     gotoXY(30 - 11 - 6, 18 - 3 - 1); for (int i = 0; i < 2; i++) { mau(0); }
//     gotoXY(66 - 11 - 6, 18 - 3 - 1); for (int i = 0; i < 2; i++) { mau(0); }

//     gotoXY(32 - 11 - 6, 18 - 3 - 1); for (int i = 0; i < 2; i++) { mau(4); }
//     gotoXY(64 - 11 - 6, 18 - 3 - 1); for (int i = 0; i < 2; i++) { mau(4); }
//     gotoXY(34 - 11 - 6, 18 - 3 - 1); for (int i = 0; i < 2; i++) { mau(0); }
//     gotoXY(62 - 11 - 6, 18 - 3 - 1); for (int i = 0; i < 2; i++) { mau(0); }

//     gotoXY(32 - 11 - 6, 19 - 3 - 1); mau(0); mau(0);
//     gotoXY(34 - 11 - 6, 19 - 3 - 1); mau(12); mau(12); mau(0); mau(0);
//     gotoXY(40 - 11 - 6, 19 - 3 - 1); mau(0); mau(0); mau(0); mau(0);
//     gotoXY(54 - 11 - 6, 19 - 3 - 1); mau(0); mau(0); mau(0); mau(0);
//     gotoXY(60 - 11 - 6, 19 - 3 - 1); mau(0); mau(0); mau(12); mau(12); mau(0); mau(0);

//     gotoXY(34 - 11 - 6, 20 - 3 - 1); mau(0); mau(0); mau(4); mau(4); mau(0); mau(0); mau(7); mau(7); mau(11); mau(11); mau(0); mau(0);
//     gotoXY(52 - 11 - 6, 20 - 3 - 1); mau(0); mau(0); mau(11); mau(11); mau(7); mau(7); mau(0); mau(0); mau(4); mau(4); mau(0); mau(0);

//     gotoXY(36 - 11 - 6, 21 - 3 - 1); mau(0); mau(0); mau(8); mau(8); mau(3); mau(3); mau(0); mau(0);
//     gotoXY(54 - 11 - 6, 21 - 3 - 1); mau(0); mau(0); mau(3); mau(3); mau(8); mau(8); mau(0); mau(0);

//     gotoXY(34 - 11 - 6, 22 - 3 - 1); mau(0); mau(0); mau(8); mau(8); mau(9); mau(9); mau(0); mau(0); mau(7); mau(7); mau(0); mau(0);
//     gotoXY(52 - 11 - 6, 22 - 3 - 1); mau(0); mau(0); mau(7); mau(7); mau(0); mau(0); mau(9); mau(9); mau(8); mau(8); mau(0); mau(0);

//     gotoXY(34 - 11 - 6, 23 - 3 - 1); mau(0); mau(0); mau(11); mau(11); mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(7); mau(7); mau(0); mau(0);
//     gotoXY(50 - 11 - 6, 23 - 3 - 1); mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(7); mau(7); mau(0); mau(0); mau(11); mau(11); mau(0); mau(0);

//     gotoXY(36 - 11 - 6, 24 - 3 - 1); mau(0); mau(0);
//     gotoXY(40 - 11 - 6, 24 - 3 - 1); mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4);
//     mau(7); mau(7); mau(8); mau(8); mau(7); mau(7); mau(0); mau(0); gotoXY(60 - 11 - 6, 24 - 3 - 1); mau(0); mau(0);

//     gotoXY(42 - 11 - 6, 25 - 3 - 1); mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4); mau(14); mau(14); mau(0); mau(0);

//     gotoXY(44 - 11 - 6, 26 - 3 - 1); mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4);

//     gotoXY(42 - 11 - 6, 27 - 3 - 1); mau(0); mau(0); mau(14); mau(14); mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4);

//     gotoXY(40 - 11 - 6, 28 - 3 - 1); mau(0); mau(0); mau(14); mau(14); mau(8); mau(8); mau(14); mau(14); mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4);

//     gotoXY(38 - 11 - 6, 29 - 3 - 1); mau(0); mau(0); mau(14); mau(14); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4); mau(15); mau(15);
//     mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4);

//     gotoXY(36 - 11 - 6, 30 - 3 - 1); mau(0); mau(0); mau(14); mau(14); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4); mau(15); mau(15); mau(15); mau(15); mau(15); mau(15);
//     mau(0); mau(0); mau(7); mau(7); mau(8); mau(8); mau(14); mau(14); mau(4); mau(4);

//     gotoXY(36 - 11 - 6, 31 - 3 - 1); mau(4); mau(4); mau(7); mau(7); mau(14); mau(14); mau(4); mau(4); mau(15); mau(15); mau(15); mau(15); mau(15); mau(15); mau(15); mau(15); mau(15); mau(15);
//     mau(0); mau(0); mau(14); mau(14); mau(7); mau(7);  mau(4); mau(4);

//     gotoXY(36 - 11 - 6, 32 - 3 - 1); mau(4); mau(4); mau(4); mau(4); mau(4); mau(4);
//     gotoXY(56 - 11 - 6, 32 - 3 - 1); mau(0); mau(0); mau(4); mau(4); mau(4); mau(4);

//     //Ve khien
//     gotoXY(40 + 10 - 11 - 6, 34 - 3 - 1); for (int i = 0; i < 8; i++) { mau(0); }
//     mau(14); mau(14); mau(14); mau(14); mau(4); mau(4); mau(14); mau(14); mau(14); mau(14);
//     for (int i = 0; i < 8; i++) { mau(7); }

//     gotoXY(40 + 10 - 11 - 6, 35 - 3 - 1); mau(0); mau(0); mau(0); mau(0);
//     for (int i = 0; i < 6; i++) {
//         mau(8);
//     }
//     for (int i = 0; i < 6; i++) {
//         mau(12);
//     }
//     for (int i = 0; i < 6; i++) {
//         mau(8);
//     }
//     mau(7); mau(7); mau(7); mau(7);

//     gotoXY(40 + 10 - 11 - 6, 36 - 3 - 1); mau(0); mau(0); mau(0); mau(0);
//     for (int i = 0; i < 7; i++) {
//         mau(12);
//     }
//     mau(6); mau(6); mau(6); mau(6);
//     for (int i = 0; i < 7; i++) {
//         mau(12);
//     }
//     mau(7); mau(7); mau(7); mau(7);

//     gotoXY(40 + 10 - 11 - 6, 37 - 3 - 1); mau(0); mau(0);
//     for (int i = 0; i < 9; i++) {
//         mau(12);
//     }
//     mau(6); mau(6);
//     for (int i = 0; i < 11; i++) {
//         mau(12);
//     }
//     mau(7); mau(7);

//     gotoXY(40 + 10 - 11 - 6, 38 - 3 - 1); mau(0); mau(0);
//     for (int i = 0; i < 9; i++) {
//         mau(12);
//     }
//     mau(6); mau(6); mau(6); mau(6);
//     for (int i = 0; i < 9; i++) {
//         mau(12);
//     }
//     mau(7); mau(7);

//     gotoXY(40 + 10 - 11 - 6, 39 - 3 - 1); mau(0); mau(0);
//     for (int i = 0; i < 10; i++) {
//         mau(12);
//     }
//     mau(0); mau(0);
//     for (int i = 0; i < 10; i++) {
//         mau(12);
//     }
//     mau(7); mau(7);

//     gotoXY(40 + 10 - 11 - 6, 40 - 3 - 1); mau(0); mau(0); mau(0); mau(0);
//     for (int i = 0; i < 6; i++) {
//         mau(12);
//     }
//     mau(0); mau(0); mau(0); mau(0); mau(0); mau(0);
//     for (int i = 0; i < 6; i++) {
//         mau(12);
//     }
//     mau(7); mau(7); mau(7); mau(7);

//     gotoXY(42 + 10 - 11 - 6, 41 - 3 - 1); mau(0); mau(0);
//     for (int i = 0; i < 8; i++) {
//         mau(12);
//     }
//     mau(0); mau(0);
//     for (int i = 0; i < 8; i++) {
//         mau(12);
//     }
//     mau(7); mau(7);

//     gotoXY(42 + 10 - 11 - 6, 42 - 3 - 1); mau(0); mau(0);
//     for (int i = 0; i < 8; i++) {
//         mau(12);
//     }
//     mau(3); mau(3);
//     for (int i = 0; i < 8; i++) {
//         mau(12);
//     }
//     mau(7); mau(7);

//     gotoXY(42 + 10 - 11 - 6, 43 - 3 - 1); mau(0); mau(0);
//     for (int i = 0; i < 6; i++) {
//         mau(12);
//     }
//     mau(3); mau(3); mau(3); mau(3); mau(3); mau(3);
//     for (int i = 0; i < 6; i++) {
//         mau(12);
//     }
//     mau(7); mau(7);

//     gotoXY(44 + 10 - 11 - 6, 44 - 3 - 1); mau(0); mau(0);
//     for (int i = 0; i < 6; i++) {
//         mau(12);
//     }
//     mau(3); mau(3);
//     for (int i = 0; i < 6; i++) {
//         mau(12);
//     }
//     mau(8); mau(8);

//     gotoXY(46 + 10 - 11 - 6, 45 - 3 - 1); mau(0); mau(0);
//     for (int i = 0; i < 10; i++) {
//         mau(12);
//     }
//     mau(8); mau(8);

//     gotoXY(48 + 10 - 11 - 6, 46 - 3 - 1);
//     for (int i = 0; i < 10; i++) {
//         mau(0);
//     }
//     gotoXY(107, 9); mau(4);
// }
}