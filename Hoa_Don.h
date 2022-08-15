#pragma once



HD Search_SoHD(HD First, char sohd[20]);
int Search_TenNVBangSoHD(NV pList, char sohd[20]);
HD KhoiTaoHD (DLHD x);
void ThemVaoDauHD(HD &First, HD p);
CTHD KhoiTaoCTHD(DLCTHD x);
void ThemVaoDauCTHD(CTHD &First, CTHD p);
int Delete_First(CTHD &p);
int Delete_After(CTHD &p);
int Delete_Info(CTHD &p, char mavt[10]);
void XoaDSCTHD(CTHD &First);
void XoaDSHD(HD &First);
void XoaTatCaDSHD_DSCTHD(NV &pList);
void CapNhatN(DLCTHD y,TREE &t); // cap nhat lai so luong ton khi nhap hoa don loai nhap
void CapNhatX(DLCTHD a,TREE &t); // cap nhat lai so luong ton khi nhap hoa don loai xuat
void ChenKhungHD();
void NoiKhungHD();
HD ThemHoaDonTheoTenNV(NV &pList, int vitri);
CTHD Kt_CTHD(CTHD p, char mavt[10]);
int ThemCTHD_TheoHD( HD &x, TREE &t);
void ThanhCongCuHoaDon();
void ThanhCongCuLapHoaDon();
void ThanhCongCuNhapCTHD(); 
int TachDSCTHD_SangMang(DLCTHD array[], CTHD p);
int DemCTHD(CTHD p);
void TinhTongTien(HD &p);
void CapNhatSLT(HD x, TREE &t);
void NhapHoaDon(NV &pList,TREE &t);
void InHoaDon(NV pList, TREE t);
int DemHD(NV pList);
int TachHD_TrongMotKhoangThoiGian_SangMang(NV pList, DLHD array[],Date x,Date y);
void SortNgayThang(DLHD array[], int q, int r);
void QuickSortNgayThang(DLHD array[], int n);
void ChenKhungDSHD();
void NoiKhungDSHD();
void InHD_TrongMotKhoangThoiGian(NV pList);

HD Search_SoHD(HD First, char sohd[20]) {
	HD p;
	for (p = First; p!=NULL && strcmp(p->DataHD.SoHD,sohd) != 0; p=p->pNext);
	return p;
}

int Search_TenNVBangSoHD(NV pList, char sohd[20]) {
	HD p;
	int i;
	for (i=0; i<pList.n; i++) {
		for (p = pList.nodes[i]->dshd; p!=NULL; p=p->pNext) {
			if (strcmp(p->DataHD.SoHD,sohd) == 0 ) {
				return i;
			}
		}
	}
	return -1;
}

