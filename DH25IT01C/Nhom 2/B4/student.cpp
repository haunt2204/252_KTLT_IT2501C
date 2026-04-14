#include <iostream>
#include <string>
using namespace std;

#define SOMH 3
#define MAX 45

string loai[] = { "YEU", "TB", "KHA", "GIOI" };
enum XepLoai
{
	YEU,
	TB,
	KHA,
	GIOI
};

struct SinhVien {
	int mssv;
	string hoTen;
	char queQuan[100];
	char ngaySinh[11];
	double diem[SOMH];
};

double tinhDTB(SinhVien sv) {
	double tong = 0;
	for (int i = 0; i < SOMH; i++) {
		tong += sv.diem[i];
	}
	return tong / SOMH;
}

int xepLoai(SinhVien sv) {
	double dtb = tinhDTB(sv);

	if (dtb >= 8)
		return GIOI;
	if (dtb > 6.5)
		return KHA;
	if (dtb > 5)
		return TB;
	return YEU;
}

void nhap1Sv(SinhVien &sv) {
	cout << "Nhap MSSV: ";
	cin >> sv.mssv;

	cin.ignore();
	cout << "Nhap ho va ten: ";
	getline(cin, sv.hoTen);

	cout << "Nhap que quan: ";
	cin.getline(sv.queQuan, 100);

	cout << "Nhap ngay sinh: ";
	cin >> sv.ngaySinh;

	cout << "Nhap diem: ";
	for (int i = 0; i < SOMH; i++) {
		cin >> sv.diem[i];
	}
}

void xuat1Sv(SinhVien sv) {
	cout << "============================\n";
	cout << "MSSV: ";
	cout << sv.mssv << endl;

	cout << "Ho va ten: ";
	cout << sv.hoTen << endl;

	cout << "Que quan: ";
	cout << sv.queQuan << endl;

	cout << "Ngay sinh: ";
	cout << sv.ngaySinh << endl;

	cout << "Diem: ";
	for (int i = 0; i < SOMH; i++) {
		cout << sv.diem[i] << " ";
	}
	cout << endl;
	cout << "============================\n";
}

struct DSSV
{
	SinhVien *ds;
	int siSo;
};

void init(DSSV &l) {
	l.ds = NULL;
	l.siSo = 0;
}

void nhapDsSv(DSSV &l) {
	do {
		cout << "Nhap si so: ";
		cin >> l.siSo;
	} while (l.siSo<=0 || l.siSo>MAX);

	l.ds = new SinhVien[l.siSo];

	for (int i = 0; i < l.siSo; i++) {
		nhap1Sv(l.ds[i]);
	}
}

ostream& operator<<(ostream &out, const SinhVien &sv) {
	out << "============================\n";
	out << "MSSV: ";
	out << sv.mssv << endl;

	out << "Ho va ten: ";
	out << sv.hoTen << endl;

	out << "Que quan: ";
	out << sv.queQuan << endl;

	out << "Ngay sinh: ";
	out << sv.ngaySinh << endl;

	out << "Diem: ";
	for (int i = 0; i < SOMH; i++) {
		out << sv.diem[i] << " ";
	}
	out << endl;
	out << "DTB: " << tinhDTB(sv) << endl;
	out << "Xep loai: " << loai[xepLoai(sv)] << endl;
	out << "============================\n";
	return out;
}

void xuatDsSv(DSSV l) {
	for (int i = 0; i < l.siSo; i++) {
		cout << l.ds[i];
		/*xuat1Sv(l.ds[i]);*/
	}
}

void empty(DSSV &l) {
	delete[]l.ds;
	l.ds = NULL;
}

int main() {
	DSSV l;

	init(l);

	nhapDsSv(l);
	xuatDsSv(l);

	empty(l);
	return 0;
}