#include "pch.h"
#include "Cactus.h"

Cactus::Cactus()
{
	x = 0;
	y = 0;
	type = 0;
	width = 0;
	height = 0;
	cactus_hitbox.x1 = 0;
	cactus_hitbox.y1 = 0;
	cactus_hitbox.x2 = 0;
	cactus_hitbox.y2 = 0;
	exist = false;
	display_hitbox = true;
	sizebitmap1 = 0;
	sizebitmap2 = 0;
}

void Cactus::Create(int x, int type)
{
	this->x = x;
	y = 600;
	this->type = type;
	width = 100;
	height = 120;
	sizebitmap1 = 200;
	sizebitmap2 = 230;
	exist = true;
}

void Cactus::display(CDC* cdc)
{
	if (!exist) {
		return;
	}
	CBitmap bitmap;
	CDC memDC;
	CBitmap* pOldBitmap = NULL;
	// Tải bitmap từ tệp
	bitmap.LoadBitmap(IDB_BITMAP5);

	// Tạo một DC tạm thời để chứa bitmap
	memDC.CreateCompatibleDC(cdc);
	pOldBitmap = memDC.SelectObject(&bitmap);
	switch (type) {
	case 0:
		// Vẽ bitmap lên DC hiện tại với background
		cdc->TransparentBlt(x, y, width, height, &memDC, 0, 0, sizebitmap1, sizebitmap2, RGB(255, 255, 255));
		break;
	case 1:
		cdc->TransparentBlt(x, y, width - 50, height, &memDC, 0, 0, sizebitmap1, sizebitmap2, RGB(255, 255, 255));
		break;
	case 2:
		cdc->TransparentBlt(x, y + 50, width, height - 50, &memDC, 0, 0, sizebitmap1, sizebitmap2, RGB(255, 255, 255));
		break;
	case 3:
		cdc->TransparentBlt(x, y, width - 50, height - 50, &memDC, 0, 0, sizebitmap1, sizebitmap2, RGB(255, 255, 255));
		break;
	}
	memDC.SelectObject(pOldBitmap);
}

void Cactus::sethitbox()
{
	switch (type) {
	case 0:
		cactus_hitbox.x1 = x + 2;
		cactus_hitbox.y1 = y;
		cactus_hitbox.x2 = x - 2 + width;
		cactus_hitbox.y2 = y + height;
		break;
	case 1:
		cactus_hitbox.x1 = x;
		cactus_hitbox.y1 = y;
		cactus_hitbox.x2 = x + width - 50;
		cactus_hitbox.y2 = y + height;
		break;
	case 2:
		cactus_hitbox.x1 = x;
		cactus_hitbox.y1 = y + 50;
		cactus_hitbox.x2 = x + width;
		cactus_hitbox.y2 = y + height;
		break;
	case 3:
		cactus_hitbox.x1 = x;
		cactus_hitbox.y1 = y + 50;
		cactus_hitbox.x2 = x + width - 50;
		cactus_hitbox.y2 = y + height;
		break;
	}
}

void Cactus::displayhitbox(CClientDC* pdc)
{
	if (!display_hitbox) {
		return;
	}
	this->sethitbox();
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen* pOldPen = pdc->SelectObject(&pen);

	pdc->Rectangle(cactus_hitbox.x1, cactus_hitbox.y1, cactus_hitbox.x2, cactus_hitbox.y2);

	pdc->SelectObject(pOldPen);
}

Hitbox Cactus::getHitbox()
{
	return cactus_hitbox;
}


bool Cactus::check_exist()
{
	if (x <= 50) {
		exist = false;
	}
	return exist;
}



void Cactus::clear(CClientDC* pdc)
{
	CPen pen(PS_SOLID, 1, RGB(10, 20, 30));
	CPen* pOldPen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(10, 20, 30));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);

	pdc->Rectangle(x - 2, y, x + width + 2, y + height);

	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
}

void Cactus::move()
{
	x -= 5;
}

void Cactus::reset()
{
	x = 0;
	y = 0;
	type = 0;
	width = 0;
	height = 0;
	cactus_hitbox.x1 = 0;
	cactus_hitbox.y1 = 0;
	cactus_hitbox.x2 = 0;
	cactus_hitbox.y2 = 0;
	exist = false;
	sizebitmap1 = 0;
	sizebitmap2 = 0;
}
