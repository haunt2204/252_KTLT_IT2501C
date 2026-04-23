#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Yeu cau 1
struct Sach
{
	char maSach[5];
	string tenSach;
	char tenTacGia[100];
	double giaBan;
	int giamGia; //%
};

void nhap1Sach(Sach &s) {
	cout << "Nhap ma sach: ";
	cin >> s.maSach;

	cin.ignore();
	cout << "Nhap ten sach: ";
	getline(cin, s.tenSach);

	cout << "Nhap ten tac gia: ";
	cin.getline(s.tenTacGia, 100);

	cout << "Nhap gia ban: ";
	cin >> s.giaBan;

	cout << "Nhap giam gia: ";
	cin >> s.giamGia;
}

void xuat1Sach(Sach s) {
	cout << "====================\n";
	cout << "Ma sach: " << s.maSach << endl;
	cout << "Ten sach: " << s.tenSach << endl;
	cout << "Ten tac gia: " << s.tenTacGia << endl;
	cout << "Gia ban: " << s.giaBan << endl;
	cout << "Giam gia: " << s.giamGia << endl;
	cout << "====================\n";
}

double tinhThanhTien(Sach s) {
	//Cap nhat cong thuc tinh
	return s.giaBan - (s.giaBan * s.giamGia/100.0);
}

//Yeu cau
struct DSQS
{
	Sach *ds;
	int soLuong;
};

void init(DSQS &l) {
	l.ds = NULL;
	l.soLuong = 0;
}

//Them phan tu noi dan kich thuoc
void pushBackArr(Sach *&a, int &n, const Sach x) {
	n = (a == NULL) ? 1 : n + 1;
	Sach *newArr = new Sach[n];

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

void inputData(DSQS &l) {
	//B1: Tao doi tuong nhap tu tap tin
	ifstream fin;

	//B2: Chi dinh duong dan (tuong doi)
	fin.open("Sach.txt");

	//B3: Kiem tra trang thai + thao tac
	if (fin.is_open()) {

		while (!fin.eof()) {
			Sach s;
			fin.getline(s.maSach, 5, '#');
			getline(fin, s.tenSach, '#');
			fin.getline(s.tenTacGia, 100, '#');
			fin >> s.giaBan;
			fin.ignore();
			fin >> s.giamGia;
			fin.ignore();
			/*xuat1Sach(s);*/
			pushBackArr(l.ds, l.soLuong, s);
		}

		//B4: Dong tap tin
		fin.close();
	}
}

void empty(DSQS &l) {
	delete []l.ds;
	l.ds = NULL;
}

void xuatDsQs(DSQS l) {
	if (l.ds == NULL) {
		cout << "DS rong!\n";
		return;
	}
	for (int i = 0; i < l.soLuong; i++) {
		xuat1Sach(l.ds[i]);
	}
}

//De quy duoi?
double tinhTongHD(DSQS l) {
	double tong = 0;
	for (int i = 0; i < l.soLuong; i++) {
		tong += tinhThanhTien(l.ds[i]);
	}
	return tong;
}

//Yeu cau 3

Sach* timKiem(DSQS l, char *id) {
	if (l.ds == NULL)
		return NULL;

	for (int i = 0; i < l.soLuong; i++) {
		if (strcmp(l.ds[i].maSach, id) == 0)
			return &l.ds[i];
	}

	return NULL;
}

//DSQS timKiem(DSQS l, string key) {
//	DSQS res;
//	init(res);
//
//	for (int i = 0; i < l.soLuong; i++) {
//		if (l.ds[i].tenSach == key) {
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

//Yeu cau 4
DSQS addToCart(DSQS l) {
	DSQS cart;
	init(cart);

	char id[5];
	int c;

	do {
		cout << "Nhap ma quyen sach can mua: ";
		cin >> id;
		Sach* res = timKiem(l, id);
		if (res != NULL) {
			pushBackArr(cart.ds, cart.soLuong, *res);
		}
		else
			cout << "Khong tim thay quyen sach can mua!\n";

		cout << "Muon mua tiep? (1-Co, 0-Khong): ";
		cin >> c;
		/*cin.ignore();*/
	} while (c!=0);

	return cart;
}

void xuatHD(DSQS l) {
	ofstream fout("HoaDon.txt");

	if (fout.is_open()) {
		fout << tinhTongHD(l) << endl;

		for (int i = 0; i < l.soLuong; i++) {
			fout << l.ds[i].maSach << "#" << l.ds[i].tenSach << "#" << tinhThanhTien(l.ds[i]) << endl;
		}

		fout.close();
	}
}

int main() {
	DSQS l;
	init(l);

	l.soLuong = 1;
	l.ds = new Sach[l.soLuong];

	//l.ds[0] = {"S001", "Nha Gia Kim", "Paulo Coelho", 150000, 10};

	inputData(l);
	xuatDsQs(l);

	DSQS cart = addToCart(l);
	cout << "=================GIO HANG==================\n";
	xuatDsQs(cart);
	xuatHD(cart);
	/*cout << "=================TIM KIEM==================\n";

	Sach *res = timKiem(l, "S004");

	if (res != NULL) {
		xuat1Sach(*res);
	}
	else
		cout << "Khong tim thay!\n";
	string key = "Dac Nhan Tam";
	vector<Sach> kq = timKiem(l, key);

	if (kq.size() != 0) {
		for (int i = 0; i < kq.size(); i++) {
			xuat1Sach(kq[i]);
		}
	}
	else
		cout << "Danh sach rong!\n";*/
	/*DSQS kq = timKiem(l, key);
	if (kq.ds != NULL) {
		xuatDsQs(kq);
	}
	else
		cout << "Khong tim thay!\n";*/
	empty(cart);
	empty(l);
	return 0;
}