HD KhoiTaoHD (DLHD x) {
	HD p;
	p = new HoaDon;
	p->DataHD = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoDauHD(HD &First, HD p) {
	p->pNext = First;
	First = p;
}

CTHD KhoiTaoCTHD(DLCTHD x) {
	CTHD p;
	p = new CT_HOADON;
	p->DataCTHD = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoDauCTHD(CTHD &First, CTHD p) {
	p->pNext = First;
	First = p;
}

int Delete_First(CTHD &p) {
	CTHD q;
	if (p == NULL) {
		return 0;
	}
	q = p;
	p = q->pNext;
	delete q;
	return 1;
}

int Delete_After(CTHD &p) { 
	CTHD q;
	if ((p == NULL) || p->pNext == NULL) {
		return 0;
	}
	q = p->pNext; // q chi nut can xoa
	p->pNext = q->pNext; // giu lai danh sach dang sau q
	delete q;
	return 1;
}

int Delete_Info(CTHD &p, char mavt[10]) {
	CTHD q = p;
	if (p == NULL) {
		return 0;
	}
	if (strcmp(p->DataCTHD.MaVT,mavt) == 0) {
		Delete_First(p);
		return 1;
	}
	for (q = p; q->pNext != NULL; q=q->pNext) {
		if (strcmp(q->pNext->DataCTHD.MaVT,mavt) == 0) {
			Delete_After(q);
			return 1;
		}
	}
	return 0;	
}

void XoaDSCTHD(CTHD &First) {
	CTHD p;
	while (First!=NULL) {
		p = First;
		First = First->pNext;
		delete p;
	}
}

void XoaDSHD(HD &First) {
	HD p;
	while (First!=NULL) {
		p = First;
		First = First->pNext;
		delete p;
	}
}

void XoaTatCaDSHD_DSCTHD(NV &pList) {
	HD p;
	for (int i=0; i<pList.n; i++) {
		for (p = pList.nodes[i]->dshd; p!=NULL; p=p->pNext) {
			XoaDSCTHD(p->DataHD.cthd);
		}
		XoaDSHD(pList.nodes[i]->dshd);
	}
}

void CapNhatN(DLCTHD y,TREE &t) {
	if(strcmp(y.MaVT,t->vt.MAVT) == 0) {
		t->vt.Soluongton += y.SoLuong;
	} else if(strcmp(y.MaVT,t->vt.MAVT) > 0) {
		CapNhatN(y,t->pRight);
	} else if(strcmp(y.MaVT,t->vt.MAVT) < 0) {
		CapNhatN(y,t->pLeft);
	}
}

void CapNhatX(DLCTHD a,TREE &t) {
	if(strcmp(a.MaVT,t->vt.MAVT) == 0) {
		t->vt.Soluongton = t->vt.Soluongton - a.SoLuong;
	} else if(strcmp(a.MaVT,t->vt.MAVT) > 0) {
		CapNhatX(a,t->pRight);
	} else if(strcmp(a.MaVT,t->vt.MAVT) < 0) {
		CapNhatX(a,t->pLeft);
	}
}

void ChenKhungHD() {
	cout << char(195);
	for (int i=0; i<92; i++) {
		if (i == 11 || i == 56 || i == 69 || i == 78) {
			cout << char(194);
		} else {
			cout << char(196);
		}
	}
	cout << char(180); 
	cout << endl;
	cout << char(179) << " MA VAT TU " << char(179) << "                 TEN VAT TU                 " << char(179) << "  SO LUONG  " << char(179) << "  THUE  " << char(179) << "   DON GIA   " << char(179) << endl;
	cout << char(179) << "           " << char(179) << "                                            " << char(179) << "            " << char(179) << "        " << char(179) << "             " << char(179) << endl;
}

void NoiKhungHD() {
	int dem = 16;
	for (int j = 0; j<4; j++) {
		Goto (12,dem);
		cout << char(179);
		Goto (57,dem);
		cout << char(179);
		Goto (70,dem);
		cout << char(179);
		Goto (79,dem);
		cout << char(179);
		Goto (93,dem);
		cout << char(179);
		dem += 2;
	}
	Goto(0,15);
	for (int j = 0; j<5; j++) {
		cout << char(179) << "           " << char(179) << "                                            " << char(179) << "            " << char(179) << "        " << char(179) << "             " << char(179) << endl;
		if (j<4) {
			cout << char(179) << endl;
		} 
		else {
			cout << char(195);
		}
	}
	for (int i=0; i<92; i++) {
		if (i == 11 || i == 56 || i == 69 || i == 78) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char(180);
	cout << endl;
	cout << char (179);
	cout << " Tong tien: "; 
	for (int i=0; i<80; i++) {
		cout << " ";
	}
	cout << char(179) << endl; 
	cout << char(192);
	for (int i=0; i<92; i++) {
		cout << char(196);
	}
	cout << char(217);
} 

HD ThemHoaDonTheoTenNV(NV &pList, int vitri) {
	DLHD x;
	char ngay[3],thang[3],nam[5],loai[2];
	int temp,temp2;
	BoxMenu(35,8,56,15,11,0);
	for (int i = 0; i < 5; i++) {
		Goto (50,11+(i*2));
		for (int j=0; j<40; j++) {
			SetColor(0,0);
			cout << " ";
		}
	}
	ShowCur(1);
	SetColor(11,12);
	Goto (55,9); cout << "THONG TIN HOA DON";
	SetColor(11,0);
	Goto (37,11); cout << "So hoa don";
	Goto (37,13); cout << "Ngay";
	Goto (37,15); cout << "Thang";
	Goto (37,17); cout << "Nam";
	Goto (37,19); cout << "Loai";
	Goto (37,21); cout << "(N: NHAP/ X: XUAT)";
	Goto (80,21); cout << "ESC: Thoat";
	SetColor(0,7);
	while (true) {
		Goto (51,11);
		if (HamNhapSoHD(x.SoHD) == -1) {
			return NULL;
		}
		temp = CheckRong(x.SoHD);
		while (temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (51,11);
			if (HamNhapSoHD(x.SoHD) == -1) {
				return NULL;
			}
			temp = CheckRong(x.SoHD);
		}
		temp2 = Search_TenNVBangSoHD(pList,x.SoHD);
		if (temp2 != -1) {
			ThongBaoThatBai("So hoa don bi trung",94,1);
			Goto (51,11);
			for (int i=0;i<20;i++)
				cout << " ";
			ShowCur(1);
		}
		else {
			break;
	 	}
	}
	while (true) {
		Goto(51,13); 
		x.Day.Ngay = HamNhapNgay_Thang(ngay);
		if (x.Day.Ngay == -1) {
			return NULL;
		}
		temp = CheckRong(ngay);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (51,13); 
			x.Day.Ngay = HamNhapNgay_Thang(ngay);
			if (x.Day.Ngay == -1) {
				return NULL;
			}
			temp = CheckRong(ngay);
		}
		Goto(51,15);
		x.Day.Thang = HamNhapNgay_Thang(thang);
		if (x.Day.Thang == -1) {
			return NULL;
		}
		temp = CheckRong(thang);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (51,15); 
			x.Day.Thang = HamNhapNgay_Thang(thang);
			if (x.Day.Thang == -1) {
				return NULL;
			}
			temp = CheckRong(thang);
		}
		Goto(51,17);
		x.Day.Nam = HamNhapNam(nam);
		if (x.Day.Nam == -1) {
			return NULL;
		}
		temp = CheckRong(nam);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (51,17); 
			x.Day.Nam = HamNhapNam(nam);
			if (x.Day.Nam == -1) {
				return NULL;
			}
			temp = CheckRong(nam);
		}
		temp2 = Kt_HopLe(x.Day);
		if (temp2 == 0) {
			ThongBaoThatBai("Ngay thang nam khong hop le",94,1);
			Goto(51,13);
			for (int i=0; i<15; i++) 
				cout << " ";
			Goto(51,15);
			for (int i=0; i<15; i++) 
				cout << " ";
			Goto(51,17);
			for (int i=0; i<15; i++) 
				cout << " ";
			ShowCur(1);
		} else {
			break;
		}
	}
	Goto(51,13);
	for (int i=0; i<15; i++)
		cout << " ";
	Goto(51,13); 
	cout << x.Day.Ngay;
	Goto(51,15);
	for (int i=0; i<15; i++)
		cout << " ";
	Goto(51,15); 
	cout << x.Day.Thang;
	Goto(51,17);
	for (int i=0; i<15; i++)
		cout << " ";
	Goto(51,17); 
	cout << x.Day.Nam;
	Goto(51,19);
	if (HamNhapLoai(x.Loai) == -1) {
		return NULL;
	}
	temp = CheckRong(x.Loai);
	while (temp==0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(51,19);
		if (HamNhapLoai(x.Loai) == -1) {
			return NULL;
		}
		temp = CheckRong(x.Loai);
	}
	HD p = KhoiTaoHD(x);
	ThemVaoDauHD(pList.nodes[vitri]->dshd,p);
	ThongBaoThanhCong("Tao hoa don thanh cong",94,1);
	return p;
}

CTHD Kt_CTHD(CTHD p, char mavt[10]) {
	CTHD l;
	for (l = p; l != NULL; l = l->pNext) {
		if (strcmp(l->DataCTHD.MaVT,mavt) == 0) {
			return l;
		}
	}
	return NULL;
}

