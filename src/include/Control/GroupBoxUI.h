//#pragma once
//
//
//#define  GROUPBOX_TEXT_OFFSET		20		//����GroupBox�е�Text�������ߵ�ƫ��
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
//		DWORD	m_dwTextColor;		///������ɫ
//		int		m_iFont;			///����ţ���С
//		bool	m_bShowHtml;		///�Ƿ���ʾHTML����
//		int		m_iTextWidth;		///Text���ֿ�
//		int		m_iTextHeigh;		///Text���ָ�
//	};
//}
//

#ifndef __UIGROUPBOX_H__
#define __UIGROUPBOX_H__

#pragma once

#define  GROUPBOX_TEXT_OFFSET		20		//����GroupBox�е�Text�������ߵ�ƫ��

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