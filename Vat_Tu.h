#pragma once
#include "Ghi_File.h"

void ThanhCongCuThemVT(); // Thanh cong cu, phim nong cho viec them vat tu
void ThanhCongCuXuatVT(); // Thanh cong cu, phim nong cho viec xuat vat tu
void ThanhCongCuHieuChinhVT(); // Thanh cong cu, phim nong cho viec hieu chinh, xoa vat tu
void ThemPhanTu(TREE &t,VatTu x);
void DiTimNodeTheMang(TREE &x,TREE &y);
int Kt_VatTu_TrongCTHD(NV pList, char mavt[10]);
void XoaVatTu(TREE &t,VatTu vt);
int HieuChinhVatTu(TREE &t,VatTu vt2);
TREE Search_MaVT(TREE t, char mavt[10]);
int KiemTraTrungMa(TREE t,VatTu vt);
void GiaiPhongVT(TREE &t);
void ChenKhungVT();
void NoiKhungVT();
int ThemVatTu(TREE &t);
int DemSoVatTu(TREE t);
int TachCayThanhMang(TREE t, VatTu p[], TREE stack[]);
void XuatVatTu(TREE &t, NV pList);
void Quick_Sort(int count, VatTu p[]);
void _Sort(VatTu p[],int q,int r);
void SapXep(TREE t);


void ThanhCongCuThemVT() { // Thanh cong cu, phim nong cho viec them vat tu
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
	cout << "Enter";
	Goto (30,dem+2);
	SetColor(11,0);
	cout << "Them vat tu";
	SetColor(0,7);
}

void ThanhCongCuXuatVT() { // Thanh cong cu, phim nong cho viec xuat vat tu
	BoxThongBao(58,25,26,2,0,0);
	SetColor(0,7);
	Goto(49,26);
	cout << "Ma vat tu";
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
	cout << "F2";
	Goto (69,dem+2);
	SetColor(11,0);
	cout << "Them vat tu";
	Goto (89,dem+2);
	SetColor(12,0);
	cout << "F3";
	Goto (92,dem+2);
	SetColor(11,0);
	cout << "Tim vat tu";
	SetColor(0,7);
}

void ThanhCongCuHieuChinhVT() {
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
	cout << "Hieu chinh";
	Goto (46,dem+2);
	SetColor(12,0);
	cout << "Delete";
	Goto(53,dem+2);
	SetColor(11,0);
	cout << "Xoa";
	SetColor(0,7);
}

void ThemPhanTu(TREE &t,VatTu x) {
	if(t==NULL) {	
		t = new DSVT;
		t->vt = x;
		t->pLeft=NULL;
		t->pRight=NULL;
	} else {
		if(strcmp(t->vt.MAVT,x.MAVT)<0) {
			ThemPhanTu(t->pRight,x);
		} else if(strcmp(t->vt.MAVT,x.MAVT)>0) {
			ThemPhanTu(t->pLeft,x);
		}
	}
}

void DiTimNodeTheMang(TREE &x,TREE &y) {
	if(y->pRight!=NULL) {
		DiTimNodeTheMang(x,y->pRight);
	} else {
		x->vt = y->vt;
		x = y;
		y = y->pLeft;
	}
}

int Kt_VatTu_TrongCTHD(NV pList, char mavt[10]) {
	CTHD l;
	HD k;
	for (int i = 0; i < pList.n; i++) {
		for (k = pList.nodes[i]->dshd; k != NULL; k = k->pNext) {
			for (l = k->DataHD.cthd; l != NULL; l = l->pNext) {
				if (strcmp(l->DataCTHD.MaVT,mavt) == 0) {
					return 1;
				}
			}
		}
	}
	return -1;
}

void XoaVatTu(TREE &t, VatTu vt) {
	if(strcmp(t->vt.MAVT,vt.MAVT)<0) {
		XoaVatTu(t->pRight,vt);
	} else if(strcmp(t->vt.MAVT,vt.MAVT)>0) {
		XoaVatTu(t->pLeft,vt);
	} else if(strcmp(t->vt.MAVT,vt.MAVT)==0) {
		DSVT *x=t;
		if(t->pLeft==NULL) {
			t=t->pRight;
		} else if(t->pRight==NULL) {
			t=t->pLeft;
		} else {
			DiTimNodeTheMang(x,t->pLeft);
		}
		delete x;
	}
}

