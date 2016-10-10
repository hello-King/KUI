#pragma once
#include "UIlib.h"
using namespace DuiLib;

class CMainWnd : public
	WindowImplBase
{
public:
	CMainWnd();
	~CMainWnd();

	virtual void InitWindow();
	virtual void OnFinalMessage(HWND hWnd);
	virtual void Notify(TNotifyUI& msg);

	DUI_DECLARE_MESSAGE_MAP()
		virtual void OnClick(TNotifyUI& msg);

protected:
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void) const;
	virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);
	
	virtual UILIB_RESOURCETYPE GetResourceType() const;
	virtual LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM /*lParam*/, bool& /*bHandled*/);

public:
	CButtonUI* m_pClose;
	CWebBrowserEventHandler* m_pWebBrowserEventHandler;
};

