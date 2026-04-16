#include <iostream>
using namespace std;

//S = 1 + 2 + 3 + ... + n
int tinhTong(int n, int sum = 0) {
	//basic case
	if (n <= 0)
		return sum;

	//general case
	return tinhTong(n - 1, n + sum);
}

int tinhTongBP(int n, int sum = 0) {
	//basic case
	if (n <= 0)
		return sum;

	//general case
	return tinhTongBP(n - 1, n*n + sum);
}

//n = 6
double tinhTongThuong(int n, double sum = 0.0) {
	if (n <= 0)
		return sum;
	if (n % 2 != 0)
		return tinhTongThuong(n - 1, 1.0 / n + sum);
	else
		return tinhTongThuong(n - 1, sum);
}

unsigned long long tinhGT(int n, unsigned long long gt = 1) {
	if (n == 0)
		return gt;

	return tinhGT(n - 1, n * gt);
}

//F = {0 1 1 2 3 5 8 13
int tinhFibo(int n, int a = 0, int b = 1) {
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	return tinhFibo(n - 1, b, a + b);
}

double tinhLuyThua(double x, int n, double res = 1) {
	if (n == 0)
		return res;
	if(n>0)
		return tinhLuyThua(x, n - 1, x * res);
	else {
		if (x == 0)
			return 0;//Loi chia cho so 0
		return tinhLuyThua(x, n + 1, (1.0 / x) * res);
	}
}

int demChuSo(int n, int dem = 0) {
	if (n == 0)
		return dem;

	return demChuSo(n / 10, dem + 1);
}

int tinhSDN(int n, int sdn = 0) {
	if (n == 0)
		return sdn;

	return tinhSDN(n / 10, sdn * 10 + n % 10);
}

void inNhiPhan(int n) {
	if (n == 0)
		return;
	inNhiPhan(n / 2);
	cout << n % 2;
}

int tinhTgPascal(int i, int j) {
	if (j == 0 || i == j)
		return 1;

	return tinhTgPascal(i - 1, j - 1) + tinhTgPascal(i - 1, j);
}

int main() {

	cout << "Ket qua tinh tong: " << tinhTong(5) << endl;
	cout << "Ket qua tinh tong BP: " << tinhTongBP(3) << endl;
	cout << "Ket qua tinh tong Thuong: " << tinhTongThuong(4) << endl;
	cout << "Ket qua tinh giai thua: " << tinhGT(5) << endl;
	cout << "Ket qua tinh fibo: " << tinhFibo(6) << endl;
	cout << "Ket qua tinh luy thua: " << tinhLuyThua(0, -3) << endl;
	cout << "Ket qua dem chu so: " << demChuSo(1246) << endl;
	cout << "Ket qua tinh so dao nguoc: " << tinhSDN(126) << endl;
	cout << "Ket qua in nhi phan: ";
	inNhiPhan(4);
	cout << endl;

	int h;

	cout << "Nhap chieu cao tam giac: ";
	cin >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			cout << tinhTgPascal(i, j) << " ";
		}
		cout << endl;
	}

	return 0;
}