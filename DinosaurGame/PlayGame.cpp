#include "pch.h"
#include "PlayGame.h"

PlayGame::PlayGame()
{
	backmain = Background(0, 100);
	maindino = Dinosaur();
	lose = false;
	played = false;
	cactus[0] = Cactus();
	cactus[1] = Cactus();
	cactus[2] = Cactus();
	jumping = false;
	Bplay = Button_custom(750, 400, 15, L"Play");
	ismenu = true;
	isrestart = false;
	lev = 0;
}

void PlayGame::display_menu(CClientDC* pdc, HDC hdc, CDC* cdc)
{
	backmain.display_menu(cdc);
	Bplay.display(pdc, hdc, cdc);

}

void PlayGame::create_cactus(CClientDC* pdc, CDC* cdc)
{
	while (!lose) {

		int rantime, rantype;
		srand(time(NULL));
		rantime = int((3000 - (lev * 500)) + rand() % ((5000 - (lev * 500)) - (3000 - (lev * 500)) + 1));
		rantype = int(rand() % 3);
	//	Sleep(rantime); Tạo khoảng thời gian tạo lại cây xương rồng
		if (!cactus[0].check_exist()) {
			cactus[0].Create(1700, rantype);
			//test(pdc, cdc, 500, 800, rantype);
			//test(pdc, cdc, 500, 900, rantime);
			Sleep(rantime);
			continue;
		}
		if (!cactus[1].check_exist()) {
			cactus[1].Create(1700, rantype);
			//test(pdc, cdc, 600, 800, rantype);
			//test(pdc, cdc, 600, 900, rantime);
			Sleep(rantime);
			continue;
		}
		if (!cactus[2].check_exist()) {
			cactus[2].Create(1700, rantype);
			//test(pdc, cdc, 700, 800, rantype);
			//test(pdc, cdc, 700, 900, rantime);
			Sleep(rantime);
			continue;
		}
	}

}

void PlayGame::displaycactus(CClientDC* pdc, CDC* cdc)
{
	if (cactus[0].check_exist()) {
		//cactus[0].displayhitbox(pdc);
		cactus[0].display(cdc);
	}

	if (cactus[1].check_exist()) {
		//cactus[1].displayhitbox(pdc);
		cactus[1].display(cdc);
	}

	if (cactus[2].check_exist()) {
		//cactus[2].displayhitbox(pdc);
		cactus[2].display(cdc);
	}
	
}

void PlayGame::movecactus()
{
	while (!lose) {
		Sleep(30 - (lev * 5));
		if (cactus[0].check_exist()) {
			cactus[0].move();
			cactus[0].sethitbox();
		}
		if (cactus[1].check_exist()) {
			cactus[1].move();
			cactus[1].sethitbox();
		}
		if (cactus[2].check_exist()) {
			cactus[2].move();
			cactus[2].sethitbox();
		}
		
	}
}

void PlayGame::displaydino(CClientDC* pdc, CDC* cdc)
{
	maindino.update_hitbox();
	//maindino.displayhitbox(pdc);
	maindino.display(cdc);
}

void PlayGame::movedino()
{
	while (!lose) {
		if (!jumping) {
			maindino.changetype();
		}
		maindino.increase_point();
		Sleep(200);
	}
}

void PlayGame::dinojump()
{
	jumping = true;
	maindino.jump();
	jumping = false;
}

bool PlayGame::isjumping()
{
	return jumping;
}

bool PlayGame::getlose()
{
	return lose;
}

bool PlayGame::getplayed()
{
	return played;
}

bool PlayGame::isplayed()
{
	played = true;
	return played;
}


void PlayGame::displayupdate(CClientDC* pdc, CDC* cdc)
{
	while (!lose) {
		backmain.display(cdc);
		this->displaycactus(pdc, cdc);
		this->displaydino(pdc, cdc);
		maindino.displaypoint(pdc);
		if (!checklose()) {
			Bplay.change(750, 700, 15, L"Restart");
			Bplay.isEnable();
			isrestart = true;
			this->lose_display(pdc, cdc);
		};
		if (maindino.getpoint() > 100 && maindino.getpoint() < 500) {
			lev = 1;
			maindino.setspeed(25);
		}
		if (maindino.getpoint() > 500 && maindino.getpoint() < 1000) {
			lev = 2;
			maindino.setspeed(22);
		}
		if (maindino.getpoint() > 1000 && maindino.getpoint() < 1500) {
			lev = 3;
			maindino.setspeed(17);
		}
		if (maindino.getpoint() > 1500 && maindino.getpoint() < 2000) {
			lev = 4;
			maindino.setspeed(15);
		}
		if (maindino.getpoint() > 3000) {
			lev = 5;
			maindino.setspeed(10);
		}
		Sleep(20);
	}
}

