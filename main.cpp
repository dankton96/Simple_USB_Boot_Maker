#include <windows.h>
#include <winuser.h>
#include <winable.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <thread>
#include <conio.h>
#include <string>
#include <string.h>
#define WINVER 0x0500

using namespace std;

void SendToKeyboard(int letter)
{
     // This structure will be used to create the keyboard
    // input event.
    INPUT ip;
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "A" key
    ip.ki.wVk = letter; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

    // Exit normally
}

int main()
{
    string var;
    var="t";
    SendToKeyboard((int)var[0]); //it's sending system date and time
    return 0;
}
