#pragma once
#include"move.h"
void VeChuOWin(int x, int y) {
    //Chu O
 //Hang 1
    for (int i = 0; i < 6; i++) {
        gotoXY(x + 7 + i, y + 1);
        ColorPix(9);
    }
    //Hang 2
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 5 + i, y + 2);
        ColorPix(9);
        gotoXY(x + 13 + i, y + 2);
        ColorPix(9);
    }
    for (int i = 0; i < 6; i++) {
        gotoXY(x + 7 + i, y + 2);
        ColorPix(3);
    }
    //Hang 3
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 3 + i, y + 3);
        ColorPix(9);
        gotoXY(x + 15 + i, y + 3);
        ColorPix(9);
    }
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 5 + i, y + 3);
        ColorPix(3);
        gotoXY(x + 13 + i, y + 3);
        ColorPix(3);
    }
    //Hang 4
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 3 + i, y + 4);
        ColorPix(9);
        gotoXY(x + 15 + i, y + 4);
        ColorPix(9);
    }
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 5 + i, y + 4);
        ColorPix(3);
        gotoXY(x + 13 + i, y + 4);
        ColorPix(3);
    }
    //Hang 5
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 3 + i, y + 5);
        ColorPix(9);
        gotoXY(x + 15 + i, y + 5);
        ColorPix(9);
    }
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 5 + i, y + 5);
        ColorPix(3);
        gotoXY(x + 13 + i, y + 5);
        ColorPix(3);
    }
    //Hang 6
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 5 + i, y + 6);
        ColorPix(9);
        gotoXY(x + 13 + i, y + 6);
        ColorPix(9);
    }
    for (int i = 0; i < 6; i++) {
        gotoXY(x + 7 + i, y + 6);
        ColorPix(3);
    }
    //Hang 7
    for (int i = 0; i < 6; i++) {
        gotoXY(x + 7 + i, y + 7);
        ColorPix(9);
    }

    //Chu W
    for (int i = 0; i < 7; i++) {
        gotoXY(x + i + 20, y + i + 1);
        ColorPix(0);
        gotoXY(x + i + 21, y + i + 1);
        ColorPix(0);
    }
    for (int i = 0; i < 6; i++) {

        gotoXY(x + i + 22, y + i + 1);
        cout << char(176);
    }
    int temp = 7;
    for (int i = 0; i < 5; i++) {
        gotoXY(x + i + 27, y + temp--);
        ColorPix(0);
        gotoXY(x + i + 28, y + temp + 1);
        ColorPix(0);
    }
    for (int i = 0; i < 5; i++) {
        gotoXY(x + i + 32, y + i + 3);
        ColorPix(0);
        gotoXY(x + i + 33, y + i + 3);
        ColorPix(0);
    }
    for (int i = 0; i < 4; i++) {

        gotoXY(x + i + 34, y + i + 3);
        cout << char(176);
    }
    temp = 7;
    for (int i = 0; i < 7; i++) {
        gotoXY(x + i + 37, y + temp--);
        ColorPix(0);
        gotoXY(x + i + 38, y + temp + 1);
        ColorPix(0);
    }
    temp = 7;
    for (int i = 0; i < 7; i++) {
        gotoXY(x + i + 39, y + temp--);
        cout << char(176);
    }

    //Chu I
    for (int i = 0; i < 7; i++) {
        gotoXY(x + 52, y + i + 1);
        ColorPix(0);
        gotoXY(x + 53, y + i + 1);
        ColorPix(0);
    }
    for (int i = 0; i < 5; i++) {
        gotoXY(x + 54, y + i + 2);
        cout << char(176);

    }
    for (int i = 0; i < 10; i++) {
        gotoXY(x + 48 + i, y + 1);
        ColorPix(0);
    }
    for (int i = 0; i < 1; i++) {
        gotoXY(x + 58, y + 1);
        cout << char(176);
    }
    for (int i = 0; i < 10; i++) {
        gotoXY(x + 48 + i, y + 7);
        ColorPix(0);
    }
    for (int i = 0; i < 1; i++) {
        gotoXY(x + 58, y + 7);
        cout << char(176);
    }

    //Chu N
    for (int i = 0; i < 7; i++) {
        gotoXY(x + 61, y + i + 1);
        ColorPix(0);
        gotoXY(x + 62, y + i + 1);
        ColorPix(0);
    }
    for (int i = 0; i < 6; i++) {
        gotoXY(x + 63, y + i + 2);
        cout << char(176);

    }
    for (int i = 0; i < 7; i++) {
        gotoXY(x + i + 63, y + i + 1);
        ColorPix(0);
        gotoXY(x + i + 64, y + i + 1);
        ColorPix(0);
    }
    for (int i = 0; i < 6; i++) {

        gotoXY(x + i + 65, y + i + 1);
        cout << char(176);
    }
    for (int i = 0; i < 7; i++) {
        gotoXY(x + 71, y + i + 1);
        ColorPix(0);
        gotoXY(x + 72, y + i + 1);
        ColorPix(0);
    }
    for (int i = 0; i < 7; i++) {
        gotoXY(x + 73, y + i + 1);
        cout << char(176);
    }
}