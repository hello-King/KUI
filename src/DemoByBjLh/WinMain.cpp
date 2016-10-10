
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <objbase.h>

#include "MainWnd.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;
	// ��ʼ��UI������
	CPaintManagerUI::SetInstance(hInstance);
	// ��ʼ����Դ

	CMainWnd* pFrame = new CMainWnd();
	if (pFrame == NULL) return 0;
	pFrame->Create(NULL, _T("������ؼ�"), UI_WNDSTYLE_FRAME, 0L);
	pFrame->CenterWindow();
	pFrame->ShowModal();

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	return 0;
}