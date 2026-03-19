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

	//Xin cap phat vung
	n = input();
	a = new int[n];

	m = input();
	b = new int[m];

	//Thao tac
	//Nhap/Xuat
	srand(time(NULL));
	genArrRand(a, n);
	genArrRand(b, m);
	//inputArr(a, n);
	outputArr(a, n);

	//Tim kiem
	cout << "===============TIM KIEM================\n";
	int* res = findExtrem(a, n, cmpMin);

	if (res != NULL)
		cout << "Min: " << *res << endl;
	else
		cout << "Mang rong!\n";

	res = find(a, n, 22);
	if (res != NULL)
		cout << "Ket qua: " << res << endl;
	else
		cout << "Khong tim thay!\n";


	cout << "===============NOI MANG================\n";
	//c = concateArr(a, n, b, m, size);
	outputArr(c, size);

	cout << "===============SAP XEP================\n";
	sortArr(c, size, cmpMin);
	outputArr(c, size);

	cout << "===============DAO NGUOC MANG================\n";
	reverseArr(c, size);
	outputArr(c, size);

	cout << "===============THEM PHAN TU VAO MANG================\n";
	pushBackArr(c, size, 999);
	outputArr(c, size);
	//Giai phong vung nho
	delete[]c;
	delete[]b;
	delete[]a;
	return 0;
}