int HieuChinhVatTu(TREE &t, VatTu vt2) {
	int dem = 2,temp;
	VatTu vt;
	ShowCur(1);
	if(strcmp(t->vt.MAVT,vt2.MAVT)>0) {
		HieuChinhVatTu(t->pLeft,vt2);
	} else if(strcmp(t->vt.MAVT,vt2.MAVT)<0) {
		HieuChinhVatTu(t->pRight,vt2);
	} else if(strcmp(t->vt.MAVT,vt2.MAVT)==0) {
		BoxMenu(30,10,67,13,11,0);
		for (int i = 0; i < 4; i++) {
			Goto (45,13+(i*2));
			for (int j=0; j<51; j++) {
				SetColor(0,0);
				cout << " ";
			}
		}
		SetColor(11,12);
		Goto (57,11); cout << "HIEU CHINH VAT TU";
		SetColor(11,0);
		Goto (32,13); cout << "Ma vat tu";
		Goto (32,15); cout << "Ten";
		Goto (32,17); cout << "Don vi tinh";
		Goto (32,19); cout << "So luong ton";
		Goto (32,21); cout << "(So luong ton la so duong)";
		Goto (86,21); cout << "ESC: Thoat";
		SetColor(0,7);
		Goto(46,19); cout << t->vt.Soluongton;
		Goto(46,13); cout << t->vt.MAVT;
		Goto (46,15);
		if (HamNhapHo(vt.TENVT) == -1) {
			return 0;
		}
		XoaKt(vt.TENVT);
		temp = CheckRong(vt.TENVT);
		while (temp==0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto(46,15);
			if (HamNhapHo(vt.TENVT) == -1) {
				return 0;
			}
			XoaKt(vt.TENVT);
			temp = CheckRong(vt.TENVT);
		}
		Goto(46,15);
		for (int i=0; i<50; i++)
			cout << " ";
		Goto(46,15);
		cout << vt.TENVT;
		Goto(46,17);
		if (HamNhapTen(vt.DVT) == -1) {
			return 0;
		}
		temp = CheckRong(vt.DVT);
		while (temp==0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto(46,17);
			if (HamNhapTen(vt.DVT) == -1) {
				return 0;
			}
			temp = CheckRong(vt.DVT);
		}
		strcpy(t->vt.TENVT,vt.TENVT);
		strcpy(t->vt.DVT,vt.DVT);
		return 1;
	}
}

TREE Search_MaVT(TREE t, char mavt[10])
{
	if (t == NULL) {
		return NULL;
	}
	else if(strcmp(t->vt.MAVT,mavt)>0) {
		if(t->pLeft==NULL) {
			return NULL;
		} else
			Search_MaVT(t->pLeft,mavt);
	} else if(strcmp(t->vt.MAVT,mavt)<0) {
		if(t->pRight==NULL) {
			return NULL;
		} else
			Search_MaVT(t->pRight,mavt);
	} else if(strcmp(t->vt.MAVT,mavt)==0) {
		return t;
	}
}

int KiemTraTrungMa(TREE t,VatTu vt) { 
	while(t!=NULL) {
		if(strcmp(t->vt.MAVT,vt.MAVT)<0) {
			t=t->pRight;
		} else if(strcmp(t->vt.MAVT,vt.MAVT)>0) {
			t=t->pLeft;
		} else {
			return 0;
		}
	}
	return 1;
}

void GiaiPhongVT(TREE &t) {
	if(t==NULL) {
		return;
	}
	GiaiPhongVT(t->pLeft);
	GiaiPhongVT(t->pRight);
	delete t;
}

