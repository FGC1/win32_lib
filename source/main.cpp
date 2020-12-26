#include <windows.h>
#include <stdio.h>
#include "MyWinApp.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_CLOSE:
        {
            ::DestroyWindow(hWnd);
            return 0;
        }
        case WM_DESTROY:
        {
            ::PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPTSTR szCmdLine,
                   int nCmdShow)
{
    CMyWinApp *pMyWinApp = NULL;

    pMyWinApp = CMyWinApp::GetWinApp();

    pMyWinApp->InitInstance();
    pMyWinApp->Run();
    pMyWinApp->ExitInstance();

    return 0;
}