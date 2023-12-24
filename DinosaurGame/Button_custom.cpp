#include "pch.h"
#include "Button_custom.h"

Button_custom::Button_custom()
{
	x = 0;
	y = 0;
	caption = "";
}

Button_custom::Button_custom(int mx, int my, int msize, CString cap)
{
	x = mx;
	y = my;
	caption = cap;
	size = msize;
	enable = true;
}

void Button_custom::display(CClientDC* pdc, HDC hdc, CDC* cdc)
{
	if (!enable) {
		return;
	}
	CRect rect(x, y, x + 100 + (size * 10), y + 50 + (size * 5));

	CBitmap bitmap;
	CDC memDC;
	bitmap.LoadBitmapW(IDB_BITMAP8);
	memDC.CreateCompatibleDC(cdc);
	CBitmap* pOldBitmap = memDC.SelectObject(&bitmap);

	cdc->TransparentBlt(x, y, 100 + (size * 10), 50 + (size * 5), &memDC, 0, 0, 100, 50, RGB(255, 255, 255));

	memDC.SelectObject(pOldBitmap);
	CFont font;
	font.CreatePointFont(180 + (size * 10), _T("Times New Roman"));
	CFont* pOldFont = pdc->SelectObject(&font);
	pdc->TextOutW(x + 15 + (size * 2), y + 7 + size, caption);
	pdc->SelectObject(pOldFont);
}

void Button_custom::display_select(CClientDC* pdc, HDC hdc, CDC* cdc)
{
	if (!enable) {
		return;
	}
	CRect rect(x, y, x + 100 + (size * 10), y + 50 + (size * 5));

	CBitmap bitmap;
	CDC memDC;
	bitmap.LoadBitmapW(IDB_BITMAP9);
	memDC.CreateCompatibleDC(cdc);
	CBitmap* pOldBitmap = memDC.SelectObject(&bitmap);

	cdc->TransparentBlt(x, y, 100 + (size * 10), 50 + (size * 5), &memDC, 0, 0, 100, 50, RGB(255, 255, 255));

	memDC.SelectObject(pOldBitmap);
	CFont font;
	font.CreatePointFont(180 + (size * 10), _T("Times New Roman"));
	CFont* pOldFont = pdc->SelectObject(&font);
	pdc->TextOutW(x + 15 + (size * 2), y + 7 + size, caption);
	pdc->SelectObject(pOldFont);
}

bool Button_custom::isMouseOn(CPoint p)
{
	if (!enable) {
		return false;
	}
	if (p.x >= x + size && p.x <= x + 100 + (size * 10) - size && p.y >= y + size && p.y <= y + 50 + (size * 5) - size) {
		return true;
	}
	return false;
}

bool Button_custom::isOnClick(UINT nChar, CPoint p)
{
	if (!enable) {
		return false;
	}
	if (isMouseOn(p) && nChar == 1) {
		return true;
	}
	return false;
}

void Button_custom::change(int mx, int my, int msize, CString cap)
{
	x = mx;
	y = my;
	size = msize;
	caption = cap;
}

bool Button_custom::getEnable()
{
	return enable;
}

bool Button_custom::isEnable()
{
	enable = true;
	return enable;
}

bool Button_custom::notEnable()
{
	enable = false;
	return enable;
}
