#ifndef _MY_WIN_APP_H

#include <windows.h>

class CMyWinApp
{
private:
    LPVOID m_pMainWnd;

    CMyWinApp();
public:
    ~CMyWinApp();

    virtual BOOL InitInstance();
    virtual BOOL ExitInstance();
    virtual BOOL Run();

    static CMyWinApp* GetWinApp();
};

#endif /* _MY_WIN_APP_H */
