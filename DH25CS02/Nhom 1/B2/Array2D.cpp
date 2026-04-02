#include <iostream>
#include "vector.h"
using namespace std;

void input(int& r, int& c) {

	do {
		cout << "Nhap so dong: ";
		cin >> r;

		cout << "Nhap so cot: ";
		cin >> c;
	} while (r<=0 || c<=0);
}

void inputArr(int** a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> *(*(a + i) + j);
		}
	}
}

void outputArr(int** a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
}

int* sumRow(int** a, int r, int c) {
	int* res = new int[r];
	for (int i = 0; i < r; i++) {
		*(res + i) = sumArr(*(a + i), c);
	}
	return res;
}

int main() {
	//Khai bao
	int** a, r, c;

	input(r, c);

	//Xin cap phat vung nho
	///Cap phat so dong
	a = new int* [r];

	///Cap phat so cot
	for (int i = 0; i < r; i++) {
		*(a + i) = new int[c];
	}

	//Nhap du lieu cho tung phan tu
	inputArr(a, r, c);
	//Xuat mang ra man hinh
	outputArr(a, r, c);
	//Thao tinh tong dong
	int* res = sumRow(a, r, c);
	cout << "Tong dong: ";
	outputArr(res, r);


	//Giai phong
	delete[]res;
	for (int i = 0; i < r; i++) {
		delete[] * (a + i);
	}
	delete[]a;
	return 0;
}