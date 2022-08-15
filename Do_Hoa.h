#pragma once


void Goto(short posx,short posy); // Ham de con tro nhay toi vi tri chi dinh x,y
void SetColor(int bg_color, int t_color); // Ham set mau nen va mau chu
void BoxMenuHD (short x, short y, short w,short h,int bg_color, int t_color); // ham tao 1 hop thong bao
void BoxMenu(short x, short y, short w,short h,int bg_color, int t_color); // ham tao 1 hop hay 1 lua chon menu
void BoxThongBao(short x, short y, short w,short h,int bg_color, int t_color); // ham tao hop thong bao
void ShowCur(bool CursorVisibility); //  ham an hien con tro nhap nhay



void Goto(short posx,short posy) { // Ham de con tro nhay toi vi tri chi dinh x,y
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = posx;
	position.Y = posy;
	SetConsoleCursorPosition(hStdout, position);
}

void SetColor(int bg_color, int t_color) { // ham set mau
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	int x = bg_color*16 + t_color;
	SetConsoleTextAttribute(color, x);
} 
void BoxMenuHD (short x, short y, short w,short h,int bg_color, int t_color) { // ham tao 1 hop thong bao
	SetColor(bg_color,t_color);
	for (int iy = y+1; iy <= y+h-1; iy++) {
		for (int ix = x+1; ix <= x+w-1; ix++) {
			Goto(ix,iy);
			cout << " ";
		}
	}
	SetColor(0,7);
	if (h<=1 || w<=1 ) return;
	for (int ix = x; ix <= x+w; ix++) {
		Goto (ix,y);
		cout << char(196);
		Goto (ix,y+h);
		cout << char(196);
	}
	for (int iy = y; iy <= y+h; iy++) {
		Goto (x,iy);
		cout << char(179);
		Goto (x+w,iy);
		cout << char(179);
	}
	Goto(x,y);
	cout << char(218);
	Goto(x+w,y);
	cout << char(191);
	Goto (x,y+h);
	cout << char(192);
	Goto (x+w,y+h);
	cout << char(217);
}

void BoxMenu (short x, short y, short w,short h,int bg_color, int t_color) { // ham tao 1 hop
	SetColor(bg_color,t_color);
	for (int iy = y+1; iy <= y+h-1; iy++) {
		for (int ix = x+1; ix <= x+w-1; ix++) {
			Goto(ix,iy);
			cout << " ";
		}
	}
	SetColor(0,14);
	if (h<=1 || w<=1 ) return;
	for (int ix = x; ix <= x+w; ix++) {
		Goto (ix,y);
		cout << char(196);
		Goto (ix,y+h);
		cout << char(196);
	}
	for (int iy = y; iy <= y+h; iy++) {
		Goto (x,iy);
		cout << char(179);
		Goto (x+w,iy);
		cout << char(179);
	}
	Goto(x,y);
	cout << char(218);
	Goto(x+w,y);
	cout << char(191);
	Goto (x,y+h);
	cout << char(192);
	Goto (x+w,y+h);
	cout << char(217);
}

void BoxThongBao (short x, short y, short w,short h,int bg_color, int t_color) { // ham tao 1 hop
	SetColor(bg_color,t_color);
	for (int iy = y+1; iy <= y+h-1; iy++) {
		for (int ix = x+1; ix <= x+w-1; ix++) {
			Goto(ix,iy);
			cout << " ";
		}
	}
	SetColor(0,7);
	if (h<=1 || w<=1 ) return;
	for (int ix = x; ix <= x+w; ix++) {
		Goto (ix,y);
		cout << char(196);
		Goto (ix,y+h);
		cout << char(196);
	}
	for (int iy = y; iy <= y+h; iy++) {
		Goto (x,iy);
		cout << char(179);
		Goto (x+w,iy);
		cout << char(179);
	}
	Goto(x,y);
	cout << char(218);
	Goto(x+w,y);
	cout << char(191);
	Goto (x,y+h);
	cout << char(192);
	Goto (x+w,y+h);
	cout << char(217);
}

void ShowCur(bool CursorVisibility) { //  ham an hien con tro nhap nhay
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}



