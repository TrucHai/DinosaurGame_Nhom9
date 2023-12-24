#include "pch.h"
#include "Background.h"

Background::Background()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Background::Background(int x, int y)
{
	this->x = x;
	this->y = y;
	w = 1600;
	h = 900;
}

void Background::display(CDC* cdc)
{
	CBitmap bitmap;
	CDC memDC;
	CBitmap* pOldBitmap = NULL;
	// Tải bitmap từ tệp
	bitmap.LoadBitmap(IDB_BITMAP7);

	// Tạo một DC tạm thời để chứa bitmap
	memDC.CreateCompatibleDC(cdc);
	pOldBitmap = memDC.SelectObject(&bitmap);

	// Vẽ bitmap lên DC hiện tại với background
	
	cdc->TransparentBlt(x, y, 1980, 668, &memDC, 0, 0, 1694, 668, RGB(255, 159, 255));

	memDC.SelectObject(pOldBitmap);
}

void Background::display_menu(CDC* cdc)
{
	CBitmap bitmap;
	CDC memDC;
	CBitmap* pOldBitmap = NULL;
	// Tải bitmap từ tệp
	bitmap.LoadBitmap(IDB_BITMAP10);

	// Tạo một DC tạm thời để chứa bitmap
	memDC.CreateCompatibleDC(cdc);
	pOldBitmap = memDC.SelectObject(&bitmap);

	// Vẽ bitmap lên DC hiện tại với background

	cdc->TransparentBlt(0, 0, 1960, 1080, &memDC, 0, 0, 1960, 1080, RGB(255, 159, 255));

	memDC.SelectObject(pOldBitmap);
}

void Background::displayBG(int x, int y, int w, int h, CDC* cdc)
{
	CBitmap background;
	CDC memDC;
	background.LoadBitmapW(IDB_BITMAP14);
	memDC.CreateCompatibleDC(cdc);
	CBitmap* pOldBitmap = memDC.SelectObject(&background);
	cdc->TransparentBlt(x, y, w, h, &memDC, 0, 0, 1960, 1080, RGB(0, 0, 0));

	memDC.SelectObject(pOldBitmap);
}
