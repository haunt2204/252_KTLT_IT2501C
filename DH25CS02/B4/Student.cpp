#include <iostream>
#include <string>
using namespace std;

#define SOMH 3
#define MAX 45

string loai[] = { "Yeu", "TB", "Kha", "Gioi" };
enum XepLoai
{
	YEU,
	TB,
	KHA,
	GIOI
};

struct SinhVien
{
	long long mssv;
	string hoTen;
	char queQuan[100];
	char ngaySinh[11];
	double diem[SOMH];
};

void nhap1Sv(SinhVien &sv) {
	cout << "Nhap mssv: ";
	cin >> sv.mssv;

	cin.ignore();
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoTen);

	cout << "Nhap que quan: ";
	cin.getline(sv.queQuan, 100);

	cout << "Nhap ngay sinh: ";
	cin >> sv.ngaySinh;

	cout << "Nhap diem mon hoc: ";
	for (int i = 0; i < SOMH; i++) {
		cin >> sv.diem[i];
	}
}

void xuat1Sv(const SinhVien &sv) {
	cout << "===================================\n";
	cout << "ID: ";
	cout << sv.mssv << endl;

	cout << "Ho ten: ";
	cout << sv.hoTen << endl;

	cout << "Que quan: ";
	cout << sv.queQuan << endl;

	cout << "Ngay sinh: ";
	cout << sv.ngaySinh << endl;

	cout << "Diem mon hoc: ";
	for (int i = 0; i < SOMH; i++) {
		cout << sv.diem[i] << " ";
	}
	cout << endl;
	cout << "===================================\n";
}

double tinhDtb(SinhVien sv) {
	int tong = 0;

	for (int i = 0; i < SOMH; i++) {
		tong += sv.diem[i];
	}

	return tong / SOMH;
}

int xepLoai(SinhVien sv) {
	double dtb = tinhDtb(sv);

	if (dtb >= 8)
		return GIOI;
	if (dtb >= 6.5)
		return KHA;
	if (dtb >= 5)
		return TB;
	return YEU;
}

ostream&  operator<<(ostream& out, const SinhVien& sv) {
	out << "===================================\n";
	out << "ID: ";
	out << sv.mssv << endl;

	out << "Ho ten: ";
	out << sv.hoTen << endl;

	out << "Que quan: ";
	out << sv.queQuan << endl;

	out << "Ngay sinh: ";
	out << sv.ngaySinh << endl;

	out << "Diem mon hoc: ";
	for (int i = 0; i < SOMH; i++) {
		out << sv.diem[i] << " ";
	}
	out << endl;
	cout << "DTB: " << tinhDtb(sv) << endl;
	cout << "Xep loai: " << loai[xepLoai(sv)] << endl;
	out << "===================================\n";

	return out;
}

struct DSSV
{
	SinhVien *ds;
	int siSo;
};

void init(DSSV& l) {
	l.ds = NULL;
	l.siSo = 0;
}

void nhapDsSv(DSSV& l) {
	do {
		cout << "Nhap si so: ";
		cin >> l.siSo;
	} while (l.siSo<=0 || l.siSo>MAX);

	l.ds = new SinhVien[l.siSo];

	for (int i = 0; i < l.siSo; i++) {
		nhap1Sv(l.ds[i]);
	}
}

void xuatDsSv(DSSV l) {
	if (l.ds == NULL) {
		cout << "DS rong!\n";
		return;
	}

	for (int i = 0; i < l.siSo; i++) {
		cout << l.ds[i];
		/*xuat1Sv(l.ds[i]);*/
	}
}

int main() {
	DSSV l;

	init(l);

	nhapDsSv(l);
	xuatDsSv(l);


	return 0;
}