int ThemCTHD_TheoHD( HD &x, TREE &t) {
	DLCTHD y;
	TREE a;
	int temp,dem = 15;
	char sl[11],dongia[11],thue[11];
	BoxMenu(35,10,56,13,11,0);
	for (int i = 0; i < 4; i++) {
		Goto (50,13+(i*2));
		for (int j=0; j<40; j++) {
			SetColor(0,0);
			cout << " ";
		}
	}
	ShowCur(1);
	SetColor(11,12);
	if (x->DataHD.Loai[0] == 'N') {
		Goto (58,11); cout << "PHIEU NHAP";
	} else {
		Goto (58,11); cout << "PHIEU XUAT";
	}
	SetColor(11,0);
	Goto (37,13); cout << "Ma vat tu";
	Goto (37,15); cout << "So luong";
	Goto (37,17); cout << "Thue(%VAT)";
	Goto (37,19); cout << "Don gia";
	Goto (80,21); cout << "ESC: Thoat";
	SetColor(0,7);
	while (true) {
		Goto (51,13);
		if (HamNhapMaNV(y.MaVT) == -1) {
			return 0;
		}
		temp = CheckRong(y.MaVT);
		while (temp==0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (51,13);
			if (HamNhapMaNV(y.MaVT) == -1) {
				return 0;
			}
			temp = CheckRong(y.MaVT);
		}
		a = Search_MaVT(t,y.MaVT);
		if (a == NULL) {
			ThongBaoThatBai("Khong tim thay vat tu",94,1);
			Goto(51,13);
			for (int i=0;i<10;i++)
				cout << " ";
			ShowCur(1);
		}
		else {
			CTHD z = Kt_CTHD (x->DataHD.cthd,y.MaVT);
			if (z != NULL) {
				ThongBaoThatBai("Vat tu da co trong hoa don",94,1);
				Goto(51,13);
				for (int i=0;i<10;i++)
					cout << " ";
				ShowCur(1);
			} else {
				break;
			}
	 	}
	}
	while (true) {
		Goto(51,15);
		y.SoLuong = HamNhapSLT(sl);
		if (y.SoLuong == -1) {
			return 0;
		}
		temp = CheckRong(sl);
		while (temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto(51,15);
			y.SoLuong = HamNhapSLT(sl);
			if (y.SoLuong == -1) {
				return 0;
			}
			temp = CheckRong(sl);
		}
		if (y.SoLuong == 0) {
			ThongBaoThatBai("So luong phai lon hon khong",94,1);
			Goto(51,15);
			for (int i=0; i<15; i++)
				cout << " ";
			ShowCur(1);
		} else if (x->DataHD.Loai[0] == 'X' && a->vt.Soluongton < y.SoLuong) {
			ThongBaoThatBai("So luong lon hon trong kho",94,1);
			Goto(37,21); 
			SetColor(11,0); 
			cout << "So luong ton hien tai: " << a->vt.Soluongton;
			SetColor(0,7);
			Goto(51,15);
			for (int i=0; i<15; i++)
				cout << " ";
			ShowCur(1);
		} else {
			break;
		}
	}
	Goto(51,15);
	for (int i=0; i<15; i++)
		cout << " ";
	Goto(51,15); 
	cout << y.SoLuong;	
	Goto(51,17);
	y.VAT = HamNhapSLT(thue);
	if (y.VAT == -1) {
		return 0;
	}
	temp = CheckRong(thue);
	while (temp == 0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(51,17);
		y.VAT = HamNhapSLT(thue);
		if (y.VAT == -1) {
			return 0;
		}
		temp = CheckRong(thue);
	}
	Goto(51,17);
	for (int i=0; i<6; i++)
		cout << " ";
	Goto(51,17); 
	cout << y.VAT;	
	Goto(51,19);
	y.DonGia = HamNhapSLT(dongia);
	if (y.DonGia == -1) {
		return 0;
	}
	temp = CheckRong(dongia);
	while (temp == 0 || y.DonGia == 0) {
		if (temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto(51,19);
			y.DonGia = HamNhapSLT(dongia);
			temp = CheckRong(dongia);
		}
		if (y.DonGia == -1) {
			return 0;
		}
		if (y.DonGia == 0) {
			ThongBaoThatBai("Don gia phai lon hon khong",94,1);
			ShowCur(1);
			Goto(51,19);
			for (int i=0; i<15; i++)
				cout << " ";
			Goto(51,19);
			y.DonGia = HamNhapSLT(dongia);
			temp = CheckRong(dongia);
		}
	}
	Goto(51,19);
	for (int i=0; i<15; i++)
		cout << " ";
	Goto(51,19); 
	cout << y.DonGia;
	CTHD k = KhoiTaoCTHD(y);
	ThemVaoDauCTHD(x->DataHD.cthd,k);
	ThongBaoThanhCong("Them thanh cong",94,1);
	return 1;
}

void ThanhCongCuHoaDon() {
	BoxThongBao(58,25,26,2,0,0);
	SetColor(0,7);
	Goto(46,26);
	cout << "Ma nhan vien";
	BoxMenu(0,28,128,4,11,0);
	int dem = 28;
	Goto(5,dem+2);
	SetColor(12,0);
	cout << "ESC";
	Goto(9,dem+2);
	SetColor(11,0);
	cout << "Tro ve";
	Goto (24,dem+2);
	SetColor(12,0);
	cout << char (17);
	Goto (26,dem+2);
	SetColor(11,0);
	cout << "Trang truoc";
	Goto (46,dem+2);
	SetColor(12,0);
	cout << char (16);
	Goto (48,dem+2);
	SetColor (11,0);
	cout << "Trang sau";
	Goto (66,dem+2);
	SetColor(12,0);
	cout << "F3";
	Goto (69,dem+2);
	SetColor(11,0);
	cout << "Tim nhan vien";
	SetColor(0,7);
}

