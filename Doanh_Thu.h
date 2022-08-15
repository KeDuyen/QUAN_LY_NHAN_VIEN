#pragma once

void ChenKhung10VT();
void NoiKhung10VT();
int TachVatTu_SangMangDT(TREE t, DTVT p[], TREE stack[]);
void TinhDoanhThuVTNhap_TrongMotKhoangThoiGian(NV pList, DTVT array[], int count, Date x, Date y);
void SortDT(DTVT array[], int q, int r);
void QuickSortDT(DTVT array[], int count);
void InVT_TrongMotKhoangThoiGian(NV pList, TREE t);
void ChenKhungDT();
void NoiKhungDT();
void TinhDoanhThuTrongNam(NV pList, long long DT[], int nam);
void InDT_TrongNam(NV pList);



void ChenKhung10VT() {
	cout << char(195);
	for (int i=0; i<79; i++) {
		if (i == 11 || i == 63) {
			cout << char(194);
		} else {
			cout << char(196);
		}
	}
	cout << char(180); 
	cout << endl;
	cout << char(179) << " MA VAT TU " << char(179) << "                    TEN VAT TU                     " << char(179) << "   DOANH THU   " << char(179) << endl;
	cout << char(179) << "           " << char(179) << "                                                   " << char(179) << "               " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<79; i++) {
		if (i == 11 || i == 63) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
}

void NoiKhung10VT() {
	cout << char(179) << "           " << char(179) << "                                                   " << char(179) << "               " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<79; i++) {
		if (i == 11 || i == 63) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
}

int TachVatTu_SangMangDT(TREE t, DTVT p[], TREE stack[]) {
	int count = 0;
	int sp=-1; // Khoi tao Stack rong
	TREE q = t;
	do {
		while (q!=NULL) {
			stack[++sp] = q;
			q = q->pLeft;
		}
		if (sp != -1) {
			q = stack[sp--];
			strcpy(p[count].MaVT,q->vt.MAVT);
			strcpy(p[count].TenVT,q->vt.TENVT);
			count++;
			q = q->pRight;
		}
		else {
			break;
		}
	} while (true);
	return count;
}

void TinhDoanhThuVTNhap_TrongMotKhoangThoiGian(NV pList, DTVT array[],int count, Date x,Date y) {
	HD p;
	CTHD l;
	for (int i = 0; i<pList.n; i++) {
		for (p = pList.nodes[i]->dshd; p != NULL; p = p->pNext) {
			if (SoSanh(p->DataHD.Day,x) >=0 && SoSanh(p->DataHD.Day,y) <= 0) {
				if (p->DataHD.Loai[0] == 'X') {
					for (l = p->DataHD.cthd; l != NULL; l = l->pNext) {
						for (int i = 0; i<count; i++) {
							if (strcmp(array[i].MaVT,l->DataCTHD.MaVT) == 0) {
								array[i].sum += round((l->DataCTHD.DonGia*l->DataCTHD.SoLuong)*(1+(float)l->DataCTHD.VAT/100));
							}
						}
					}
				}
			}
		}
	}
}

