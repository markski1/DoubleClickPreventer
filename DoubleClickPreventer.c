/*
    
    DoubleClickPreventer

    Served as-is. This is a simple-as-they-come hook on WH_MOUSE_LL.
    There is no reason for an anticheat to detect this as a cheat.
    If it does, it's not my problem.

    github.com/markski1
    markski.ar

*/

#include <stdio.h>
#include <Windows.h>


static  HHOOK      mouseHookId = NULL;
static  ULONGLONG  lastClickMs = 0;
const   ULONGLONG  clickTimeThreshold = 100;


static LRESULT CALLBACK ClickDetect(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0 && wParam == WM_LBUTTONDOWN)
    {
        ULONGLONG currTime = GetTickCount64();

        // Drop clicks which happen within 100ms of the last.
        if (lastClickMs + clickTimeThreshold > currTime)
        {
            printf("Prevented.\n");
            return 0;
        }

        lastClickMs = currTime;
    }

    return CallNextHookEx(mouseHookId, nCode, wParam, lParam);
}


static BOOL ExitHandler(DWORD fdwCtrlType)
{
    switch (fdwCtrlType)
    {
        case CTRL_C_EVENT:
        case CTRL_CLOSE_EVENT:
            UnhookWindowsHookEx(mouseHookId);
            return TRUE;
        default:
            return FALSE;
    }
}


int main()
{
    if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)ExitHandler, TRUE)) {
        printf("Couldn't set an exit handler. This would prevent cleanup.");
        return 1;
    }

    mouseHookId = SetWindowsHookEx(WH_MOUSE_LL, ClickDetect, GetModuleHandle(NULL), 0);

    if (mouseHookId == NULL)
    {
        printf("Could not hook the mouse click.\n");
        return 1;
    }

    printf("Now detecting double clicks. Feel free to minimize this window.\n");

    // keep the program running
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