bool PlayGame::checklose()
{
	Hitbox headdino = maindino.headhitbox();
	Hitbox bodydino = maindino.bodyhitbox();
	Hitbox legdino = maindino.leghitbox();
	for (int i = 0; i < 3; ++i) {
		Hitbox cactus_hb = cactus[i].getHitbox();
		if (isColliding(headdino.x1, headdino.y1, headdino.x2, headdino.y2, cactus_hb.x1, cactus_hb.y1, cactus_hb.x2, cactus_hb.y2)) {
			lose = true;
			return false;
		}
	}
	for (int i = 0; i < 3; ++i) {
		Hitbox cactus_hb = cactus[i].getHitbox();
		if (isColliding(bodydino.x1, bodydino.y1, bodydino.x2, bodydino.y2, cactus_hb.x1, cactus_hb.y1, cactus_hb.x2, cactus_hb.y2)) {
			lose = true;
			return false;
		}
	}
	for (int i = 0; i < 3; ++i) {
		Hitbox cactus_hb = cactus[i].getHitbox();
		if (isColliding(legdino.x1, legdino.y1, legdino.x2, legdino.y2, cactus_hb.x1, cactus_hb.y1, cactus_hb.x2, cactus_hb.y2)) {
			lose = true;
			return false;
		}
	}
	
	return true;
}

bool PlayGame::isColliding(int x1_a, int y1_a, int x2_a, int y2_a, int x1_b, int y1_b, int x2_b, int y2_b)
{
	if (x1_a < x2_b && x2_a > x1_b && y1_a < y2_b && y2_a > y1_b) {
		return true;
	}
	return false;
}

void PlayGame::restart()
{
	lose = false;
	played = false;
	maindino = Dinosaur();
	cactus[0].reset();
	cactus[1].reset();
	cactus[2].reset();
	lev = 0;
}


void PlayGame::test(CClientDC* pdc, CDC* cdc, int x, int y, int t)
{
	CString temp;
	CRect rect(x, y, x + 100,y + 100);
	// Set Pen ( Hem rectangle)
	CPen pen(PS_SOLID, 4, RGB(255, 50, 255));
	CPen* pOldPen = pdc->SelectObject(&pen);
	// Set brush rectangle
	CBrush myBrush(RGB(20, 20, 100));
	CBrush* pOldBrush = pdc->SelectObject(&myBrush);
	temp.Format(_T("T: %d"), t);
	pdc->Rectangle(rect);
	pdc->DrawText(temp, rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_NOCLIP);
	// Set default
	pdc->SelectObject(pOldPen);
	pdc->SelectObject(pOldBrush);
}

void PlayGame::display_change_button(CPoint p, CClientDC* pdc, HDC hdc, CDC* cdc)
{
	if (ismenu) {
		if (Bplay.isMouseOn(p)) {
			Bplay.display_select(pdc, hdc, cdc);
			Sleep(50);
		}
		else {
			Bplay.display(pdc, hdc, cdc);
		}
		return;
	}
	if (isrestart) {
		if (Bplay.isMouseOn(p)) {
			Bplay.display_select(pdc, hdc, cdc);
			Sleep(50);
		}
		else {
			Bplay.display(pdc, hdc, cdc);
		}
		return;
	}
}

bool PlayGame::click_button(UINT nChar, CPoint p, CClientDC* pdc, CWnd* pWnd, HDC hdc, CDC* cdc)
{
	if (ismenu) {
		if (Bplay.isOnClick(nChar, p)) {
			ismenu = false;
			backmain.display(cdc);
			this->displaydino(pdc, cdc);
			Bplay.notEnable();
			return true;
		}
	}
	if (isrestart) {
		if (Bplay.isOnClick(nChar, p)) {
			backmain.display_menu(cdc);
			backmain.display(cdc);
			this->displaydino(pdc, cdc);
			Bplay.notEnable();
			this->restart();
			isrestart = false;
		}
		return true;
	}
	return false;
}

void PlayGame::Animation(CDC* cdc, Background bg)
{
	for (int i = 0; i <= 10; i++)
	{
		// Tính toán kích thước mới của bitmap
		int newWidth = 1960 * (i + 1) / 10;
		int newHeight = 1080 * (i + 1) / 10;

		// Tính toán tọa độ mới để vẽ bitmap từ giữa màn hình
		int newX = 0 - (newWidth - 1960) / 2;
		int newY = 0 - (newHeight - 1080) / 2;

		// Vẽ bitmap với kích thước mới
		bg.displayBG(newX, newY, newWidth, newHeight, cdc);

		// Đợi một khoảng thời gian nhất định
		Sleep(20);
	}

}

void PlayGame::lose_display(CClientDC* pdc, CDC* cdc)
{
	this->Animation(cdc, backmain);
	CRect rect_box(900, 250, 1000, 350);
	CFont font;
	// Set Font + Color
	font.CreatePointFont(300, _T("Times New Roman"));
	CFont* pOldFont = pdc->SelectObject(&font);
	CString point;
	point.Format(_T("POINT: %d"), maindino.getpoint());
	pdc->DrawText(point, rect_box, DT_CENTER | DT_NOCLIP | DT_WORDBREAK);
}

void PlayGame::addpoint(int p)
{
	maindino.addpoint(p);
}
