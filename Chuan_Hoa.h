#pragma once


int CheckRong(char *s); // Ham check chuoi co rong hay khong
void InHoaChuoi(char *s); // Ham in hoa tat ca chuoi
void XoaMotKiTu(char s[], int i); // Ham xoa 1 ki tu trong chuoi
void XoaKt(char *s); // Ham xoa khoang trang thua trong chuoi
int HamNhapMaNV(char manv[10]); // ham chi nhan chu va so, khong nhan ki tu dac biet va khoang trang
int HamNhapHo(char ho[50]); // ham chi nhan chu va khoang trang
int HamNhapTen(char ten[10]); // ham chi nhan chu
int HamNhapPhai(char phai[2]);
int HamNhapSLT(char SLT[11]);
int HamNhapSoHD(char sohd[20]);
int HamNhapLoai(char loai[2]);
int Kt_Nhuan(Date x);
int SoNgayToiDaTrongThang(Date x);
int Kt_HopLe(Date x);
int HamNhapNgay_Thang(char date[3]);
int HamNhapNam(char year[5]);
int SoSanh(Date x, Date y);



int CheckRong(char *s) { // Ham check chuoi co rong hay khong
	int dem=0;
	int n=strlen(s);
	for (int i=0; i<n; i++) {
		if (s[i]!=' ' && s[i]!='\n' && s[i]!='\0')
			dem++;
	}
	return dem;
}

void InHoaChuoi(char *s) { // Ham in hoa tat ca chuoi
	for (int i=0; i<strlen(s); i++) {
		s[i]=toupper(s[i]);
	}
}

void XoaMotKiTu(char s[], int i) { // Ham xoa 1 ki tu trong chuoi
	int n=strlen(s);
	for (int j=i; j<n; j++) {
		s[j]=s[j+1];
	}
	s[n-1]='\0';
}

void XoaKt(char *s) { // Ham xoa khoang trang thua trong chuoi
	int n=strlen(s);
	for (int i=0; i<n; i++) {
		if (s[i]==' ' && s[i+1]==' ') {
			XoaMotKiTu(s,i);
			i--;
		}
	}
	if (s[0]==' ')
		XoaMotKiTu(s,0);
	if (s[strlen(s)-1]==' ')
		XoaMotKiTu(s,strlen(s)-1);
}

int HamNhapMaNV(char manv[10]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 9) {
			if (c >= 48 && c <= 57 || c>=65 && c<=90 || c>=97 && c<=122) {
				c = toupper(c);
				manv[x] = c;
				cout << manv[x];
				x++;
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			cout << char(8) << " " << char(8);
			x--;
		}
		if (c == 27) {
			return -1;
		}
	}
	manv[x] = '\0';
	return 1;
}

int HamNhapHo(char ho[50]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 49) {
			if (x == 0) {
				if (c>=65 && c<=90 || c>=97 && c<=122) {
					c = toupper(c);
					ho[x] = c;
					cout << ho[x];
					x++;
				}
			} else if (x>0) {
				if (c>=65 && c<=90 || c>=97 && c<=122) {
					c = toupper(c);
					ho[x] = c;
					cout << ho[x];
					x++;
				}
				if (c == 32) {
					if (ho[x-1] == ' ') {
						continue;
					}
					else {
						ho[x] = c;
						cout << ho[x];
						x++;
					}
				}
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			cout << char(8) << " " << char(8);
			x--;
		}
		if (c == 27) {
			return -1;
		}
	}
	ho[x] = '\0';
	return 1;
}

int HamNhapTen(char ten[10]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 9) {
			if (c>=65 && c<=90 || c>=97 && c<=122) {
				c = toupper(c);
				ten[x] = c;
				cout << ten[x];
				x++;
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			cout << char(8) << " " << char(8);
			x--;
		}
		if (c == 27) {
			return -1;
		}
	}
	ten[x] = '\0';
	return 1;
}

int HamNhapPhai(char phai[2]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 1) {
			if (c==48 || c==49) {
				c = toupper(c);
				phai[x] = c;
				if (phai[x] == 48)
					cout << "NAM";
				else {
					cout << "NU";
				}
				x++;
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			if (phai[x-1] == 48) {
				cout << char(8) << char(8) << char(8) << "   " << char(8) << char(8) << char(8);
				x--;
			} else {
				cout << char(8) << char(8) << "  " << char(8) << char(8);
				x--;
			}
		}
		if (c == 27) {
			return -1;
		}
	}
	phai[x] = '\0';
	return 1;
}

