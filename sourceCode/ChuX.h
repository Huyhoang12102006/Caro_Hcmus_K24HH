﻿#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "move.h"
using namespace std;
void VeChuX(int x, int y, bool isGray/* = false*/)
{
    gotoXY(x, y); // Di chuyển con trỏ đến vị trí (x, y)
    SetConsoleOutputCP(CP_UTF8); // Đảm bảo mã hóa đúng
    // Nếu là màu xám, sẽ dùng màu 8 (gray)
    TextColor(isGray ? 240 | 8 : 240 | 4); // Màu xám hoặc đỏ (theo yêu cầu của bạn)
    std::cout << u8R"(


      ╔═════════════════════════════════╗
      ▒       ░░████╗     ████╗░░       ▒
      ▓       ░░████║     ████║░░       ▓
      ▒        ░░║████╗ ████╔═╝         ▒
      ▓        ░░╚████║ ████║ ░░        ▓
      ▒          ░░ ██████╔═╝░░         ▒
      ▓          ░░ ██████║  ░░         ▓
      ▒         ░░████╔═████╗ ░░        ▒
      ▓         ░░████║ ████║ ░░        ▓
      ▒       ░░████╔═╝   ████╗░░       ▒
      ▓       ░░████║     ████║░░       ▓
      ▒          ╚══╝     ╚═══╝         ▒
      ▓       ╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗        ▓
      ▒     * ╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝ *      ▒
      ▓       ╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═        ▓
      ╚═════════════════════════════════╝
                                )";
}

