#include <iostream>
#include "vector.h"
using namespace std;

void init(int**& a, int& r, int& c) {
	a = NULL;
	r = 0;
	c = 0;
}
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
			cout << "a[" << i << "][" << j << "]=";
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

int* calRow(int** a, int r, int c) {
	int* res = new int[r];

	for (int i = 0; i < r; i++) {
		*(res + i) = sumArr(*(a + i), c);
	}

	return res;
}

int main() {
	//Khai bao
	int** a, r, c;

	//Khoi tao rong
	init(a, r, c);

	//Xin cap phat
	input(r, c);

	///Cap phat theo so dong
	a = new int* [r];

	///Cap phat theo so cot
	for (int i = 0; i < r; i++) {
		*(a + i) = new int[c];
	}

	//Thao tac

	inputArr(a, r, c);
	outputArr(a, r, c);

	int* res = calRow(a, r, c);

	outputArr(res, r);

	//Giai phong vung nho
	delete[]res;

	for (int i = 0; i < r; i++) {
		delete[]*(a + i);
	}

	delete[]a;
	return 0;
}