int HamNhapSLT(char SLT[11]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 10) {
			if (c>=48 && c<=57) {
				SLT[x] = c;
				cout << SLT[x];
				x++;
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			cout << char(8) << " " << char(8);
			x--;
		}
		if (c == 27) {
			return -1;
		}
	}
	SLT[x] = '\0';
	int slt = SLT[0] - '0';
	for (int i=1;i<x;i++) {
		slt = slt*10 + (int)SLT[i]-48;
	}
	return slt;
}

int HamNhapSoHD(char sohd[20]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 19) {
			if (c >= 48 && c <= 57 || c>=65 && c<=90 || c>=97 && c<=122) {
				c = toupper(c);
				sohd[x] = c;
				cout << sohd[x];
				x++;
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			cout << char(8) << " " << char(8);
			x--;
		}
		if (c == 27) {
			return -1;
		}
	}
	sohd[x] = '\0';
	return 1;
}

int HamNhapLoai(char loai[2]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 1) {
			if (c=='X' || c=='x' || c=='n' || c=='N') {
				c = toupper(c);
				loai[x] = c;
				if (loai[x] == 'N')
					cout << "NHAP";
				else {
					cout << "XUAT";
				}
				x++;
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			cout << char(8) << char(8) << char(8) << char(8) << "    " << char(8) << char(8) << char(8) << char(8);
			x--;
		}
		if (c == 27) {
			return -1;
		}
	}
	loai[x] = '\0';
	return 1;
}

int Kt_Nhuan(Date x)
{
	if (x.Nam % 4 == 0 && x.Nam % 100 != 0)
		return 1;
	if (x.Nam % 400 == 0)
		return 1;
	return 0;
}

int SoNgayToiDaTrongThang(Date x)
{
	int ngaythang[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (Kt_Nhuan(x))
		ngaythang[1] = 29;
	return ngaythang[x.Thang - 1];
}

int Kt_HopLe(Date x)
{
	time_t hientai = time(0); 
	tm *ht = localtime(&hientai); 
	int namht = 1900 + ht->tm_year;
	int thanght = 1 + ht->tm_mon;
	int ngayht = ht->tm_mday;
	if (x.Nam < 1)
		return 0;
	if (x.Thang < 1)
		return 0;
	if (x.Thang > 12)
		return 0;
	if (x.Ngay < 1)
		return 0;
	if (x.Ngay > SoNgayToiDaTrongThang(x))
		return 0;
	if (x.Nam > namht) 
		return 0;
	else if (x.Nam == namht) {
		if (x.Thang > thanght) 
			return 0;
		else if (x.Thang == thanght) {
			if (x.Ngay > ngayht)
				return 0;
		}
	}
	return 1;
}

int HamNhapNgay_Thang(char date[3]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 2) {
			if (c>=48 && c<=57) {
				date[x] = c;
				cout << date[x];
				x++;
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			cout << char(8) << " " << char(8);
			x--;
		}
		if (c == 27) {
			return -1;
		}
	}
	date[x] = '\0';
	int DATE = date[0] - '0';
	for (int i=1;i<x;i++) {
		DATE = DATE*10 + (int)date[i]-48;
	}
	return DATE;
}

int HamNhapNam(char year[5]) {
	char c;
	int x = 0;
	while (true) {
		c = getch();
		if (x < 4) {
			if (c>=48 && c<=57) {
				year[x] = c;
				cout << year[x];
				x++;
			}
		}
		if (c == 13) {
			break;
		}
		if (c == 8 && x > 0) {
			cout << char(8) << " " << char(8);
			x--;
		}
		if (c == 27) {
			return -1;
		}
	}
	year[x] = '\0';
	int YEAR = year[0] - '0';
	for (int i=1;i<x;i++) {
		YEAR = YEAR*10 + (int)year[i]-48;
	}
	return YEAR;
}

int SoSanh(Date x, Date y)
{
	if (x.Nam > y.Nam)
		return 1;
	if (x.Nam < y.Nam)
		return -1;
	if (x.Thang > y.Thang)
		return 1;
	if (x.Thang < y.Thang)
		return -1;
	if (x.Ngay > y.Ngay)
		return 1;
	if (x.Ngay < y.Ngay)
		return -1;
	return 0;
}

