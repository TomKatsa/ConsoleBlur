#include <Windows.h>
#include <stdio.h>
#include "windowstructs.h"


void MakeTransparent(HWND hWnd) {
    AccentPolicy policy = {ACCENT_ENABLE_BLURBEHIND, 2, 0x80000000,0};
    WindowCompositionAttributeData data = {WCA_ACCENT_POLICY, &policy, sizeof(AccentPolicy) };
    FARPROC FuncPointer = GetProcAddress(GetModuleHandle("user32.dll"), "SetWindowCompositionAttribute");
    BOOL (*SetWindowCompositionAttribute)(HWND, WindowCompositionAttributeData*) = (BOOL (*)(HWND, WindowCompositionAttributeData*))FuncPointer;
    SetWindowCompositionAttribute(hWnd, &data);
}


BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM name) {
    char buff[100];
    GetWindowText(hWnd, buff, 100);
    if (strcmp((char*)name, buff) == 0) {
        MakeTransparent(hWnd);
        return FALSE;
    }
    return TRUE;
}


int main(int argc, char const *argv[])
{
    char ConsoleName[100];
    GetConsoleTitle(ConsoleName, 100);
    EnumWindows(EnumWindowsProc, (LPARAM)ConsoleName);
    return 0;
}
