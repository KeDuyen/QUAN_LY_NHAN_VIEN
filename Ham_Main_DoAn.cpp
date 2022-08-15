#include "Header.h"
#include "Nhan_Vien.h"
#include "Chuan_Hoa.h"
#include "Do_Hoa.h"
#include "Vat_Tu.h"
#include "Hoa_Don.h"
#include "Doanh_Thu.h"
#include "Menu_NhanVien.h"
#include "Menu_VatTu.h"
#include "Menu_HoaDon.h"
#include "Menu_DoanhThu.h"
#include "Menu_Chinh.h"
#include "Doc_File.h"
#include "Ghi_File.h"
 


int main() {
	NV pList;
	TREE t;
	VatTu vt;
	KhoiTaoDSVT(t);
	Doc_File(vt,t);
	pList.n=0;
	DocNhanVien(pList,t);
	MenuChinh(pList,t);
	return 0;
}

