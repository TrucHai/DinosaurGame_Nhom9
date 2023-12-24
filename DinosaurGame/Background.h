#pragma once
class Background
{
private:
	int x, y;
	int w, h;

public:
	Background();
	Background(int x, int y);
	void display(CDC* cdc);
	void display_menu(CDC* cdc);
	void displayBG(int x, int y, int w, int h, CDC* cdc);
};

