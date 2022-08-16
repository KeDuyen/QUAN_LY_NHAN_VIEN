#pragma once

void LuaChonMenuChinh(short x, short y, short w, short h, int bg_color, int t_color, int sl);
void ThanhSangMenuChinh(short x, short y, short w, short h, int bg_color_light, int t_color); // thanh sang se hien len khi ta bam phim
int DiChuyenMenuChinh();
void MenuChinh(NV &pList, TREE &t);




void LuaChonMenuChinh(short x, short y, short w, short h, int bg_color, int t_color, int sl) {
	string str1="\t          QUAN LY VAT TU";
	string str2="1. Danh sach nhan vien.";
	string str3="2. Danh sach vat tu.";
	string str4="3. Danh sach hoa don.";
	string str5="4. Doanh thu";
	string str6="0. Thoat chuong trinh va luu.";
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
		if (i==5)
			cout << str6;
	}
}

void ThanhSangMenuChinh(short x, short y, short w, short h, int bg_color_light, int t_color) { // thanh sang se hien len khi ta bam phim
	string str2="1. Danh sach nhan vien.";
	string str3="2. Danh sach vat tu.";
	string str4="3. Danh sach hoa don.";
	string str5="4. Doanh thu";
	string str6="0. Thoat chuong trinh va luu.";
	SetColor(bg_color_light,t_color);
	for (short iy=y+1; iy<=y+h-1; iy++) {
		for (short ix=x+1; ix<=x+w-1; ix++) {
			Goto(ix,iy);
			cout << " ";
		}
	}
	Goto (x+1,y+1);
	int i=(y-6)/h; // de xac dinh vi tri hien tai (moi hop la y+2, y la so chan, dem di chia cho h, se ra duoc vi tri)
	if (i==1)
		cout << str2;
	if (i==2)
		cout << str3;
	if (i==3)
		cout << str4;
	if (i==4)
		cout << str5;
	if (i==5)
		cout << str6;
}

int DiChuyenMenuChinh() {
	ShowCur(0); // 0 la tat con tro nhap nhay, 1 la hien con tro nhap nhay
	short x=40;
	short y=6;
	short w=50;
	short h=2;
	int t_color=11;
	int bg_color=9;
	int bg_color_light=12;
	int sl=6;
	LuaChonMenuChinh(x,y,w,h,bg_color,t_color,sl);
	ThanhSangMenuChinh(x,y+h,w,h,bg_color_light,t_color); //  vi tri y truyen vao y+h vi hop dau se khong sang
	short xp=x;
	short yp=y+h;
	short xcu=xp;
	short ycu=yp;
	int chucnang;
	bool kt=true;
	do {
		if (kt==true) {
			Goto(xcu,ycu);
			ThanhSangMenuChinh(xcu,ycu,w,h,bg_color,t_color);
			xcu=xp;
			ycu=yp;
			ThanhSangMenuChinh(xp,yp,w,h,bg_color_light,t_color);
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
				ThanhSangMenuChinh(xcu,ycu,w,h,0,7);
				system ("cls");
				break;
			}
		}
	} while (true);
	return chucnang;
}

void MenuChinh(NV &pList, TREE &t) {
	int chucnang;
	do {
		system ("cls");
		chucnang = DiChuyenMenuChinh();
		switch (chucnang) {
			case 1: {
				MenuChinhNhanVien(pList);
				break;
			}
			case 2: {
				MenuChinhVatTu(t,pList);
				break;
			}
			case 3: {
				MenuChinhHoaDon(pList,t);
				break;
			}
			case 4: {
				MenuChinhDoanhThu(t,pList);
				break;
			}
		}
		if (chucnang == 5) {
			int sl = DemSoVatTu(t);
			VatTu p[sl];
			TREE stack[sl];
			int dem = TachCayThanhMang(t,p,stack);
			Ghi_File(p,dem);
			GhiDanhSachNhanVien(pList);
			GiaiPhongVT(t);
			XoaTatCaDSHD_DSCTHD(pList);
			XoaDanhSachNhanVien(pList);
			break;
		}
	} while (true);
}





