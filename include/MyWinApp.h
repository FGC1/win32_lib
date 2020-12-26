#ifndef _MY_WIN_APP_H

#include <windows.h>

class MyWinApp
{
private:
    LPVOID m_pMainWnd;

    MyWinApp();
public:
    ~MyWinApp();

    virtual BOOL InitInstance();
    virtual BOOL ExitInstance();
    virtual BOOL Run();

    static MyWinApp* GetWinApp();
};

#endif /* _MY_WIN_APP_H */
