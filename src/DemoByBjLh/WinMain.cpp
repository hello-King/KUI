
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <objbase.h>

#include "MainWnd.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;
	// 初始化UI管理器
	CPaintManagerUI::SetInstance(hInstance);
	// 初始化资源

	CMainWnd* pFrame = new CMainWnd();
	if (pFrame == NULL) return 0;
	pFrame->Create(NULL, _T("浏览器控件"), UI_WNDSTYLE_FRAME, 0L);
	pFrame->CenterWindow();
	pFrame->ShowModal();

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	return 0;
}