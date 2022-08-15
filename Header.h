#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <ctime>
#define MAXLIST 500
using namespace std;
#include <fstream>

struct Date {
	int Ngay;
	int Thang;
	int Nam;
};

//===========================Khai bao du lieu chi tiet hoa don========================
struct DuLieuCTHD {
	char MaVT[10];
	int SoLuong;
	int DonGia;
	int VAT;
};
typedef struct DuLieuCTHD DLCTHD;
//============================Khai bao danh sach chi tiet hoa don==============
struct CT_HOADON {
	DLCTHD DataCTHD;
	CT_HOADON *pNext;
};
typedef struct CT_HOADON* CTHD;

//===========================Khai bao du lieu hoa don==================================
struct DuLieuHD {
	char SoHD[20];
	Date Day;
	char Loai[2];
	long long TongTien = 0;
	CTHD cthd; // con tro tro den chi tiet hoa don tuong ung
	DuLieuHD ()
	{
		cthd = NULL;
	}
};
typedef struct DuLieuHD DLHD;

//=========================Khai bao danh sach hoa don==========================
struct HoaDon {
	DLHD DataHD;
	HoaDon *pNext;
};
typedef struct HoaDon* HD;

//============================Khai bao vat tu=================================
struct VatTu {
	//char
	char MAVT[10];
	char TENVT[50];
	char DVT[10];
	int Soluongton;
};

//============================Khai bao danh sach vat tu=======================
struct DanhSachVatTu {
	VatTu vt;
	DanhSachVatTu *pLeft;
	DanhSachVatTu *pRight;
};
typedef struct DanhSachVatTu DSVT;
typedef DSVT * TREE;
void KhoiTaoDSVT(TREE &t) {
	t=NULL;
}

//=============================Khai bao danh sach nhan vien=====================
struct nv {
	char MaNv[10];
	char Ten[10];
	char Ho[50];
	int Phai;
	HD dshd;
	nv (char manv[10], char ho[50], char ten[10],int phai) {
		strcpy(MaNv,manv);
		strcpy(Ho,ho);
		strcpy(Ten,ten);
		Phai = phai;
		dshd = NULL;
	}
	nv () {
	}
};

struct NhanVien {
	int n;
	struct nv *nodes[MAXLIST];
};
typedef struct NhanVien NV;

//==============================================================================

struct DoanhThuVatTu {
	char MaVT[10];
	char TenVT[50];
	long long sum = 0;
}; 
typedef struct DoanhThuVatTu DTVT;



