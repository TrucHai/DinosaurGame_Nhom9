#pragma once
#include "Background.h"
class Cactus
{
private:
	int x, y;
	int width, height;
	int sizebitmap1, sizebitmap2;
	int type;
	Hitbox cactus_hitbox;
	bool exist;
	bool display_hitbox;

public:
	Cactus();
	void Create(int x, int type);
	void display(CDC* cdc);
	void sethitbox();
	void displayhitbox(CClientDC* pdc);
	Hitbox getHitbox();
	bool check_exist();
	void clear(CClientDC* pdc);
	void move();
	void reset();
};

