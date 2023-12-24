#pragma once
#include "Background.h"
class Dinosaur
{
private:
	int x, y;
	int type;
	int width, hight;
	int point;
	Hitbox head_hitbox, body_hitbox, leg_hitbox;
	bool display_hitbox;
	bool control;
	int speed;

public:
	Dinosaur();
	void display(CDC* cdc);
	void changetype();
	void clear(CClientDC* pdc, CDC* cdc);
	void move(CClientDC* pdc, CDC* cdc);
	void jump();
	void update_hitbox();
	void displayhitbox(CClientDC* pdc);
	Hitbox headhitbox();
	Hitbox bodyhitbox();
	Hitbox leghitbox();
	void increase_point();
	void displaypoint(CClientDC* pdc);
	int getpoint();
	int addpoint(int p);
	void setspeed(int s);
	int getspeed();
};

