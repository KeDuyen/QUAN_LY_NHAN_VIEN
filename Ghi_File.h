#pragma once

void GhiMotNhanVien(ofstream &fileout, nv *x); // ham ghi mot nhan vien vao file
void GhiDanhSachNhanVien(NV pList); // ham ghi danh sach nhan vien vao file
void Ghi_File(VatTu p[], int count); // ham ghi vat tu vao file


void GhiMotNhanVien(ofstream &fileout, nv *x) {
	int dem = 0;
	HD p;
	CTHD k;
	fileout << x->MaNv << endl;
	fileout << x->Ho << " " << x->Ten << endl;
	if (x->Phai == 0) {
		fileout << "NAM";
	} else {
		fileout << "NU";
	}
	fileout << endl;
	for (p = x->dshd; p != NULL; p = p->pNext) {
		dem++;
	}
	fileout << dem << endl;
	for (p = x->dshd; p != NULL; p = p->pNext) {
		fileout << p->DataHD.SoHD << endl;
		fileout << p->DataHD.Day.Ngay << endl;
		fileout << p->DataHD.Day.Thang << endl;
		fileout << p->DataHD.Day.Nam << endl;
		if (p->DataHD.Loai[0] == 'N') {
			fileout << "NHAP";
		} else {
			fileout << "XUAT";
		}
		fileout << endl;
		fileout << p->DataHD.TongTien << endl;
		int m = 0;
		for (k = p->DataHD.cthd; k != NULL; k = k->pNext) {
			m++;
		}
		fileout << m << endl;
		for (k = p->DataHD.cthd; k != NULL; k = k->pNext) {
			fileout << k->DataCTHD.MaVT << endl;
			fileout << k->DataCTHD.SoLuong << endl;
			fileout << k->DataCTHD.VAT << endl;
			fileout << k->DataCTHD.DonGia << endl;
		}
	}
}

void GhiDanhSachNhanVien(NV pList) {
	ofstream fileout;
	fileout.open("OUTPUTNV.txt",ios_base::out);
	fileout << pList.n << endl;
	for (int i = 0; i<pList.n; i++) {
		GhiMotNhanVien(fileout,pList.nodes[i]);
		fileout << endl;
	}
	fileout.close();
}

void Ghi_File(VatTu p[], int count) {
	ofstream l;
	l.open("output.txt",ios_base::out);
	l << count << endl;
	for (int i = 0; i<count; i++)
	{
		l << p[i].MAVT << endl;
		l << p[i].TENVT << endl;
		l << p[i].DVT << endl; 
		l << p[i].Soluongton << endl << endl;
	}
	l.close();
}