void ChenKhungVT() {
	cout << char(218);
	for (int i=0; i<92; i++) {
		if (i == 11 || i == 63 || i == 77) {
			cout << char(194);
		} else {
			cout << char(196);
		}
	}
	cout << char(191); 
	cout << endl;
	cout << char(179) << " MA VAT TU " << char(179) << "                    TEN VAT TU                     " << char(179) << " DON VI TINH " << char(179) << " SO LUONG TON " << char(179) << endl;
	cout << char(179) << "           " << char(179) << "                                                   " << char(179) << "             " << char(179) << "              " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<92; i++) {
		if (i == 11 || i == 63 || i == 77) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
}

void NoiKhungVT() {
	cout << char(179) << "           " << char(179) << "                                                   " << char(179) << "             " << char(179) << "              " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<92; i++) {
		if (i == 11 || i == 63 || i == 77) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
} 

int ThemVatTu(TREE &t)
{
	VatTu vt;
	char SLT[11];
	int temp;
	ShowCur(1);
	BoxMenu(30,10,67,13,11,0);
	for (int i = 0; i < 4; i++) {
		Goto (45,13+(i*2));
		for (int j=0; j<51; j++) {
			SetColor(0,0);
			cout << " ";
		}
	}
	ShowCur(1);
	SetColor(11,12);
	Goto (57,11); cout << "THEM VAT TU";
	SetColor(11,0);
	Goto (32,13); cout << "Ma vat tu";
	Goto (32,15); cout << "Ten";
	Goto (32,17); cout << "Don vi tinh";
	Goto (32,19); cout << "So luong ton";
	Goto (32,21); cout << "(So luong ton la so duong)";
	Goto (86,21); cout << "ESC: Thoat";
	SetColor(0,7);
	while (true) {
		Goto(46,13);
		if (HamNhapMaNV(vt.MAVT) == -1) {
			return 0;
		}
		temp = CheckRong(vt.MAVT);
		while (temp==0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto(46,13);
			if (HamNhapMaNV(vt.MAVT) == -1) {
				return 0;
			}
			temp = CheckRong(vt.MAVT);
		}
		if (KiemTraTrungMa(t,vt)) {
			break;
		} else {
			ThongBaoThatBai("Ma vat tu bi trung",94,1);
			Goto(46,13);
			for (int i=0;i<10;i++)
				cout << " ";
			ShowCur(1);
		}
	}
	Goto(46,15);
	if (HamNhapHo(vt.TENVT) == -1) {
		return 0;
	}
	XoaKt(vt.TENVT);
	temp = CheckRong(vt.TENVT);
	while (temp==0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(46,15);
		if (HamNhapHo(vt.TENVT) == -1) {
			return 0;
		}
		XoaKt(vt.TENVT);
		temp = CheckRong(vt.TENVT);
	}
	Goto(46,15);
	for (int i=0; i<50; i++)
		cout << " ";
	Goto(46,15);
	cout << vt.TENVT;
	Goto(46,17);
	if (HamNhapTen(vt.DVT) == -1) {
		return 0;
	}
	temp = CheckRong(vt.DVT);
	while (temp==0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(46,17);
		if (HamNhapTen(vt.DVT) == -1) {
			return 0;
		}
		temp = CheckRong(vt.DVT);
	}
	Goto(46,19);
	vt.Soluongton = HamNhapSLT(SLT);
	if (vt.Soluongton == -1) {
		return 0;
	}
	temp = CheckRong(SLT);
	while (temp == 0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(46,19);
		vt.Soluongton = HamNhapSLT(SLT);
		if (vt.Soluongton == -1) {
			return 0;
		}
		temp = CheckRong(SLT);
	}
	Goto(46,19);
	for (int i=0; i<15; i++)
		cout << " ";
	Goto(46,19); 
	cout << vt.Soluongton;
	ThemPhanTu(t,vt);
	ThongBaoThanhCong("Them thanh cong",94,1);
	return 1;
}

int DemSoVatTu(TREE t)
{
	if(t==NULL)
  		return 0;
  	else {
		return 1 + DemSoVatTu(t->pLeft) + DemSoVatTu(t->pRight);
  	}
}


