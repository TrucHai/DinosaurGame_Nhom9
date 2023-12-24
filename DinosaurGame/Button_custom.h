#pragma once
class Button_custom
{
private:
	int x, y;
	CString caption;
	int size;
	bool enable;

public:
	Button_custom();
	Button_custom(int x, int y, int size, CString cap);
	void display(CClientDC* pdc, HDC hdc, CDC* cdc);
	void display_select(CClientDC* pdc, HDC hdc, CDC* cdc);
	bool isMouseOn(CPoint p);
	bool isOnClick(UINT nChar, CPoint p);
	void change(int x, int y, int size, CString cap);
	bool getEnable();
	bool isEnable();
	bool notEnable();
};

