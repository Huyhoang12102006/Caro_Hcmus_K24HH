#pragma once
#include"move.h"
#include <iostream>
using namespace std;


void drawXplayer() {
    int u = 1;
    gotoXY(1, 0);
    cout << char(201);

    for (int i = 1; i < 35; i++) {
        cout << char(205);
    }
    cout << char(187);
    for (int rowx = 1; rowx < 20; rowx++) {
        gotoXY(3, u);
        cout << char(186);
        gotoXY(38, u);
        cout << char(186) << endl;
        ++u;
    }

    gotoXY(1, u);
    cout << char(200);
    for (int i = 1; i < 35; i++) {
        cout << char(205);
    }
    cout << char(188);



}
const int toadoPY = 100;
void drawYplayer() {

    int u = 1;
    gotoXY(toadoPY, 0);
    cout << char(201);
    for (int i = 1; i < 35; i++) {
        cout << char(205);
    }
    cout << char(187);
    for (int rowx = 1; rowx < 20; rowx++) {
        gotoXY(toadoPY, u);
        cout << char(186);
        gotoXY(toadoPY + 35, u);
        cout << char(186) << endl;
        ++u;
    }

    gotoXY(toadoPY, u);
    cout << char(200);
    for (int i = 1; i < 35; i++) {
        cout << char(205);
    }
    cout << char(188);



}