void ThanhCongCuLapHoaDon() {
	BoxMenu(0,28,128,4,11,0);
	int dem = 28;
	Goto(5,dem+2);
	SetColor(12,0);
	cout << "ESC";
	Goto(9,dem+2);
	SetColor(11,0);
	cout << "Tro ve";
	Goto (24,dem+2);
	SetColor(12,0);
	cout << "F2";
	Goto (27,dem+2);
	SetColor(11,0);
	cout << "Lap hoa don";
	SetColor(0,7);
}

void ThanhCongCuNhapCTHD() {
	BoxMenu(0,28,128,4,11,0);
	int dem = 28;
	Goto (5,dem+2);
	SetColor(12,0);
	cout << "F2";
	Goto (8,dem+2);
	SetColor(11,0);
	cout << "Them chi tiet hoa don";
	Goto (38,dem+2);
	SetColor(12,0);
	cout << "Delete";
	Goto (45,dem+2);
	SetColor(11,0);
	cout << "Xoa chi tiet hoa don";
	Goto (74,dem+2);
	SetColor(12,0);
	cout << "F10";
	Goto (78,dem+2);
	SetColor(11,0);
	cout << "Luu";
	SetColor(0,7);
	
}

int TachDSCTHD_SangMang(DLCTHD array[], CTHD p) {
	CTHD l;
	int count = 0;
	for (l = p; l != NULL; l = l->pNext) {
		array[count] = l->DataCTHD;
		count++;
	}
	return count;
}

int DemCTHD(CTHD p) {
	CTHD l;
	int count = 0;
	for (l = p; l != NULL; l = l->pNext) {
		count++;
	}
	return count;
}

void TinhTongTien(HD &p) {
	CTHD l;
	for (l = p->DataHD.cthd; l != NULL; l = l->pNext) {
		p->DataHD.TongTien += round((l->DataCTHD.DonGia*l->DataCTHD.SoLuong)*(1+(float)l->DataCTHD.VAT/100));
	}
}

void CapNhatSLT(HD x, TREE &t) {
	CTHD l;
	if (x->DataHD.Loai[0] == 'N') {
		for (l = x->DataHD.cthd; l != NULL; l = l->pNext) {
			CapNhatN(l->DataCTHD,t);
		}
	} else {
		for (l = x->DataHD.cthd; l != NULL; l = l->pNext) {
			CapNhatX(l->DataCTHD,t);
		}
	}
}

