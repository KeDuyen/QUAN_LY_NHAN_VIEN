#pragma once
#include "Chuan_Hoa.h"
#include "Do_Hoa.h"
#include "Ghi_File.h"

void ThongBaoThanhCong(string s, short x, short y); // Thong bao thao tac thanh cong
void ThongBaoThatBai(string s, short x, short y); // Thong bao thao tac that bai
void ThanhCongCuThem(); // Thanh cong cu, phim nong cho viec them nhan vien
void ChenKhung();
void NoiKhung();
void ThanhCongCuXuat(); // Thanh cong cu, phim nong cho viec xuat nhan vien
void HopThongBao(); // tao hop thong bao
int Search_Info(char info[10], NV pList); // ham tim ma nhan vien
int Insert_Item(NV &pList, int i, nv *nhanvien); // ham them mot nhan vien vao danh sach
int Delete_Item(NV &pList, int i); // ham xoa mot nhan vien trong danh sach
void HoanDoi(nv &p1, nv &p2); // ham hoan doi hai nhan vien
void SortTen(nv array[], int q, int r);
void QuickSortTen(nv array[], int n);
void TachNhanVienSangMang(NV pList, nv array[]);
int ThemNhanVien(NV &pList); // ham them nhan vien
int HieuChinhNhanVien(NV &pList, char manvcu[10], int a); // ham hieu chinh nhan vien
void XuatMotDoan (NV pList, int start, int end);
void ThanhCongCuInDS();
void InDSNhanVien (NV pList);
void XuatNhanVien (NV &pList); // ham xuat nhan vien
void XoaDanhSachNhanVien(NV &pList); // ham xoa danh sach nhan vien

void ThongBaoThanhCong(string s, short x, short y) {
	ShowCur(0);
	BoxThongBao(x,y,34,2,2,0);
	Goto(x+2,y+1);
	SetColor(2,0);
	cout << s;
	Sleep(2000);
	Goto(x,y);
	BoxThongBao(x,y,34,2,0,0);
	SetColor(0,7);
}

void ThongBaoThatBai(string s, short x, short y) {
	ShowCur(0);
	BoxThongBao(x,y,34,2,12,0);
	Goto(x+2,y+1);
	SetColor(12,0);
	cout << s;
	Sleep(2000);
	Goto(x,y);
	BoxThongBao(x,y,34,2,0,0);
	SetColor(0,7);
}

void ThanhCongCuThem() { // Thanh cong cu, phim nong cho viec them nhan vien
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
	cout << "Them nhan vien";
	SetColor(0,7);
}

void ChenKhung() {
	cout << char(218);
	for (int i=0; i<92; i++) {
		if (i == 14 || i == 71 || i == 85) {
			cout << char(194);
		} else {
			cout << char(196);
		}
	}
	cout << char(191); 
	cout << endl;
	cout << char(179) << " MA NHAN VIEN " << char(179) << "                           HO                           " << char(179) << "     TEN     " << char(179) << " PHAI " << char(179) << endl;
	cout << char(179) << "              " << char(179) << "                                                        " << char(179) << "             " << char(179) << "      " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<92; i++) {
		if (i == 14 || i == 71 || i == 85) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
}

void NoiKhung() {
	cout << char(179) << "              " << char(179) << "                                                        " << char(179) << "             " << char(179) << "      " << char(179) << endl;
	cout << char (192);
	for (int i=0; i<92; i++) {
		if (i == 14 || i == 71 || i == 85) {
			cout << char(193);
		} else {
			cout << char(196);
		}
	}
	cout << char (217);
}

void ThanhCongCuXuat() { // Thanh cong cu, phim nong cho viec xuat nhan vien
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
	cout << "F2";
	Goto (69,dem+2);
	SetColor(11,0);
	cout << "Them nhan vien";
	Goto (92,dem+2);
	SetColor(12,0);
	cout << "F3";
	Goto (95,dem+2);
	SetColor(11,0);
	cout << "Tim nhan vien";
	SetColor(0,7);
}

