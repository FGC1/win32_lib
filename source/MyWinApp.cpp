#include "MyWinApp.h"

static CMyWinApp *g_MyApp = NULL;

extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

CMyWinApp::CMyWinApp()
{

}

CMyWinApp::~CMyWinApp()
{

}

BOOL CMyWinApp::InitInstance()
{
    TCHAR      szAppName[32] = TEXT("Win32LibTest");
    HWND       hWnd          = NULL;
    MSG        msg;
    WNDCLASSEX wcex;
    HINSTANCE  hInstance     = ::GetModuleHandle(NULL);

    memset(&wcex, 0, sizeof(wcex));
    memset(&msg, 0, sizeof(msg));

    wcex.cbSize        = sizeof(wcex);
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = WndProc;
    wcex.cbClsExtra    = 0;
    wcex.cbWndExtra    = 0;
    wcex.hInstance     = hInstance;
    wcex.hIcon         = ::LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor       = ::LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)::GetStockObject(GRAY_BRUSH);
    wcex.lpszMenuName  = NULL;
    wcex.lpszClassName = szAppName;
    wcex.hIconSm       = ::LoadIcon(NULL, IDI_ERROR);

    ::RegisterClassEx(&wcex);

    hWnd = CreateWindowEx(0,
                          szAppName,
                          szAppName,
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL);

    ::ShowWindow(hWnd, SW_SHOW);
    ::UpdateWindow(hWnd);

    return TRUE;
}

BOOL CMyWinApp::Run()
{
    MSG msg;

    while (::GetMessage(&msg, NULL, 0, 0))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    return msg.wParam;
}

BOOL CMyWinApp::ExitInstance()
{
    return TRUE;
}

CMyWinApp* CMyWinApp::GetWinApp()
{
    if (NULL == g_MyApp)
    {
        g_MyApp = new CMyWinApp();
    }

    return g_MyApp;
}