void NhapHoaDon(NV &pList,TREE &t) {
	int tranght = 1;
	HD p;
	int trangdau = 1;
	int temp,dem = 2,a,tempcheck;
	int k = pList.n;
	int sl = pList.n;
	char c,manv[10];
	int trangcuoi;
	while (true) {
		system("cls");
		if (pList.n != 0) {
			if (pList.n % 20 ==0) {
					trangcuoi = pList.n/20;
			} else {
					trangcuoi = (pList.n/20)+1;
			}
		} else {
			trangcuoi = 1;
		}
		ShowCur(0);
		Goto (65,24);
		cout << tranght << "/" << trangcuoi;
		ThanhCongCuHoaDon();
		HopThongBao();
		Goto (0,0);
		if (sl < 20) {
			XuatMotDoan(pList,(tranght-1)*20,(tranght-1)*20 + sl);
		} else {
			XuatMotDoan(pList,(tranght-1)*20,tranght*20);
		}
		c = getch();
		if (c == -32) {
			c = getch();
			if (c == 77) { // mui ten qua phai
				if (tranght == trangcuoi) {
					tranght = tranght;
					sl = sl;
				} else {
					sl -= 20;
					tranght++;
					system ("cls");
				}
			}
			if (c == 75) {
				if (tranght == trangdau) { // mui ten qua trai
					tranght = tranght;
					sl = sl;
				} else {
					sl += 20;
					tranght--;
					system ("cls");
				}
			}
		} else if (c == 0) {
			c = getch();
			if (c == 61) { // nut F3
				ShowCur(1);
				Goto (60,26);
				tempcheck = HamNhapMaNV(manv);
				if (tempcheck == -1) {
					tranght = tranght;
					sl = sl;
				} else {
					temp = CheckRong(manv);
					while (temp==0 && tempcheck != -1) {
						ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
						ShowCur(1);
						Goto (60,26);
						tempcheck = HamNhapMaNV(manv);
						temp = CheckRong(manv);
					}
					if (tempcheck == -1) {
						tranght = tranght;
						sl = sl;
					} else {
						a = Search_Info(manv,pList);
						if (a == -1) {
							ThongBaoThatBai("Khong tim thay nhan vien",94,1);
							tranght = 1;
							sl = k;
						} else {
							while (true) {
								system("cls");
								ChenKhung();
								HopThongBao();
								ThanhCongCuLapHoaDon();
//===== Xuat thong tin cua nhan vien
								Goto (2,dem);
								cout << pList.nodes[a]->MaNv;
								Goto (17,dem);
								cout << pList.nodes[a]->Ho;
								Goto (74,dem);
								cout << pList.nodes[a]->Ten;
								Goto (88,dem);
								if (pList.nodes[a]->Phai == 0)
									cout << "NAM";
								else cout << "NU";
								cout << endl;
								NoiKhung();
								ShowCur(0);
								c = getch();
								if (c == 0) {
									c = getch();
									if (c == 60) { // nut F2
										p = ThemHoaDonTheoTenNV(pList,a);
										if (p != NULL) {
											int tranght1 = 1, trangdau1 = 1;
											int count = 0;
											int sl1 = 0;
											int trangcuoi1;
											int dem1;
											while (true) {
												if (count == 0) {
//													DLCTHD array[count];
													trangcuoi1 = 1;
													system("cls");
													ShowCur(0);
													Goto (65,27);
													cout << tranght1 << "/" << trangcuoi1;
													ThanhCongCuNhapCTHD();
													HopThongBao();
													BoxMenuHD(0,0,93,13,0,0);
													SetColor(0,7);
													Goto (45,1); cout << "HOA DON";
													Goto (2,3); cout << "SO HOA DON:";
													Goto (14,3); cout << p->DataHD.SoHD;
													Goto (2,5); cout << "MA NHAN VIEN:";
													Goto (16,5); cout << pList.nodes[a]->MaNv;
													Goto (2,7); cout << "HO TEN NHAN VIEN:";
													Goto (20,7); cout << pList.nodes[a]->Ho << " " << pList.nodes[a]->Ten;
													Goto (2,9); cout << "NGAY:";
													Goto (8,9); cout << p->DataHD.Day.Ngay;
													Goto (15,9); cout << "THANG:";
													Goto (22,9); cout << p->DataHD.Day.Thang;
													Goto (29,9); cout << "NAM:";
													Goto (34,9); cout << p->DataHD.Day.Nam;
													Goto (2,11); cout << "LOAI:";
													Goto (8,11); 
													if (p->DataHD.Loai[0] == 'N') {
														cout << "NHAP";
													} 
													else {
														cout << "XUAT";
													}
													Goto (0,13);
													ChenKhungHD();
													Goto (0,15);
													NoiKhungHD();
//													TachDSCTHD_SangMang(array,p->DataHD.cthd);
												} else {
													DLCTHD array[count];
													if (count % 9 == 0) {
														trangcuoi1 = count/9;
													} else {
														trangcuoi1 = (count/9)+1;
													}
													int dem = 15;
													system("cls");
													ShowCur(0);
													Goto (65,27);
													cout << tranght1 << "/" << trangcuoi1;
													ThanhCongCuNhapCTHD();
													HopThongBao();
													BoxMenuHD(0,0,93,13,0,0);
													SetColor(0,7);
													Goto (45,1); cout << "HOA DON";
													Goto (2,3); cout << "SO HOA DON:";
													Goto (14,3); cout << p->DataHD.SoHD;
													Goto (2,5); cout << "MA NHAN VIEN:";
													Goto (16,5); cout << pList.nodes[a]->MaNv;
													Goto (2,7); cout << "HO TEN NHAN VIEN:";
													Goto (20,7); cout << pList.nodes[a]->Ho << " " << pList.nodes[a]->Ten;
													Goto (2,9); cout << "NGAY:";
													Goto (8,9); cout << p->DataHD.Day.Ngay;
													Goto (15,9); cout << "THANG:";
													Goto (22,9); cout << p->DataHD.Day.Thang;
													Goto (29,9); cout << "NAM:";
													Goto (34,9); cout << p->DataHD.Day.Nam;
													Goto (2,11); cout << "LOAI:";
													Goto (8,11); 
													if (p->DataHD.Loai[0] == 'N') {
														cout << "NHAP";
													} 
													else {
														cout << "XUAT";
													}
													Goto (0,13);
													ChenKhungHD();
													Goto (0,15);
													NoiKhungHD();
													TachDSCTHD_SangMang(array,p->DataHD.cthd);
													if (sl1 < 9) {
														for (int i = (tranght1-1)*9; i < (tranght1-1)*9 + sl1; i++) {
															Goto (2,dem);
															cout << array[i].MaVT;
															TREE a = Search_MaVT(t,array[i].MaVT);
															Goto (14,dem);
															cout << a->vt.TENVT;
															Goto (59,dem);
															cout << array[i].SoLuong;
															Goto (72,dem);
															cout << array[i].VAT;
															Goto (81,dem);
															cout << array[i].DonGia;
															dem++;
														}
													} else {
														for (int i = (tranght1-1)*9; i < tranght1*9; i++) {
															Goto (2,dem);
															cout << array[i].MaVT;
															TREE a = Search_MaVT(t,array[i].MaVT);
															Goto (14,dem);
															cout << a->vt.TENVT;
															Goto (59,dem);
															cout << array[i].SoLuong;
															Goto (72,dem);
															cout << array[i].VAT;
															Goto (81,dem);
															cout << array[i].DonGia;
															dem++;
														}
													}
												}
												c = getch();
												if (c == -32) {
													c = getch();
													if (c == 77) { // mui ten qua phai
														if (tranght1 == trangcuoi1) {
															tranght1 = tranght1;
															sl1 = sl1;
														} else {
															sl1 -= 9;
															tranght1++;
															system ("cls");
														}
													} else if (c == 75) {
														if (tranght1 == trangdau1) { // mui ten qua trai
															tranght1 = tranght1;
															sl1 = sl1;
														} else {
															sl1 += 9;
															tranght1--;
															system ("cls");
														}
													} else if (c == 83) { // nut Delete
														char mavt[10];
														BoxMenu(35,10,56,7,11,0);
														for (int i = 0; i < 1; i++) {
															Goto (50,13+(i*2));
															for (int j=0; j<40; j++) {
																SetColor(0,0);
																cout << " ";
															}
														}
														ShowCur(1);
														SetColor(11,12);
														Goto (55,11); cout << "XOA CHI TIET HOA DON";
														SetColor(11,0);
														Goto (37,13); cout << "Ma vat tu";
														Goto (80,15); cout << "ESC: Thoat";
														SetColor(0,7);
														while (true) {
															Goto (51,13);
															if (HamNhapMaNV(mavt) == -1) {
																break;
															}
															temp = CheckRong(mavt); 
															while (temp==0) {
																ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
																ShowCur(1);
																Goto (51,13);
																if (HamNhapMaNV(mavt) == -1) {
																	break;
																}
																temp = CheckRong(mavt); 
															}
															CTHD check = Kt_CTHD(p->DataHD.cthd,mavt);
															if (check != NULL) {
																int vitri = 1;
																ShowCur(0);
																BoxMenu(50,18,29,3,11,0);
																Goto(52,19);
																SetColor(11,0);
																cout << "Ban co chac chan muon xoa?";
																Goto(55,20);
																cout << "Co";
																Goto(70,20);
																cout << "Khong";
																SetColor(0,7); // set lai mau cu
																while (true) {
																	if (vitri == 1) {
																		Goto(55,20);
																		SetColor(12,0);
																		cout << "Co";
																		SetColor(0,7);
																	}
																	if (vitri == 2) {
																		Goto(70,20);
																		SetColor(12,0);
																		cout << "Khong";
																		SetColor(0,7);
																	}
																	char c = getch();
																	if (c == -32) {
																		c =  getch();
																		if (c == 77) { // mui ten qua phai
																			if (vitri == 2) {
																				vitri = vitri;
																			} else { // set lai mau vi tri truoc do va tang gia tri vi tri
																				Goto(55,20);
																				SetColor(11,0);
																				cout << "Co";
																				SetColor(0,7);
																				vitri++;
																			}
																		}
																		if (c == 75) { // mui ten qua trai
																			if (vitri == 1) {
																				vitri = vitri;
																			} else { // set lai mau vi tri truoc do va giam gia tri vi tri
																				Goto(70,20);
																				SetColor(11,0);
																				cout << "Khong";
																				SetColor(0,7);
																				vitri--;
																			}
																		}
																	} else if (c == 13) {
																		if (vitri == 1) { // chi xet truong hop vitri = 1 nghia la co xoa, thi dung ham Delete_Info de xoa chi tiet hoa don
																			int m = Delete_Info(p->DataHD.cthd,mavt);
																			if (m == 1) {
																				count--;
																				tranght1 = 1;
																				sl1 = count; 
																				ThongBaoThanhCong("Xoa thanh cong",94,1);
																			}
																		} else{
																			tranght1 = 1;
																			sl1 = count;
																		}
																		break;
																	}
																}
																break;
															} else {
																tranght1 = 1;
																sl1 = count;
																ThongBaoThatBai("Khong tim thay vat tu can xoa",94,1);
																break;
															}
														}
													}
												} else if (c == 0) {
													c = getch();
													if (c == 60) { // nut F2										
														if (ThemCTHD_TheoHD(p,t) == 1) {
															count++;
															tranght1 = 1;
															sl1 = count;
														} else {
															tranght1 = 1;
															sl1 = count; 
														}
													} else if (c == 68) { // nut F10
														if (count == 0) {
															ThongBaoThatBai("Moi ban them chi tiet hoa don",94,1);
														} else {
															CapNhatSLT(p,t);
															TinhTongTien(p);
															Goto(13,25);
															cout << p->DataHD.TongTien;
															ThongBaoThanhCong("Luu hoa don thanh cong",94,1);
															break;
														}
													} 
												}
											}
											break;
										}
									} 
								} else if (c == 27) {
									tranght = 1;
									sl = k;
									break;
								}
							}
						}
					}
				}
			}
		} else if (c == 27) {
			break;
		}
	}
}

