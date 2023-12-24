#include "pch.h"
#include "Dinosaur.h"

Dinosaur::Dinosaur()
{
	x = 200;
	y = 550;
	point = 0;
	type = 0;
	control = true;
	width = 150;	//Kích thước khủng long
	hight = 160;	//
	display_hitbox = true;
	speed = 26;
	head_hitbox.x1 = x + (width / 2);
	head_hitbox.y1 = y;
	head_hitbox.x2 = x + width;
	head_hitbox.y2 = y + (hight / 2);

	body_hitbox.x1 = x;
	body_hitbox.y1 = y + (hight / 2);
	body_hitbox.x2 = x + width - (width / 10);
	body_hitbox.y2 = y + hight - (hight / 5);

	leg_hitbox.x1 = x + (width / 2);
	leg_hitbox.y1 = y + hight - (hight / 5);
	leg_hitbox.x2 = x + width - (width / 10);
	leg_hitbox.y2 = y + width;

}

void Dinosaur::display(CDC* cdc)
{
	CBitmap bitmap;
	CDC memDC;
	switch (type){
		case 0:
		{
			bitmap.LoadBitmap(IDB_BITMAP11);
			break;
		}
		case 1:
		{
			bitmap.LoadBitmap(IDB_BITMAP12);
			break;
		}
		case 2:
		{
			bitmap.LoadBitmap(IDB_BITMAP13);
			break;
		}
		default:
		{
			bitmap.LoadBitmap(IDB_BITMAP3);
		}
		
	}

	memDC.CreateCompatibleDC(cdc);
	CBitmap* pOldBitmap = memDC.SelectObject(&bitmap);

	cdc->TransparentBlt(x, y, width, hight, &memDC, 0, 0, 200, 192, RGB(255, 255, 255));
	memDC.SelectObject(pOldBitmap);
}

void Dinosaur::changetype()
{
	if (type == 0) {
		type = 1;
		return;
	}
	if (type == 1) {
		type = 2;
		return;
	}
	if (type == 2) {
		type = 0;
		return;
	}
}

void Dinosaur::clear(CClientDC* pdc, CDC* cdc)
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
	cdc->TransparentBlt(0, 100, 1980, 668, &memDC, 0, 0, 1694, 668, RGB(255, 0, 0));
	memDC.SelectObject(pOldBitmap);
	
}

void Dinosaur::move(CClientDC* pdc,CDC* cdc)
{
	
}

void Dinosaur::jump()
{
	while (y >= 350) {
		y -= 5;
		Sleep(speed);
	}
	x += 5;
	Sleep(speed + 10);
	while (y <= 550) {
		y += 5;
		Sleep(speed);
	}
	x -= 5;
}

void Dinosaur::update_hitbox()
{
	head_hitbox.x1 = x + (width / 2);
	head_hitbox.y1 = y;
	head_hitbox.x2 = x + width;
	head_hitbox.y2 = y + (hight / 2);

	body_hitbox.x1 = x;
	body_hitbox.y1 = y + (hight / 2);
	body_hitbox.x2 = x + width - (width / 10);
	body_hitbox.y2 = y + hight - (hight / 5);

	leg_hitbox.x1 = x + (width / 2);
	leg_hitbox.y1 = y + hight - (hight / 5);
	leg_hitbox.x2 = x + width - (width / 10);
	leg_hitbox.y2 = y + width;
}

void Dinosaur::displayhitbox(CClientDC* pdc)
{
	if (!display_hitbox) {
		return;
	}
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen* pOldPen = pdc->SelectObject(&pen);

	pdc->Rectangle(head_hitbox.x1, head_hitbox.y1, head_hitbox.x2, head_hitbox.y2);
	pdc->Rectangle(body_hitbox.x1, body_hitbox.y1, body_hitbox.x2, body_hitbox.y2);
	pdc->Rectangle(leg_hitbox.x1, leg_hitbox.y1, leg_hitbox.x2, leg_hitbox.y2);

	pdc->SelectObject(pOldPen);
}

Hitbox Dinosaur::headhitbox()
{
	return head_hitbox;
}

Hitbox Dinosaur::bodyhitbox()
{
	return body_hitbox;
}

Hitbox Dinosaur::leghitbox()
{
	return leg_hitbox;
}

void Dinosaur::increase_point()
{
	++point;
}

void Dinosaur::displaypoint(CClientDC* pdc)
{
	CString poi;
	CFont font;
	// Set Font + Color
	font.CreatePointFont(150, _T("Arial"));
	CFont* pOldFont = pdc->SelectObject(&font);
	pdc->SetTextColor(RGB(255, 255, 255));
	CRect rect(0, 0, 200, 100);
	// Set Pen ( Hem rectangle)
	CPen pen(PS_SOLID, 4, RGB(255, 50, 255));
	CPen* pOldPen = pdc->SelectObject(&pen);
	// Set brush rectangle
	CBrush myBrush(RGB(20, 20, 100));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	poi.Format(_T(" Point: %d"), point);
	pdc->Rectangle(rect);
	pdc->DrawText(poi, rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_NOCLIP);
	// Set default
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
	pdc->SelectObject(pOldFont);
	pdc->SetTextColor(RGB(0, 0, 0));
}

int Dinosaur::getpoint()
{
	return point;
}

int Dinosaur::addpoint(int p)
{
	point += p;
	return 0;
}

void Dinosaur::setspeed(int s)
{
	speed = s;
}

int Dinosaur::getspeed()
{
	return speed;
}


