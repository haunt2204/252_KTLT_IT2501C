#include <iostream>
#include "vector.h"
using namespace std;


void init(int **&a, int &r, int &c) {
	a = NULL;
	r = 0;
	r = 0;
}

void input(int &r, int &c) {
	do {
		cout << "Nhap so dong: ";
		cin >> r;

		cout << "Nhap so cot: ";
		cin >> c;
	} while (r<=0 || c<=0);
}

void inputArr(int **a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> *(*(a + i) + j);
		}
	}
}

void outputArr(int **a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
}

void xuatTongDong(int **a, int r, int c) {
	for (int i = 0; i < r; i++) {
		cout << sumArr(*(a + i), c) << endl;
	}
}

int main() {
	//Khai bao
	int **a, r, c;

	//Khoi tao rong
	init(a, r, c);

	//Xin cap phat
	input(r, c);
	//Cap phat so dong
	a = new int*[r];

	//Cap phat so cot
	for (int i = 0; i < r; i++) {
		*(a + i) = new int[c];
	}

	//Nhap du lieu cho tung phan tu mang
	inputArr(a, r, c);
	outputArr(a, r, c);

	//Tinh tong dong
	xuatTongDong(a, r, c);

	//Giai phong vung nho
	for (int i = 0; i < r; i++)
		delete[] a[i];
	delete[]a;
	return 0;
}