void ThanhCongCuHieuChinh() {
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

void HopThongBao() { // tao hop thong bao
	Goto (107,0);
	cout << "Thong bao";
	BoxThongBao(94,1,34,2,0,0);
	SetColor(0,7);
}

int Search_Info(char info[10], NV pList) { // Ham tim ma nhan vien
	int i;
	for (i=0; i<pList.n; i++) {
		if (strcmp(pList.nodes[i]->MaNv,info) == 0)
			return i;
	}
	return -1;
}

int Insert_Item(NV &pList, int i, nv *nhanvien) { // ham them 1 nhan vien vao danh sach
	for (int j=pList.n-1; j>=i; j--) {
		pList.nodes[j+1]=pList.nodes[j];
	}
	pList.nodes[i] = nhanvien;
	pList.n++;
	return 1;
}

int Delete_Item(NV &pList, int i) {
	if (i<0 || i >= pList.n || pList.n == 0)
		return 0;
	delete pList.nodes[i];
	for (int j=i+1; j<pList.n; j++) {
		pList.nodes[j-1] = pList.nodes[j];
	}
	pList.n--;
	return 1;
}

void HoanDoi(nv &p1, nv &p2) { // ham hoan doi hai nhan vien
	struct nv temp = p1;
	p1 = p2;
	p2 = temp;
}

void SortTen(nv array[], int q, int r) {
	int i = q;
	int j = r;
	nv x = array[(q+r)/2];
	do {
		while (true) {
			if (strcmp(array[i].Ten,x.Ten)<0) {
				i++;
			} 
			else if (strcmp(array[i].Ten,x.Ten)==0) {
				if (strcmp(array[i].Ho,x.Ho)<0) {
					i++;
				}
				else {
					break;
				}
			}
			else if (strcmp(array[i].Ten,x.Ten)>0) {
				break;
			}
		}
		while (true) {
			if (strcmp(array[j].Ten,x.Ten)>0) {
				j--;
			}
			else if (strcmp(array[j].Ten,x.Ten)==0) {
				if (strcmp(array[j].Ho,x.Ho)>0)
					j--;
				else {
					break;
				}
			}
			else if (strcmp(array[j].Ten,x.Ten)<0) {
				break;
			}
		}
		if (i <= j) {
			HoanDoi(array[i],array[j]);
			i++;
			j--;
		}
	} while(i<=j);
	if (q<j) {
		SortTen(array,q,j);
	}
	if (i<r) {
		SortTen(array,i,r);
	}
}

void QuickSortTen(nv array[], int n) {
	SortTen(array,0,n-1);
}

void TachNhanVienSangMang(NV pList, nv array[]) {
	int count = 0;
	for (int i = 0; i<pList.n; i++) {
		array[count] = *pList.nodes[i];
		count++;
	}
}

int ThemNhanVien(NV &pList) { // ham them nhan vien
	char manv[10],ho[50],ten[10],phai[2];
	int temp,temp2,x;
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
	Goto (57,11); cout << "THEM NHAN VIEN";
	SetColor(11,0);
	Goto (32,13); cout << "Ma nhan vien";
	Goto (32,15); cout << "Ho";
	Goto (32,17); cout << "Ten";
	Goto (32,19); cout << "Phai";
	Goto (32,21); cout << "(0: NAM/ 1: NU)";
	Goto (86,21); cout << "ESC: Thoat";
	SetColor(0,7);
	while (true) {
		Goto(46,13);
		if (HamNhapMaNV(manv) == -1) {
			return 0;
		}
		temp = CheckRong(manv);
		while (temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto (46,13);
			if (HamNhapMaNV(manv) == -1) {
				return 0;
			}
			temp = CheckRong(manv);
		}
		temp2 = Search_Info(manv,pList);
		if (temp2 != -1) {
			ThongBaoThatBai("Ma nhan vien bi trung",94,1);
			Goto(46,13);
			for (int i=0;i<10;i++)
				cout << " ";
			ShowCur(1);
		}
		else {
			break;
		}
	}
	Goto (46,15);
	if (HamNhapHo(ho) == -1) {
		return 0;
	}
	XoaKt(ho);
	temp = CheckRong(ho);
	while (temp == 0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto (46,15);
		if (HamNhapHo(ho) == -1) {
			return 0;
		}
		XoaKt(ho);
		temp = CheckRong(ho);
	}
	Goto (46,15);
	for (int i=0; i<50; i++)
		cout << " ";
	Goto (46,15);
	cout << ho;
	Goto (46,17);
	if (HamNhapTen(ten) == -1) {
		return 0;
	}
	temp = CheckRong(ten);
	while (temp == 0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto (46,17);
		if (HamNhapTen(ten) == -1) {
			return 0;
		}
		temp = CheckRong(ten);
	}
	Goto (46,19);
	if (HamNhapPhai(phai) == -1) {
		return 0;
	}
	temp = CheckRong(phai);
	while (temp == 0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(46,19);
		if (HamNhapPhai(phai) == -1) {
			return 0;
		}
		temp = CheckRong(phai);
	}
	if (phai[0] == 48) {
		x = 0;
	}
	else {
		x = 1;
	}
	if (pList.n == MAXLIST) { // kiem tra danh sach da day hay chua
		ThongBaoThatBai("Danh sach da day",94,1);
		return 0;
	}
	else {
		nv *nhanvien = new nv (manv, ho, ten, x);
		if (Insert_Item(pList, pList.n, nhanvien) == 1) {
			ThongBaoThanhCong("Them thanh cong",94,1);
		}
	}
	return 1;
}

int HieuChinhNhanVien(NV &pList, char manvcu[10], int a) { // hieu chinh nhan vien
	ShowCur(1);
	char manv[10],ten[10],ho[50],phai[2];
	int temp,temp2,x,dem = 2;
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
	Goto (57,11); cout << "HIEU CHINH NHAN VIEN";
	SetColor(11,0);
	Goto (32,13); cout << "Ma nhan vien";
	Goto (32,15); cout << "Ho";
	Goto (32,17); cout << "Ten";
	Goto (32,19); cout << "Phai";
	Goto (32,21); cout << "(0: NAM/ 1: NU)";
	Goto (86,21); cout << "ESC: Thoat";
	SetColor(0,7);
	while (true) {
		Goto(46,13);
		if (HamNhapMaNV(manv) == -1) {
			return 0;
		}
		temp = CheckRong(manv);
		while (temp == 0) {
			ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
			ShowCur(1);
			Goto(46,13);
			if (HamNhapMaNV(manv) == -1) {
				return 0;
			}
			temp = CheckRong(manv);
		}
		temp2 = Search_Info(manv,pList);
		if (temp2 != -1 && strcmp(manv,manvcu) != 0) {
			ThongBaoThatBai("Ma nhan vien bi trung",94,1);
			Goto(46,13);
			for (int i=0;i<10;i++)
				cout << " ";
			ShowCur(1);
		}
		else {
			break;
	 	}
	}
	Goto(46,15);
	if (HamNhapHo(ho) == -1) {
		return 0;
	}
	XoaKt(ho);
	temp = CheckRong(ho);
	while (temp == 0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(46,15);
		if (HamNhapHo(ho) == -1) {
			return 0;
		}
		XoaKt(ho);
		temp = CheckRong(ho);
	}
	Goto(46,15);
	for (int i=0; i<50; i++) // xoa ho cu
		cout << " ";
	Goto(46,15);
	cout << ho;
	Goto(46,17);
	if (HamNhapTen(ten) == -1) {
		return 0;
	}
	temp = CheckRong(ten);
	while (temp == 0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(46,17);
		if (HamNhapTen(ten) == -1) {
			return 0;
		}
		temp = CheckRong(ten);
	}
	Goto(46,19);
	if (HamNhapPhai(phai) == -1) {
		return 0;
	}
	temp = CheckRong(phai);
	while (temp==0) {
		ThongBaoThatBai("Khong duoc bo trong thong tin",94,1);
		ShowCur(1);
		Goto(46,19);
		if (HamNhapPhai(phai) == -1) {
			return 0;
		}
		temp = CheckRong(phai);
	}
	if (phai[0] == 48) {
		x = 0;
	}
	else {
		x = 1;
	}
	strcpy(pList.nodes[a]->MaNv,manv);
	strcpy(pList.nodes[a]->Ho,ho);
	strcpy(pList.nodes[a]->Ten,ten);
	pList.nodes[a]->Phai = x;
	ThongBaoThanhCong("Hieu chinh thanh cong",94,1);
	return 1;
}

void XuatMotDoan (NV pList, int start, int end) {
	int dem = 2;
	ChenKhung();
	for (int i = start; i < end; i++) {
		Goto (2,dem);
		cout << pList.nodes[i]->MaNv;
		Goto (17,dem);
		cout << pList.nodes[i]->Ho;
		Goto (74,dem);
		cout << pList.nodes[i]->Ten;
		Goto (88,dem);
		if (pList.nodes[i]->Phai == 0)
			cout << "NAM";
		else cout << "NU";
		cout << endl;
		NoiKhung();
		dem++;
	}
}

void ThanhCongCuInDS()
{
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
	SetColor(0,7);
}

void InDSNhanVien (NV pList) { // Ham in danh sach nhan vien
	int tranght = 1;
	int trangdau = 1;
	int temp,a;
	int sl = pList.n;
	nv array[sl];
	char c,manv[10];
	int trangcuoi;
	if (pList.n != 0) {
		if (pList.n % 20 ==0) {
			trangcuoi = pList.n/20;
		} else {
			trangcuoi = (pList.n/20)+1;
		}
	} else {
		trangcuoi = 1;
	}
	TachNhanVienSangMang(pList,array);
	QuickSortTen(array,sl);
	while (true) {
		system("cls");
		int dem = 2;
		if (pList.n == 0) {
			BoxMenu(55,13,16,2,12,0);
			SetColor(12,0);
			Goto (56,14);
			cout << "Danh sach rong";
			SetColor(0,7);
			getch();
			return;
		}
		ChenKhung();
		Goto (65,24);
		cout << tranght << "/" << trangcuoi;
		ThanhCongCuInDS();
		Goto (0,0);
		if (sl < 20) {
			for (int i = (tranght-1)*20; i < (tranght-1)*20 + sl; i++) {
				Goto (2,dem);
				cout << array[i].MaNv;
				Goto (17,dem);
				cout << array[i].Ho;
				Goto (74,dem);
				cout << array[i].Ten;
				Goto (88,dem);
				if (array[i].Phai == 0)
					cout << "NAM";
				else cout << "NU";
				cout << endl;
				NoiKhung();
				dem++;
			}
		} else {
			for (int i = (tranght-1)*20; i < tranght*20; i++) {
				Goto (2,dem);
				cout << array[i].MaNv;
				Goto (17,dem);
				cout << array[i].Ho;
				Goto (74,dem);
				cout << array[i].Ten;
				Goto (88,dem);
				if (array[i].Phai == 0)
					cout << "NAM";
				else cout << "NU";
				cout << endl;
				NoiKhung();
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
		} else if (c == 27) {
			break;
		}
	}
}

void XuatNhanVien (NV &pList) { // Ham xuat nhan vien
	int trangdau = 1;
	int tranght = 1;
	int temp,dem = 2,a,tempcheck;
	char c,manv[10];
	int sl = pList.n;
	while (true) {
		ShowCur(0);
		system("cls");
		int trangcuoi;
		if (pList.n != 0) {
			if (pList.n % 20 ==0) {
				trangcuoi = pList.n/20;
			} else {
				trangcuoi = (pList.n/20)+1;
			}
		} else {
			trangcuoi = 1;
		}
		HopThongBao();
		Goto (65,24);
		cout << tranght << "/" << trangcuoi;
		ThanhCongCuXuat();
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
							sl = pList.n;
						} else {
							while (true) {
								system("cls");
								ChenKhung();
								HopThongBao();
								ThanhCongCuHieuChinh();
//===== Xuat thong tin cu cua nhan vien
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
										if (HieuChinhNhanVien(pList,manv,a) == 1) {
											tranght = 1;
											sl = pList.n;
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
												if (vitri == 1) { // chi xet truong hop vitri = 1 nghia la co xoa, thi dung ham Delete_Item de xoa nhan vien tai vi tri a, con truong hop 2 thi break nen khong can them vao
													if (pList.nodes[a]->dshd != NULL) {
														ThongBaoThatBai("Nhan vien da lap hoa don",94,1);
														tranght = 1;
														sl = pList.n;
													} else {
														if (Delete_Item(pList,a) == 1) {
															ThongBaoThanhCong("Xoa thanh cong",94,1);
															tranght = 1;
															sl = pList.n;
														}
													}
												} else {
													tranght = 1;
													sl = pList.n;
												}
												break;
											}
										}
										break;
									}
								} else if (c == 27) { // nut ESC 
									tranght = 1;
									sl = pList.n;
									break;
								}
							}
						}
					}
				}
			} else if (c == 60) { // nut F2
				if (ThemNhanVien(pList) == 1) {
					tranght = 1;
					sl = pList.n;
				} else {
					tranght = 1;
					sl = pList.n;
				}
			}
		} else if (c == 27) {
			break;
		}
	}
}

void XoaDanhSachNhanVien(NV &pList) {
	for (int i=0; i<pList.n; i++) {
		delete pList.nodes[i];
	}
	pList.n = 0;
}











