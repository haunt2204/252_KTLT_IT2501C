#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Yeu cau 1
struct Sach
{
	char maSach[5];
	string tenSach = "";
	char tenTg[100] = "";
	double giaBan = 0;
	int giamGia = 0;
};

void nhap1Sach(Sach& s) {
	cout << "Nhap ma sach: ";
	cin >> s.maSach;

	cin.ignore();
	cout << "Nhap ten sach: ";
	getline(cin, s.tenSach);

	cout << "Nhap ten tac gia: ";
	cin.getline(s.tenTg, 100);

	cout << "Nhap gia ban: ";
	cin >> s.giaBan;

	cout << "Nhap giam gia: ";
	cin >> s.giamGia;
}

void xuat1Sach(Sach s) {
	cout << "====================\n";
	cout << "Ma sach: " << s.maSach << endl;
	cout << "Ten sach: " << s.tenSach << endl;
	cout << "Ten tac gia: " << s.tenTg << endl;
	cout << "Gia ban: " << s.giaBan << endl;
	cout << "Giam gia: " << s.giamGia << endl;
	cout << "====================\n";
}

double tinhThanhTien(Sach s) {
	//Cap nhat cong thuc tinh
	return s.giaBan - (s.giaBan * s.giamGia/100.0);
}

//Yeu cau 2
struct DSQS
{
	Sach* ds;
	int soLuong;
};

void init(DSQS& l) {
	l.ds = NULL;
	l.soLuong = 0;
}

//Them phan tu noi dan kich thuoc
void pushBackArr(Sach*& a, int& n, const Sach x) {
	n = (a == NULL) ? 1 : n + 1;
	Sach* newArr = new Sach[n];

	//Chuyen du lieu tu mang cu sang mang moi
	for (int i = 0; i < n - 1; i++) {
		*(newArr + i) = *(a + i);
	}

	//Them x vao mang
	newArr[n - 1] = x;

	//Giai phong vung nho cu
	delete[]a;
	a = newArr;
}

void inputData(DSQS& l) {
	//B1: Tao doi tuong doc tap tin
	ifstream fin;

	//B2: Chi dinh duong dan: tuong doi
	fin.open("Sach.txt");

	//B3: Kiem tra trang thai
	if (fin.is_open()) {
		//Thao tac

		Sach s;

		while (!fin.eof()) {
			fin.getline(s.maSach, 5, '#');
			getline(fin, s.tenSach, '#');
			fin.getline(s.tenTg, 100, '#');
			fin >> s.giaBan;
			fin.ignore();
			fin >> s.giamGia;
			fin.ignore();
			pushBackArr(l.ds, l.soLuong, s);
		}

		//B4: Dong tap tin
		fin.close();
	}
}

void xuatDsQs(DSQS l) {
	if (l.ds == NULL) {
		cout << "Danh sach rong!\n";
		return;
	}

	for (int i = 0; i < l.soLuong; i++) {
		xuat1Sach(l.ds[i]);
	}
}

void empty(DSQS& l) {
	delete[] l.ds;
	l.ds = NULL;
}

double tinhTongHD(DSQS l) {
	double tong = 0;

	for (int i = 0; i < l.soLuong; i++) {
		tong += tinhThanhTien(l.ds[i]);
	}

	return tong;
}

//Yeu cau 3
Sach* timKiem(DSQS l, char id[]) {
	for (int i = 0; i < l.soLuong; i++) {
		if (strcmp(l.ds[i].maSach, id) == 0) {
			return &l.ds[i];
		}
	}
	return NULL;
}

//DSQS timKiem(DSQS l, string key) {
//	DSQS res;
//	init(res);
//
//	for (int i = 0; i < l.soLuong; i++) {
//		if (l.ds[i].tenSach==key) {
//			pushBackArr(res.ds, res.soLuong, l.ds[i]);
//		}
//	}
//
//	return res;
//}

vector<Sach> timKiem(DSQS l, string key) {
	vector<Sach> res;

	for (int i = 0; i < l.soLuong; i++) {
		if (l.ds[i].tenSach == key) {
			res.push_back(l.ds[i]);
		}
	}

	return res;
}

DSQS addToCart(DSQS l) {
	DSQS cart;
	init(cart);

	char id[5];
	int c;

	do {
		cout << "Nhap ma quyen sach can mua: ";
		cin >> id;

		Sach* res = timKiem(l, id);

		if (res != NULL)
			pushBackArr(cart.ds, cart.soLuong, *res);
		else
			cout << "Sach khong co trong kho!\n";

		cout << "Mua tiep? (Co-1, Khong-0): ";
		cin >> c;
	} while (c!=0);

	return cart;
}

void xuatHoaDon(DSQS l) {
	ofstream fout("HoaDon.txt");

	if (fout.is_open()) {

		fout << tinhTongHD(l) << endl;

		for (int i = 0; i < l.soLuong; i++) {
			fout << l.ds[i].maSach << "#"
				<< l.ds[i].tenSach << "#"
				<< to_string(tinhThanhTien(l.ds[i])) << endl;
		}

		fout.close();
	}
}

int main() {
	DSQS l;
	init(l);

	inputData(l);
	xuatDsQs(l);

	cout << "==============TIM KIEM===============\n";
	/*char id[] = "S014";
	Sach* res = timKiem(l, id);
	if (res != NULL)
		xuat1Sach(*res);
	else
		cout << "Khong tim thay!\n";*/
	string key;
	key = "Bi Mat Cua Nuoc";

	/*DSQS res = timKiem(l, key);
	if (res.ds != NULL)
		xuatDsQs(res);
	else
		cout << "Khong tim thay!\n";*/

	vector<Sach> res = timKiem(l, key);
	if (res.size() != 0)
	{
		for (int i = 0; i < res.size(); i++) {
			xuat1Sach(res[i]);
		}
	}
	else
		cout << "Khong tim thay!\n";

	cout << "==============MUA HANG===============\n";
	DSQS cart = addToCart(l);
	xuatDsQs(cart);
	xuatHoaDon(cart);

	empty(cart);
	empty(res);
	empty(l);
	return 0;
}