void InHoaDon(NV pList, TREE t) {
	CTHD p;
	int temp;
	char sohd[20],c;
	HopThongBao();
	BoxMenu(35,10,56,7,11,0);
	for (int i = 0; i < 1; i++) {
		Goto (50,13+(i*2));
		for (int j=0; j<40; j++) {
			SetColor(0,0);
			cout << " ";
		}
	}
	ShowCur(1);
	SetColor(11,12);
	Goto (58,11); cout << "IN HOA DON";
	SetColor(11,0);
	Goto (37,13); cout << "So hoa don";
	Goto (80,15); cout << "ESC: Thoat";
	SetColor(0,7);
	Goto (51,13);
	if (HamNhapSoHD(sohd) == -1) {
		return;
	}
	temp = CheckRong(sohd);
	while (temp==0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto (51,13);
	    if (HamNhapSoHD(sohd) == -1) {
			return;
		}
		temp = CheckRong(sohd);
	}
	int x = Search_TenNVBangSoHD(pList,sohd);
	if (x == -1) {
		ThongBaoThatBai("Khong tim thay hoa don",94,1);
	} else {
		HD y = Search_SoHD(pList.nodes[x]->dshd,sohd);
		int tranght1 = 1, trangdau1 = 1;
		int sl1 = DemCTHD(y->DataHD.cthd);
		DLCTHD array[sl1];
		TachDSCTHD_SangMang(array,y->DataHD.cthd);
		int trangcuoi1;
		if (sl1 % 9 == 0) { // khong tinh truong hop so luong chi tiet hoa don = 0 vi phai co chi tiet hoa don moi luu hoa don duoc
			trangcuoi1 = sl1/9;
		} else {
			trangcuoi1 = (sl1/9)+1;
		}
		while (true) {
			int dem = 15;
			system("cls");
			ShowCur(0);
			Goto (65,27);
			cout << tranght1 << "/" << trangcuoi1;
			ThanhCongCuInDS();
			BoxMenuHD(0,0,93,13,0,0);
			SetColor(0,7);
			Goto (43,1); cout << "HOA DON";
			Goto (2,3); cout << "SO HOA DON:";
			Goto (14,3); cout << y->DataHD.SoHD;
			Goto (2,5); cout << "MA NHAN VIEN:";
			Goto (16,5); cout << pList.nodes[x]->MaNv;
			Goto (2,7); cout << "HO TEN NHAN VIEN:";
			Goto (20,7); cout << pList.nodes[x]->Ho << " " << pList.nodes[x]->Ten;
			Goto (2,9); cout << "NGAY:";
			Goto (8,9); cout << y->DataHD.Day.Ngay;
			Goto (15,9); cout << "THANG:";
			Goto (22,9); cout << y->DataHD.Day.Thang;
			Goto (29,9); cout << "NAM:";
			Goto (34,9); cout << y->DataHD.Day.Nam;
			Goto (2,11); cout << "LOAI:";
			Goto (8,11); 
			if (y->DataHD.Loai[0] == 'N') {
				cout << "NHAP";
			} 
			else {
				cout << "XUAT";
			}
			Goto (0,13);
			ChenKhungHD();
			Goto (0,15);
			NoiKhungHD();
			if (sl1 < 9) {
				for (int i = (tranght1-1)*9; i < (tranght1-1)*9 + sl1; i++) {
					Goto (2,dem);
					cout << array[i].MaVT;
					TREE a = Search_MaVT(t,array[i].MaVT);
					Goto (14,dem);
					cout << a->vt.TENVT;
					Goto (59,dem);
					cout << array[i].SoLuong;
					Goto (72,dem);
					cout << array[i].VAT;
					Goto (81,dem);
					cout << array[i].DonGia;
					dem++;
				}
			} else {
				for (int i = (tranght1-1)*9; i < tranght1*9; i++) {
					Goto (2,dem);
					cout << array[i].MaVT;
					TREE a = Search_MaVT(t,array[i].MaVT);
					Goto (14,dem);
					cout << a->vt.TENVT;
					Goto (59,dem);
					cout << array[i].SoLuong;
					Goto (72,dem);
					cout << array[i].VAT;
					Goto (81,dem);
					cout << array[i].DonGia;
					dem++;
				}
			}
			Goto(13,25);
			cout << y->DataHD.TongTien;
			c = getch();
			if (c == -32) {
				c = getch();
				if (c == 77) { // mui ten qua phai
					if (tranght1 == trangcuoi1) {
						tranght1 = tranght1;
						sl1 = sl1;
					} else {
						sl1 -= 9;
						tranght1++;
						system ("cls");
					}
				}
				else if (c == 75) {
					if (tranght1 == trangdau1) { // mui ten qua trai
						tranght1 = tranght1;
						sl1 = sl1;
					} else {
						sl1 += 9;
						tranght1--;
						system ("cls");
					}
				}
			} else if (c == 27) {
				break;
			}
		}
	}
}

