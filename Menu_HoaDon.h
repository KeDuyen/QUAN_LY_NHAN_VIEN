#pragma once
#include "Ghi_File.h"

void LuaChonMenuHoaDon(short x, short y, short w, short h, int bg_color, int t_color, int sl);
void ThanhSangMenuHoaDon(short x, short y, short w, short h, int bg_color_light, int t_color); // thanh sang se hien len khi ta bam phim
int DiChuyenMenuHoaDon();
void MenuChinhHoaDon(NV &pList, TREE &t);


void LuaChonMenuHoaDon(short x, short y, short w, short h, int bg_color, int t_color, int sl) {
	string str1="\t          	HOA DON";
	string str2="1. Lap hoa don.";
	string str3="2. In hoa don.";
	string str4="3. In hoa don trong khoang thoi gian.";
	string str5="0. Tro ve menu chinh.";
	for (int i = 0; i < sl; i++) {
		BoxMenu(x,y+(i*h),w,h,bg_color,t_color);
		if (i!=0) {
			Goto (x,y+(i*2));
			cout << char(195);
			Goto (x+w,y+(i*2));
			cout << char(180);
		}
	}
	SetColor(bg_color,t_color);
	for (int i=0; i<sl; i++) {
		Goto (x+1,y+h*i+1);
		if (i==0)
			cout << str1;
		if (i==1)
			cout << str2;
		if (i==2)
			cout << str3;
		if (i==3)
			cout << str4;
		if (i==4)
			cout << str5;
	}
}

void ThanhSangMenuHoaDon(short x, short y, short w, short h, int bg_color_light, int t_color) { // thanh sang se hien len khi ta bam phim
	string str1="1. Lap hoa don.";
	string str2="2. In hoa don.";
	string str3="3. In hoa don trong khoang thoi gian.";
	string str4="0. Tro ve menu chinh.";
	SetColor(bg_color_light,t_color);
	for (short iy=y+1; iy<=y+h-1; iy++) {
		for (short ix=x+1; ix<=x+w-1; ix++) {
			Goto(ix,iy);
			cout << " ";
		}
	}
	Goto (x+1,y+1);
	int i=(y-6)/h; // de xac dinh vi tri hien tai (moi hop la y+2, y+1 la so chan, dem di chia cho h, se ra duoc vi tri)
	if (i==1)
		cout << str1;
	if (i==2)
		cout << str2;
	if (i==3)
		cout << str3;
	if (i==4)
		cout << str4;
}

int DiChuyenMenuHoaDon() {
	ShowCur(0); // 0 la tat con tro nhap nhay, 1 la hien con tro nhap nhay
	short x=40;
	short y=6;
	short w=50;
	short h=2;
	int t_color=11;
	int bg_color=9;
	int bg_color_light=12;
	int sl=5;
	LuaChonMenuHoaDon(x,y,w,h,bg_color,t_color,sl);
	ThanhSangMenuHoaDon(x,y+h,w,h,bg_color_light,t_color);
	short xp=x;
	short yp=y+h;
	short xcu=xp;
	short ycu=yp;
	int chucnang;
	bool kt=true;
	do {
		if (kt==true) {
			Goto(xcu,ycu);
			ThanhSangMenuHoaDon(xcu,ycu,w,h,bg_color,t_color);
			xcu=xp;
			ycu=yp;
			ThanhSangMenuHoaDon(xp,yp,w,h,bg_color_light,t_color);
			kt=false;
		}
		if (kbhit()) {
			char c=getch();
			if (c==-32) {
				kt=true;
				c=getch();
				if (c==72) {
					if (yp!=y+h)
						yp-=2;
					else {
						yp=y+h*(sl-1);
					}
				} else if (c==80) {
					if (yp!=y+h*(sl-1))
						yp+=2;
					else {
						yp=y+h;
					}
				}
			} else if (c==13) {
				chucnang=(yp-6)/h;
				Goto(xcu,ycu);
				ThanhSangMenuHoaDon(xcu,ycu,w,h,0,7);
				system ("cls");
				break;
			}
		}
	} while (true);
	return chucnang;
}

void MenuChinhHoaDon(NV &pList, TREE &t) {
	int chucnang;
	do {
		system ("cls");
		chucnang = DiChuyenMenuHoaDon();
		switch (chucnang) {
			case 1: {
				ShowCur(1); // hien con tro nhap nhay
				NhapHoaDon(pList,t);
				break;
			}
			case 2: {
				InHoaDon(pList,t);
				break;
			}
			case 3: {
				InHD_TrongMotKhoangThoiGian(pList);
				break;
			}
		}
		if (chucnang == 4) {
			break;
		}
	} while (true);
}

