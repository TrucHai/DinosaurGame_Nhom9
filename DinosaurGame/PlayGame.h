#pragma once
#include <ctime>
#include "Background.h"
#include "Dinosaur.h"
#include "Cactus.h"
#include "Button_custom.h"

class PlayGame
{
private:
	Background backmain;
	Dinosaur maindino;
	Cactus cactus[3];
	Button_custom Bplay;
	bool played, lose;
	bool jumping;
	int test1, test2, test3;
	int lev;
public:
	bool ismenu, isrestart;
	PlayGame();
	void display_menu(CClientDC* pdc, HDC hdc, CDC* cdc);
	void create_cactus(CClientDC* pdc, CDC* cdc);
	void displaycactus(CClientDC* pdc, CDC* cdc);
	void movecactus();
	void displaydino(CClientDC* pdc, CDC* cdc);
	void movedino();
	void dinojump();
	bool isjumping();
	bool getlose();
	bool getplayed();
	bool isplayed();
	void displayupdate(CClientDC* pdc, CDC* cdc);
	bool checklose();
	bool isColliding(int x1_a, int y1_a, int x2_a, int y2_a, int x1_b, int y1_b, int x2_b, int y2_b);
	void restart();

	void test(CClientDC* pdc, CDC* cdc, int x, int y, int t);

	void display_change_button(CPoint p, CClientDC* pdc, HDC hdc, CDC* cdc);
	bool click_button(UINT nChar, CPoint p, CClientDC* pdc, CWnd* pWnd, HDC hdc, CDC* cdc);
	void Animation(CDC* cdc, Background bg);
	void lose_display(CClientDC* pdc, CDC* cdc);
	void addpoint(int p);
};

