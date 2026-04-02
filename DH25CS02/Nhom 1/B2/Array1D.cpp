#include "vector.h"

int main() {
	//Khai bao
	int* a, n;
	int* b, m;
	int* c, size;
	//Khoi tao
	init(a, n);
	init(b, m);
	init(c, size);
	//Xin cap phat
	/*n = input("n");
	a = new int[n];*/

	m = input("m");
	b = new int[m];
	//Nhap mang
	srand(time(NULL));
	/*genArrRand(a, n);*/
	genArrRand(b, m);
	//inputArr(a, n);

	//Xuat mang
	outputArr(a, n);

	//Thao tac
	cout << "=================TINH TONG==================\n";
	cout << "Ket qua tinh: " << sumArr(a, n) << endl;

	cout << "=================TIM KIEM===================\n";
	int* res = findExtrem(a, n, max);
	if(res!=NULL)
		cout << "Max: " << *res << endl;

	res = find(a, n, 22);
	if (res != NULL)
		cout << "Ket qua: " << res << endl;
	else
		cout << "Khong tim thay!\n";

	cout << "=================DAO NGUOC==================\n";
	reverseArr(a, n);
	outputArr(a, n);

	cout << "=================NOI MANG==================\n";
	c = concateArr(a, n, b, m, size);
	outputArr(c, size);

	cout << "=================SAP XEP==================\n";
	sortArr(a, n, min);
	outputArr(a, n);

	cout << "=================DAO NGUOC==================\n";
	reverseArr(a, n);
	outputArr(a, n);

	cout << "=================THEM PHAN TU VAO MANG==================\n";
	pushBackArr(a, n, 2222);
	outputArr(a, n);

	//Giai phong
	delete[]a;
	delete[]b;
	delete[]c;
	return 0;
}