void SortDT(DTVT array[], int q, int r) {
	int i = q;
	int j = r;
	DTVT x = array[(q+r)/2],temp;
	do {
		while (array[i].sum > x.sum) 
			i++;
		while (array[j].sum < x.sum) 
			j--;
		if (i<=j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	} while (i<=j);
	if (q<j) {
		SortDT(array,q,j);
	}
	if (i<r) {
		SortDT(array,i,r);
	}
}

void QuickSortDT(DTVT array[], int count) {
	SortDT(array,0,count-1);
}

void InVT_TrongMotKhoangThoiGian(NV pList, TREE t) {
	Date x,y;
	int temp,temp2;
	int k = DemSoVatTu(t);
	TREE stack[k];
	DTVT array[k];
	char ngay[3],thang[3],nam[5],c;
	HopThongBao();
	BoxMenu(35,10,54,9,11,0);
	Goto (50,13); cout << "    ";
	Goto (63,13); cout << "    ";
	Goto (76,13); cout << "      ";
	Goto (50,15); cout << "    ";
	Goto (63,15); cout << "    ";
	Goto (76,15); cout << "      ";
	ShowCur(1);
	SetColor(11,12);
	Goto (37,11); cout << "DOANH THU 10 VAT TU CAO NHAT TRONG KHOANG THOI GIAN";
	SetColor(11,0);
	Goto (37,13); cout << "Tu ngay";
	Goto (37,15); cout << "Den ngay";
	Goto (78,17); cout << "ESC: Thoat";
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
	int sl = TachVatTu_SangMangDT(t,array,stack);
	TinhDoanhThuVTNhap_TrongMotKhoangThoiGian(pList,array,sl,x,y);
	QuickSortDT(array,sl);
	while (true) {
		system("cls");
		int dem = 6;
		ThanhCongCuInDS();
		Goto (65,24);
		cout << 1 << "/" << 1;
		BoxMenuHD(0,0,80,4,0,0);
		Goto(0,4);
		ChenKhung10VT();
		Goto (6,1); cout << "BANG LIET KE 10 VAT TU CO DOANH THU CAO NHAT TRONG KHOANG THOI GIAN";
		Goto (17,3); cout << "Tu ngay: ";
		Goto (42,3); cout << "Den ngay: ";
		Goto (26,3); cout << x.Ngay << "/" << x.Thang << "/" << x.Nam;
		Goto (52,3); cout << y.Ngay << "/" << y.Thang << "/" << y.Nam;
		if (sl < 10) {
			for (int i = 0; i < sl; i++) {
				Goto (2,dem); cout << array[i].MaVT;
				Goto (14,dem); cout << array[i].TenVT;
				Goto (66,dem); cout << array[i].sum;
				cout << endl;
				NoiKhung10VT();	
				dem++;
			}
		} else {
			for (int i = 0; i < 10; i++) {
				Goto (2,dem); cout << array[i].MaVT;
				Goto (14,dem); cout << array[i].TenVT;
				Goto (66,dem); cout << array[i].sum;
				cout << endl;
				NoiKhung10VT();	
				dem++;
			}
		}
		c = getch();
		if (c == 27) {
			break;
		}
	}
}

void ChenKhungDT() {
	cout << char(195);
	for (int i=0; i<35; i++) {
		if (i == 11) {
			cout << char(194);
		} else {
			cout << char(196);
		}
	}
	cout << char(180); 
	cout << endl;
	cout << char(179) << "   THANG   " << char(179) << "       DOANH THU       " << char(179) << endl;
	cout << char(179) << "           " << char(179) << "                       " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<35; i++) {
		if (i == 11) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
}

void NoiKhungDT() {
	cout << char(179) << "           " << char(179) << "                       " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<35; i++) {
		if (i == 11) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
}

void TinhDoanhThuTrongNam(NV pList, long long DT[], int nam) {
	HD p;
	CTHD l;
	for (int i = 0; i<pList.n; i++) {
		for (p = pList.nodes[i]->dshd; p != NULL; p = p->pNext) {
			if (p->DataHD.Day.Nam == nam) {
				if (p->DataHD.Loai[0] == 'X') {
					DT[p->DataHD.Day.Thang] += p->DataHD.TongTien;
				}
			}
		}
	}
}

void InDT_TrongNam(NV pList) {
	int NAM,temp;
	char nam[5],c;
	HopThongBao();
	time_t hientai = time(0); 
	tm *ht = localtime(&hientai); 
	int namht = 1900 + ht->tm_year;
	BoxMenu(43,10,48,7,11,0);
	for (int i = 0; i < 1; i++) {
		Goto (50,13+(i*2));
		for (int j=0; j<40; j++) {
			SetColor(0,0);
			cout << " ";
		}
	}
	ShowCur(1);
	SetColor(11,12);
	Goto (58,11); cout << "DOANH THU TRONG NAM";
	SetColor(11,0);
	Goto (45,13); cout << "Nam";
	Goto (80,15); cout << "ESC: Thoat";
	SetColor(0,7);
	Goto(51,13);
	while (true) {
		Goto(51,13);
		NAM = HamNhapNam(nam);
		if (NAM == -1) {
			return;
		}
		temp = CheckRong(nam);
		while(temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (51,13); 
			NAM = HamNhapNam(nam);
			if (NAM == -1) {
				return;
			}
			temp = CheckRong(nam);
		}
		if (NAM > namht) {
			ThongBaoThatBai("Nam khong hop le",94,1);
			Goto(51,13);
			for (int i = 0; i<15; i++)
				cout << " ";
			ShowCur(1);
		} else {
			break;
		}
	}
	long long DT[12];
	for (int i = 1; i <= 12; i++)
		DT[i] = 0;
	TinhDoanhThuTrongNam(pList,DT,NAM);
	while (true) {
		system("cls");
		ShowCur(0);
		int dem = 4;
		ThanhCongCuInDS();
		Goto (65,24);
		cout << 1 << "/" << 1;
		BoxMenuHD(0,0,36,2,0,0);
		Goto(0,2);
		ChenKhungDT();
		Goto (2,1); cout << "BANG THONG KE DOANH THU NAM ";
		Goto (30,1); cout << NAM;
		for (int i = 1; i <= 12; i++) {
			Goto (2,dem); cout << i;
			Goto (14,dem); cout << DT[i];
			cout << endl;
			NoiKhungDT();	
			dem++;
		}
		c = getch();
		if (c == 27) {
			break;
		}
	}
}








