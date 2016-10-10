#include "MainWnd.h"
#include "CustomWebEventHandler.h"

CMainWnd::CMainWnd()
{
}


CMainWnd::~CMainWnd()
{
}

DUI_BEGIN_MESSAGE_MAP(CMainWnd, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()


void CMainWnd::InitWindow()
{
	CActiveXUI* pActiveXUI = static_cast<CActiveXUI*>(m_PaintManager.FindControl(_T("ie")));
	if (pActiveXUI)
	{
		IWebBrowser2* pWebBrowser = NULL;
		pActiveXUI->GetControl(IID_IWebBrowser2, (void**)&pWebBrowser);
		if (pWebBrowser != NULL)
		{
			pWebBrowser->Navigate(L"http://www.baidu.com", NULL, NULL, NULL, NULL);
			pWebBrowser->Release();
		}
	}

	CWebBrowserUI* pActiveXUI1 = static_cast<CWebBrowserUI*>(m_PaintManager.FindControl(_T("ie2")));

	if (pActiveXUI1)
	{
		pActiveXUI1->SetDelayCreate(false);
		CCustomWebEventHandler *pWebHandle = new CCustomWebEventHandler;
		pActiveXUI1->SetWebBrowserEventHandler(pWebHandle);
		pActiveXUI1->Navigate2(L"about:blank");    //这行代码，如果注释掉，就不会去掉边框，IE有bug，第二次加载网页才会让事件处理器有效
		pActiveXUI1->Navigate2(L"http://www.163.com/");
	}
}
void CMainWnd::OnFinalMessage(HWND hWnd)
{
	__super::OnFinalMessage(hWnd);

	delete this;
}
void CMainWnd::Notify(TNotifyUI& msg)
{
	__super::Notify(msg);
}
void CMainWnd::OnClick(TNotifyUI& msg)
{
	CDuiString sCtrlName = msg.pSender->GetName();
	if (sCtrlName == _T("closebtn"))
	{
		Close();
		return;
	}
	else if (sCtrlName == _T("minbtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		return;
	}
	else if (sCtrlName == _T("maxbtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		return;
	}
	else if (sCtrlName == _T("restorebtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0);
		return;
	}
	return;
}
CDuiString CMainWnd::GetSkinFolder()
{
	return L"resources\\";
}
CDuiString CMainWnd::GetSkinFile()
{
	return L"IEDemo.xml";
}
LPCTSTR CMainWnd::GetWindowClassName(void) const
{
	return L"DUI";
}
LRESULT CMainWnd::ResponseDefaultKeyEvent(WPARAM wParam)
{
	return S_OK;
}

UILIB_RESOURCETYPE CMainWnd::GetResourceType() const
{
	return UILIB_FILE;
}

LRESULT CMainWnd::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM /*lParam*/, bool& /*bHandled*/)
{
	return S_OK;
}
LRESULT CMainWnd::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{
	PostQuitMessage(0);

	return S_OK;
}