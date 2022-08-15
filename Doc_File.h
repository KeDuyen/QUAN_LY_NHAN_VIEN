#pragma once

void DocNhanVien (NV &pList, TREE &t); // ham doc mot nhan vien tu file
void Doc_File(VatTu vt,TREE &t); // ham doc vat tu tu file


void DocNhanVien (NV &pList, TREE &t) {
	ifstream filein;
	filein.open("INPUTNV.txt",ios_base::in);
	char loai[2],manv[10],hoten[60],ho[50],ten[10];
	int count_nv,count_hd,count_cthd,i,phai;
	string MANV,HOTEN,PHAI,temp,SOHD,LOAI,MAVT;
	filein >> count_nv;
	if (count_nv == 0) {
		return;
	}
	getline(filein,temp);
	for (int q = 0; q<count_nv; q++) {
		// doc ma nhan vien
		getline(filein, MANV, '\n');
		MANV.copy(manv, MANV.length());
		manv[MANV.length()] = '\0';
		// doc ho ten
		getline(filein, HOTEN, '\n');
		int n = HOTEN.length();
		for (i=n-1; i>=0; i--) {
			if (HOTEN[i] == ' ')
				break;
		}
		HOTEN.copy(ho,i,0);
		ho[i] = '\0';
		HOTEN.copy(ten,n-i-1,i+1);
		ten[n-i-1] = '\0';
		InHoaChuoi(ho);
		InHoaChuoi(ten);
		// doc phai
		getline(filein, PHAI, '\n');
		if (PHAI == "NAM") {
			phai = 0;
		} else {
			phai = 1;
		}
		nv *nhanvien = new nv(manv,ho,ten,phai);
		
		filein >> count_hd;
		getline(filein,temp);
		for (int j = 0; j<count_hd; j++) {
			DLHD p;
			getline(filein,SOHD,'\n');
			SOHD.copy(p.SoHD,SOHD.length());
			filein >> p.Day.Ngay;
			getline(filein,temp);
			filein >> p.Day.Thang;
			getline(filein,temp);
			filein >> p.Day.Nam;
			getline(filein,temp);
			getline(filein,LOAI,'\n');
			if (LOAI == "NHAP") {
				p.Loai[0] = 'N';
			} else {
				p.Loai[0] = 'X';
			}
			p.Loai[1] = '\0';
			filein >> p.TongTien;
			getline(filein,temp);
			
			filein >> count_cthd;
			getline(filein,temp);
			for (int k = 0; k<count_cthd; k++) {
				DLCTHD l;
				getline(filein,MAVT,'\n');
				MAVT.copy(l.MaVT,MAVT.length());
				filein >> l.SoLuong;
				getline(filein,temp);
				filein >> l.VAT;
				getline(filein,temp);
				filein >> l.DonGia;	
				getline(filein,temp);
				CTHD z = KhoiTaoCTHD(l);
				ThemVaoDauCTHD(p.cthd,z);
			}
			HD w = KhoiTaoHD(p);
			ThemVaoDauHD(nhanvien->dshd,w);
			CapNhatSLT(nhanvien->dshd,t);
		} 
		Insert_Item(pList, pList.n, nhanvien);
		getline(filein, temp); // lay ki tu cuoi
	}
	filein.close();
}

void Doc_File(VatTu vt,TREE &t) {
	ifstream p;
	int count;
	string Mavt,Tenvt,Dvt,SLT,temp;
	p.open("input.txt",ios_base::in);
	if(p.fail()==true) {
		cout<<"File ban khong ton tai!\n";
		system("pause");
		return;
	}
	p >> count;
	if (count == 0) {
		return;
	}
	getline(p,temp);
	for (int i = 0; i<count; i++) {
		getline(p,Mavt,'\n');
		Mavt.copy(vt.MAVT,Mavt.length());
		vt.MAVT[Mavt.length()]='\0';
		getline(p,Tenvt,'\n');
		Tenvt.copy(vt.TENVT,Tenvt.length());
		vt.TENVT[Tenvt.length()]='\0';
		getline(p,Dvt,'\n');
		Dvt.copy(vt.DVT,Dvt.length());
		vt.DVT[Dvt.length()]='\0';
		p >> vt.Soluongton;		
		ThemPhanTu(t,vt);
		getline(p,temp);
		getline(p,temp);
		
	}
	p.close();
}





