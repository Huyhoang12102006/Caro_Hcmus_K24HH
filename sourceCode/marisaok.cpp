#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <ctime> 
#include <vector>
#include <string>
#include "board.h"
#include "move.h"
#include "changeconsole.h"
#include "drawplayerXY.h"
#include "playgame.h"
#include "PVC(hard).h"
#include "pvceasy.h"
#include "menu.h"
#include "PvPtime.h"
#include "menuviet.h"
#include "savegame.h"

#pragma comment(lib, "winmm.lib")
using namespace std;

int main() {
    SetConsoleOutputCP(437);
    system("cls");
    resizeConsole(1150, 750);
    system("color f0");
    fixConsoleScroll();
    setConsoleFont(L"Consolas", 16);
    FixConsoleWindow();
    hienmenu();
}
