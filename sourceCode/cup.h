#pragma once
#include<iostream>
#include<conio.h>
#include<windows.h>
#include"move.h"
#include"changeconsole.h"
using namespace std;
void VeCup(int x, int y)
{
    for (int i = 0; i < 10; i++) {
        gotoXY(x + 12 + i, y + 1);
        ColorPix(0);
    }
    for (int i = 0; i < 8; i++) {
        gotoXY(x + 4 + i, y + 2);
        ColorPix(0);
        gotoXY(x + 22 + i, y + 2);
        ColorPix(0);
    }
    for (int i = 0; i < 6; i++) {
        gotoXY(x + 6 + i, y + 4);
        ColorPix(0);
        gotoXY(x + 22 + i, y + 4);
        ColorPix(0);
    }
    for (int i = 0; i < 4; i++) {
        gotoXY(x + 2, y + 3 + i);
        ColorPix(0);
        gotoXY(x + 3, y + 3 + i);
        ColorPix(0);
        gotoXY(x + 30, y + 3 + i);
        ColorPix(0);
        gotoXY(x + 31, y + 3 + i);
        ColorPix(0);
    }
    for (int i = 0; i < 4; i++) {
        gotoXY(x + 8 + i, y + 6);
        ColorPix(0);
        gotoXY(x + 22 + i, y + 6);
        ColorPix(0);
    }
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 6 + i, y + 5);
        ColorPix(0);
        gotoXY(x + 10 + i, y + 5);
        ColorPix(0);
        gotoXY(x + 22 + i, y + 5);
        ColorPix(0);
        gotoXY(x + 26 + i, y + 5);
        ColorPix(0);
    }
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 4 + i, y + 7);
        ColorPix(0);
        gotoXY(x + 28 + i, y + 7);
        ColorPix(0);
    }
    for (int i = 0; i < 4; i++) {
        gotoXY(x + 6 + i, y + 8);
        ColorPix(0);
        gotoXY(x + 24 + i, y + 8);
        ColorPix(0);
    }
    for (int i = 0; i < 4; i++) {
        gotoXY(x + 10 + i, y + 9);
        ColorPix(0);
        gotoXY(x + 20 + i, y + 9);
        ColorPix(0);
    }
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 14 + i, y + 10);
        ColorPix(0);
        gotoXY(x + 18 + i, y + 10);
        ColorPix(0);
    }
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 16 + i, y + 11);
        ColorPix(0);
    }
    for (int i = 0; i < 10; i++) {
        gotoXY(x + 12 + i, y + 12);
        ColorPix(0);
    }
    for (int i = 0; i < 10; i++) {
        gotoXY(x + 12 + i, y + 14);
        ColorPix(0);
    }
    for (int i = 0; i < 3; i++) {
        gotoXY(x + 10, y + 12 + i);
        ColorPix(0);
        gotoXY(x + 11, y + 12 + i);
        ColorPix(0);
        gotoXY(x + 22, y + 12 + i);
        ColorPix(0);
        gotoXY(x + 23, y + 12 + i);
        ColorPix(0);
    }
    //Tô màu 
    for (int i = 0; i < 10; i++) {
        gotoXY(x + 12 + i, y + 2);
        ColorPix(6);
    }
    for (int i = 0; i < 26; i++) {
        gotoXY(x + 4 + i, y + 3);
        ColorPix(6);
    }
    for (int i = 0; i < 4; i++) {
        gotoXY(x + 4 + i, y + 6);
        ColorPix(6);
        gotoXY(x + 26 + i, y + 6);
        ColorPix(6);
    }
    for (int i = 0; i < 4; i++) {
        gotoXY(x + 4, y + 3 + i);
        ColorPix(6);
        gotoXY(x + 5, y + 3 + i);
        ColorPix(6);
        gotoXY(x + 28, y + 3 + i);
        ColorPix(6);
        gotoXY(x + 29, y + 3 + i);
        ColorPix(6);
    }
    for (int i = 0; i < 22; i++) {
        gotoXY(x + 6 + i, y + 7);
        ColorPix(6);
    }
    for (int i = 0; i < 14; i++) {
        gotoXY(x + 10 + i, y + 8);
        ColorPix(6);
    }
    for (int i = 0; i < 10; i++) {
        gotoXY(x + 12 + i, y + 4);
        ColorPix(6);
        gotoXY(x + 12 + i, y + 5);
        ColorPix(6);
        gotoXY(x + 12 + i, y + 6);
        ColorPix(6);
    }
    for (int i = 0; i < 6; i++) {
        gotoXY(x + 14 + i, y + 9);
        ColorPix(6);
    }
    for (int i = 0; i < 2; i++) {
        gotoXY(x + 16 + i, y + 10);
        ColorPix(6);
    }
    for (int i = 0; i < 10; i++) {
        gotoXY(x + 12 + i, y + 13);
        ColorPix(6);
    }
    for (int i = 0; i < 5; i++) {
        gotoXY(x + 16, y + 3 + i);
        ColorPix(4);
        gotoXY(x + 17, y + 3 + i);
        ColorPix(4);
    }
    for (int i = 0; i < 1; i++) {
      
        gotoXY(x + 14, y + 4 + i);
        ColorPix(4);
        gotoXY(x + 15, y + 4 + i);
        ColorPix(4);
    }
    TextColor(240 | 15);
    
}