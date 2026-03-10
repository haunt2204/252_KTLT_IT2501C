#include "vector.h"

int main() {
	//Khai bao
	int *a, n;
	int *b, m;
	int *c, size;

	//Khoi tao rong
	init(a, n);
	init(b, m);

	//Xin cap phat vung nho
	n = input();
	a = new int[n];
	m = input();
	b = new int[m];

	//Nhap mang
	//inputArr(a, n);
	srand(time(NULL));
	genArrRand(a, n);
	genArrRand(b, m);

	//Xuat mang
	outputArr(a, n);

	//Thao tac tim kiem
	cout << "================TIM KIEM===============\n";
	int* res = find(a, n, 22);

	if (res != NULL)
		cout << "Min = " << *res << endl;
	else
		cout << "Khong tim thay!\n";

	cout << "================NOI MANG===============\n";
	c = concateArr(a, n, b, m, size);
	outputArr(c, size);

	cout << "================THEM PHAN TU===============\n";
	pushBackArr(a, n, 22);
	outputArr(a, n);

	cout << "================SAP XEP===============\n";
	sortArr(a, n);
	outputArr(a, n);
	
	cout << "================DAO NGUOC===============\n";
	reverseArr(a, n);
	outputArr(a, n);
	//Giai phong vung nho
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}