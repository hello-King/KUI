//#pragma once
//
//
//#define  GROUPBOX_TEXT_OFFSET		20		//定义GroupBox中的Text相对于左边的偏移
//
//namespace DuiLib {
//	class CGroupBoxUI :
//		public CContainerUI
//	{
//	public:
//		CGroupBoxUI();
//		~CGroupBoxUI();
//		virtual LPCTSTR GetClass() const;
//		virtual LPVOID GetInterface(LPCTSTR pstrName);
//		virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
//		void PaintText(HDC hDC);
//		void PaintBorder(HDC hDC);
//		void SetTextColor(DWORD dwTextColor);
//		void SetFont(int iFont);
//		void SetShowHtml(bool bShowHtml);
//
//	private:
//		DWORD	m_dwTextColor;		///字休颜色
//		int		m_iFont;			///字体号，大小
//		bool	m_bShowHtml;		///是否显示HTML代码
//		int		m_iTextWidth;		///Text文字宽
//		int		m_iTextHeigh;		///Text文字高
//	};
//}
//

#ifndef __UIGROUPBOX_H__
#define __UIGROUPBOX_H__

#pragma once

#define  GROUPBOX_TEXT_OFFSET		20		//定义GroupBox中的Text相对于左边的偏移

namespace DuiLib
{

	class UILIB_API CGroupBoxUI : public CVerticalLayoutUI
	{
		//DECLARE_DUICONTROL(CGroupBoxUI)
	public:
		CGroupBoxUI();
		~CGroupBoxUI();
		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		void SetTextColor(DWORD dwTextColor);
		DWORD GetTextColor() const;
		void SetDisabledTextColor(DWORD dwTextColor);
		DWORD GetDisabledTextColor() const;
		void SetFont(int index);
		int GetFont() const;

	protected:
		//Paint
		virtual void PaintText(HDC hDC);
		virtual void PaintBorder(HDC hDC);
		virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	private:
		SIZE CalcrectSize(SIZE szAvailable);

	protected:
		DWORD m_dwTextColor;
		DWORD m_dwDisabledTextColor;
		int m_iFont;
		UINT m_uTextStyle;
		RECT m_rcTextPadding;
	};
}
#endif // __UIGROUPBOX_H__