#include <Windows.h>
#include <stdio.h>
#include "windowstructs.h"


void MakeTransparent(HWND hWnd) {
    // Policy parameters: { AccentState, AccentFlags, GradientColor (0xAARRGGBB), Animationid }
    // 2 Flag enables the use of gradient color (Making the window half-transparent improves the look on light background)
    AccentPolicy policy = {ACCENT_ENABLE_BLURBEHIND, 2, 0x80000000,0}; 
    WindowCompositionAttributeData data = {WCA_ACCENT_POLICY, &policy, sizeof(AccentPolicy) };
    FARPROC FuncPointer = GetProcAddress(GetModuleHandle("user32.dll"), "SetWindowCompositionAttribute"); // Get the undocumented func address
    BOOL (*SetWindowCompositionAttribute)(HWND, WindowCompositionAttributeData*) = (BOOL (*)(HWND, WindowCompositionAttributeData*))FuncPointer;
    SetWindowCompositionAttribute(hWnd, &data);
}


BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM name) {
    char buff[100];
    GetWindowText(hWnd, buff, 100);
    if (strcmp((char*)name, buff) == 0) { // If window name matches this console name
        MakeTransparent(hWnd);
        return FALSE;
    }
    return TRUE; // Iterate the window handles
}


int main(int argc, char const *argv[])
{
    char ConsoleName[100];
    GetConsoleTitle(ConsoleName, 100);
    EnumWindows(EnumWindowsProc, (LPARAM)ConsoleName);
    return 0;
}