int DemHD(NV pList) {
	HD l;
	int dem = 0;
	for (int i = 0; i<pList.n; i++) {
		for (l = pList.nodes[i]->dshd; l != NULL; l = l->pNext) {
			dem++;
		}
	}
	return dem;
}

int TachHD_TrongMotKhoangThoiGian_SangMang(NV pList, DLHD array[],Date x,Date y) {
	HD p;
	int count = 0;
	for (int i = 0; i<pList.n; i++) {
		for (p = pList.nodes[i]->dshd; p != NULL; p = p->pNext) {
			if (SoSanh(p->DataHD.Day,x) >=0 && SoSanh(p->DataHD.Day,y) <= 0)
			{
				array[count] = p->DataHD;
				count++;
			}
		}
	}
	return count;
}

void SortNgayThang(DLHD array[], int q, int r) {
	int i = q;
	int j = r;
	DLHD x = array[(q+r)/2];
	do {
		while (SoSanh(x.Day,array[i].Day) == 1) {
			i++;
		}
		while (SoSanh(x.Day,array[j].Day) == -1) {
			j--;
		}
		if (i<=j) {
			DLHD temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	} while (i<=j);
	if (q<j) {
		SortNgayThang(array,q,j);
	}
	if (i<r) {
		SortNgayThang(array,i,r);
	}
}
void QuickSortNgayThang(DLHD array[], int n) {
	SortNgayThang(array,0,n-1);
}

void ChenKhungDSHD() {
	cout << char(195);
	for (int i=0; i<127; i++) {
		if (i == 22 || i == 35 || i == 50 || i == 109) {
			cout << char(194);
		} else {
			cout << char(196);
		}
	}
	cout << char(180); 
	cout << endl;
	cout << char(179) << "      SO HOA DON      " << char(179) << "  NGAY LAP  " << char(179) << " LOAI HOA DON " << char(179) << "                      HO TEN NHAN VIEN                    " << char(179) << " TRI GIA HOA DON " << char(179) << endl;
	cout << char(179) << "                      " << char(179) << "            " << char(179) << "              " << char(179) << "                                                          " << char(179) << "                 " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<127; i++) {
		if (i == 22 || i == 35 || i == 50 || i == 109) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
}

void NoiKhungDSHD() {
	cout << char(179) << "                      " << char(179) << "            " << char(179) << "              " << char(179) << "                                                          " << char(179) << "                 " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<127; i++) {
		if (i == 22 || i == 35 || i == 50 || i == 109) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char(217);
} 

void InHD_TrongMotKhoangThoiGian(NV pList) {
	Date x,y;
	int temp,temp2;
	int k = DemHD(pList);
	DLHD array[k];
	char ngay[3],thang[3],nam[5],c;
	HopThongBao();
	BoxMenu(35,10,56,9,11,0);
	Goto (50,13); cout << "    ";
	Goto (63,13); cout << "    ";
	Goto (76,13); cout << "      ";
	Goto (50,15); cout << "    ";
	Goto (63,15); cout << "    ";
	Goto (76,15); cout << "      ";
	ShowCur(1);
	SetColor(11,12);
	Goto (43,11); cout << "LIET KE CAC HOA DON TRONG KHOANG THOI GIAN";
	SetColor(11,0);
	Goto (37,13); cout << "Tu ngay";
	Goto (37,15); cout << "Den ngay";
	Goto (80,17); cout << "ESC: Thoat";
	SetColor(0,7);
// nhap ngay x
	while (true) {
		Goto(51,13); 
		x.Ngay = HamNhapNgay_Thang(ngay);
		if (x.Ngay == -1) {
			return;
		}
		temp = CheckRong(ngay);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (51,13); 
			x.Ngay = HamNhapNgay_Thang(ngay);
			if (x.Ngay == -1) {
				return;
			}
			temp = CheckRong(ngay);
		}
		Goto(64,13);
		x.Thang = HamNhapNgay_Thang(thang);
		if (x.Thang == -1) {
			return;
		}
		temp = CheckRong(thang);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (64,13); 
			x.Thang = HamNhapNgay_Thang(thang);
			if (x.Thang == -1) {
				return;
			}
			temp = CheckRong(thang);
		}
		Goto(77,13);
		x.Nam = HamNhapNam(nam);
		if (x.Nam == -1) {
			return;
		}
		temp = CheckRong(nam);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (77,13); 
			x.Nam = HamNhapNam(nam);
			if (x.Nam == -1) {
				return;
			}
			temp = CheckRong(nam);
		}
		temp2 = Kt_HopLe(x);
		if (temp2 == 0) {
			ThongBaoThatBai("Ngay thang nam khong hop le",94,1);
			Goto(50,13);
			for (int i=0; i<4; i++) 
				cout << " ";
			Goto(63,13);
			for (int i=0; i<4; i++) 
				cout << " ";
			Goto(76,13);
			for (int i=0; i<6; i++) 
				cout << " ";
			ShowCur(1);
		} else {
			break;
		}
	}
	Goto(50,13);
	for (int i=0; i<4; i++)
		cout << " ";
	Goto(51,13); 
	cout << x.Ngay;
	Goto(63,13);
	for (int i=0; i<4; i++)
		cout << " ";
	Goto(64,13); 
	cout << x.Thang;
	Goto(76,13);
	for (int i=0; i<6; i++)
		cout << " ";
	Goto(77,13); 
	cout << x.Nam;