int TachCayThanhMang(TREE t, VatTu p[], TREE stack[]) {
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
			p[count++] = q->vt;
			q = q->pRight;
		}
		else {
			break;
		}
	} while (true);
	return count;
}

void XuatVatTu(TREE &t, NV pList) {
	int temp,tempcheck;
	int k = DemSoVatTu(t);
	int sl = DemSoVatTu(t);
	char c;
	VatTu vt;
	int tranght = 1;
	int trangdau = 1;
	while (true) {
		system("cls");
		int dem = 2;
		VatTu p[k]; // mang dung de luu tru dia chi cua ten vat tu
		TREE stack[k]; // dua cac nut trong cay nhi phan vao mang tuyen tinh
		int trangcuoi;
		if (k != 0) {
			if (k % 20 ==0) {
				trangcuoi = k/20;
			} else {
				trangcuoi = (k/20)+1;
			}
		} else {
			trangcuoi = 1;
		}
		TachCayThanhMang(t,p,stack);
		ChenKhungVT();
		Goto (65,24);
		cout << tranght << "/" << trangcuoi;
		ThanhCongCuXuatVT();
		HopThongBao();
		ShowCur(0);
		Goto (0,0);
		if (sl < 20) {
			for (int i = (tranght-1)*20; i < (tranght-1)*20 + sl; i++) {
				Goto (2,dem); cout <<p[i].MAVT;
				Goto (14,dem); cout <<p[i].TENVT;
				Goto (66,dem); cout <<p[i].DVT;
				Goto (80,dem); cout <<p[i].Soluongton << endl;
				NoiKhungVT();
				dem++;
			}
		} else {
			for (int i = (tranght-1)*20; i < tranght*20; i++) {
				Goto (2,dem); cout <<p[i].MAVT;
				Goto (14,dem); cout <<p[i].TENVT;
				Goto (66,dem); cout <<p[i].DVT;
				Goto (80,dem); cout <<p[i].Soluongton << endl;
				NoiKhungVT();
				dem++;
			}
		}
		c = getch();
		if (c == 0) {
			c = getch();
			if (c == 60) { // nut F2
				if (ThemVatTu(t) == 1) {
					k++;
					tranght = 1;
					sl = k;
				} else {
					tranght = 1;
					sl = k;
				}
			}
			else if (c == 61) {// nut F3
				ShowCur(1);
				Goto(60,26);
				tempcheck = HamNhapMaNV(vt.MAVT);
				if (tempcheck == -1) {
					tranght = tranght;
					sl = sl;
				} else {
					temp = CheckRong(vt.MAVT);
					while (temp == 0 && tempcheck != -1) {
						ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
						ShowCur(1);
						Goto (60,26);
						tempcheck = HamNhapMaNV(vt.MAVT);
						temp = CheckRong(vt.MAVT);
					}
					if (tempcheck == -1) {
						tranght = tranght;
						sl = sl;
					} else {
						TREE a = Search_MaVT(t,vt.MAVT);
						if (a == NULL) {
							ThongBaoThatBai("Khong tim thay vat tu",94,1);
							tranght = 1;
							sl = k;
						} else {
							while (true) {
								system("cls");
								ChenKhungVT();
								HopThongBao();
								ThanhCongCuHieuChinh();
//===== Xuat thong tin cu cua vat tu
								Goto (2,2); cout << a->vt.MAVT;
								Goto (14,2); cout << a->vt.TENVT;
								Goto (66,2); cout << a->vt.DVT;
								Goto (80,2); cout << a->vt.Soluongton;
								cout << endl;
								NoiKhungVT();
								ShowCur(0);
								c = getch();
								if (c == 0) {
									c = getch();
									if (c == 60) { // nut F2
										if (HieuChinhVatTu(t,vt) == 1) {
											ThongBaoThanhCong("Hieu chinh thanh cong",94,1);
											tranght = 1;
											sl = k;
											break;
										}
									}
								} else if (c == -32) {
									c = getch();
									if (c == 83) { // nut Delete
										int vitri = 1;
										ShowCur(0);
										BoxMenu(50,13,29,3,11,0);
										Goto(52,14);
										SetColor(11,0);
										cout << "Ban co chac chan muon xoa?";
										Goto(55,15);
										cout << "Co";
										Goto(70,15);
										cout << "Khong";
										SetColor(0,7); // set lai mau cu
										while (true) {
											if (vitri == 1) {
												Goto(55,15);
												SetColor(12,0);
												cout << "Co";
												SetColor(0,7);
											}
											if (vitri == 2) {
												Goto(70,15);
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
														Goto(55,15);
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
														Goto(70,15);
														SetColor(11,0);
														cout << "Khong";
														SetColor(0,7);
														vitri--;
													}
												}
											} else if (c == 13) {
												if (vitri == 1) { // chi xet truong hop vitri = 1 nghia la co xoa, thi dung ham XoaVatTu de xoa vat tu, con truong hop 2 thi break nen khong can them vao
													int check = Kt_VatTu_TrongCTHD(pList,vt.MAVT);
													if (check == 1) {
														ThongBaoThatBai("Vat tu da co trong hoa don",94,1);
														tranght = 1;
														sl = k;
													} else {
														XoaVatTu(t,vt);
														k--;
														tranght = 1;
														sl = k;
														ThongBaoThanhCong("Xoa thanh cong",94,1);
													}
												} else {
													tranght = 1;
													sl = k;
												}
												break;
											}
										}
										break;
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
		} else if (c == -32) {
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
		} else if (c == 27) {
			break;
		}
	}
}

void _Sort(VatTu p[],int q,int r)
{
	VatTu temp;
	int i = q;
	int j = r;
	VatTu x = p[(q+r)/2];
	do
	{
		while(strcmp(p[i].TENVT,x.TENVT) < 0)
		i++;
		while(strcmp(p[j].TENVT,x.TENVT) > 0)
		j--;
		if( i <= j)
		{
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			i++;
			j--;
		}
	}while(i <= j);
	if(q < j)
     _Sort(p,q,j);
    if( i < r)
     _Sort(p,i,r);
}

void Quick_Sort(int count, VatTu p[])
{
	_Sort(p,0,count-1);
}

void SapXep(TREE t) {
	int tranght = 1;
	int trangdau = 1;
	VatTu vt;
	int sl = DemSoVatTu(t);
	char c;
	int sp=-1;
	VatTu p[sl]; // mang dung de luu tru dia chi cua ten vat tu
	TREE stack[sl]; // dua cac nut trong cay nhi phan vao mang tuyen tinh
	int trangcuoi;
	if (sl == 0) {
		BoxMenu(55,13,16,2,12,0);
		SetColor(12,0);
		Goto (56,14);
		cout << "Danh sach rong";
		SetColor(0,7);
		getch();
		return;
	}
	if (sl % 20 ==0) {
		trangcuoi = sl/20;
	} else {
		trangcuoi = (sl/20)+1;
	}
	int count = TachCayThanhMang(t,p,stack);
	Quick_Sort(count,p);
	while (true) {
		system("cls");
		int dem = 2;
		ChenKhungVT();
		Goto (65,24);
		cout << tranght << "/" << trangcuoi;
		ThanhCongCuInDS();
		Goto (0,0);
		if (sl < 20) {
			for (int i = (tranght-1)*20; i < (tranght-1)*20 + sl; i++) {
				Goto (2,dem); cout <<p[i].MAVT;
				Goto (14,dem); cout <<p[i].TENVT;
				Goto (66,dem); cout <<p[i].DVT;
				Goto (80,dem); cout <<p[i].Soluongton << endl;
				NoiKhungVT();
				dem++;
			}
		} else {
			for (int i = (tranght-1)*20; i < tranght*20; i++) {
				Goto (2,dem); cout <<p[i].MAVT;
				Goto (14,dem); cout <<p[i].TENVT;
				Goto (66,dem); cout <<p[i].DVT;
				Goto (80,dem); cout <<p[i].Soluongton << endl;
				NoiKhungVT();
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
		} else if (c == 27) { // nut ESC
			break;
		}
	}
}