// nhap ngay y
	while (true) {
		Goto(51,15); 
		y.Ngay = HamNhapNgay_Thang(ngay);
		if (y.Ngay == -1) {
			return;
		}
		temp = CheckRong(ngay);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (51,15); 
			y.Ngay = HamNhapNgay_Thang(ngay);
			if (y.Ngay == -1) {
				return;
			}
			temp = CheckRong(ngay);
		}
		Goto(64,15);
		y.Thang = HamNhapNgay_Thang(thang);
		if (y.Thang == -1) {
			return;
		}
		temp = CheckRong(thang);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (64,15); 
			y.Thang = HamNhapNgay_Thang(thang);
			if (y.Thang == -1) {
				return;
			}
			temp = CheckRong(thang);
		}
		Goto(77,15);
		y.Nam = HamNhapNam(nam);
		if (y.Nam == -1) {
			return;
		}
		temp = CheckRong(nam);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (77,15); 
			y.Nam = HamNhapNam(nam);
			if (y.Nam == -1) {
				return;
			}
			temp = CheckRong(nam);
		}
		temp2 = Kt_HopLe(y);
		if (temp2 == 0 || SoSanh(x,y) == 1) {
			ThongBaoThatBai("Ngay thang nam khong hop le",94,1);
			Goto(50,15);
			for (int i=0; i<4; i++) 
				cout << " ";
			Goto(63,15);
			for (int i=0; i<4; i++) 
				cout << " ";
			Goto(76,15);
			for (int i=0; i<6; i++) 
				cout << " ";
			ShowCur(1);
		} else {
			break;
		}
	}
	Goto(50,15);
	for (int i=0; i<4; i++)
		cout << " ";
	Goto(51,15); 
	cout << y.Ngay;
	Goto(63,15);
	for (int i=0; i<4; i++)
		cout << " ";
	Goto(64,15); 
	cout << y.Thang;
	Goto(76,15);
	for (int i=0; i<6; i++)
		cout << " ";
	Goto(77,15); 
	cout << y.Nam;
	ShowCur(0);
	int sl = TachHD_TrongMotKhoangThoiGian_SangMang(pList,array,x,y);
	QuickSortNgayThang(array,sl);
	if (sl == 0) {
		system("cls");
		BoxMenu(50,13,35,3,12,0);
		SetColor(12,0);
		Goto (52,14);
		cout << "Khong co hoa don duoc lap trong";
		Goto (58,15);
		cout << "khoang thoi gian nay";
		SetColor(0,7);
		getch();
		return;
	}
	int tranght = 1;
	int trangdau = 1;
	int trangcuoi;
	if (sl % 16 ==0) {
		trangcuoi = sl/16;
	} else {
		trangcuoi = (sl/16)+1;
	}
	while (true) {
		system("cls");
		int dem = 6;
		ThanhCongCuInDS();
		Goto (65,24);
		cout << tranght << "/" << trangcuoi;
		BoxMenuHD(0,0,128,4,0,0);
		Goto(0,4);
		ChenKhungDSHD();
		Goto (43,1); cout << "BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN";
		Goto (45,3); cout << "Tu ngay: ";
		Goto (70,3); cout << "Den ngay: ";
		Goto (54,3); cout << x.Ngay << "/" << x.Thang << "/" << x.Nam;
		Goto (80,3); cout << y.Ngay << "/" << y.Thang << "/" << y.Nam;
		if (sl < 16) {
			for (int i = (tranght-1)*16; i < (tranght-1)*16 + sl; i++) {
				Goto (2,dem); cout << array[i].SoHD;
				Goto (25,dem); cout << array[i].Day.Ngay << "/" << array[i].Day.Thang << "/" << array[i].Day.Nam;
				Goto (38,dem); 
				if (array[i].Loai[0] == 'N') {
					cout << "NHAP";
				} else {
					cout << "XUAT";
				}
				Goto (53,dem);
				int z = Search_TenNVBangSoHD(pList,array[i].SoHD);
				cout << pList.nodes[z]->Ho << " " << pList.nodes[z]->Ten;
				Goto (112,dem); cout << array[i].TongTien;
				cout << endl;
				NoiKhungDSHD();	
				dem++;
			}
		} else {
			for (int i = (tranght-1)*16; i < tranght*16; i++) {
				Goto (2,dem); cout << array[i].SoHD;
				Goto (25,dem); cout << array[i].Day.Ngay << "/" << array[i].Day.Thang << "/" << array[i].Day.Nam;
				Goto (38,dem); 
				if (array[i].Loai[0] == 'N') {
					cout << "NHAP";
				} else {
					cout << "XUAT";
				}
				Goto (53,dem);
				int z = Search_TenNVBangSoHD(pList,array[i].SoHD);
				cout << pList.nodes[z]->Ho << " " << pList.nodes[z]->Ten;
				Goto (112,dem); cout << array[i].TongTien;
				cout << endl;
				NoiKhungDSHD();	
				dem++;
			}
		}
		c = getch();
		if (c == -32) {
			c = getch();
			if (c == 77) { // mui ten qua phai
				if (tranght == trangcuoi) {
					tranght = tranght;
					sl = sl;
				} else {
					sl -= 16;
					tranght++;
					system ("cls");
				}
			}
			if (c == 75) {
				if (tranght == trangdau) { // mui ten qua trai
					tranght = tranght;
					sl = sl;
				} else {
					sl += 16;
					tranght--;
					system ("cls");
				}
			}
		}
		else if (c == 27) {
			break;
		}
	}
}










