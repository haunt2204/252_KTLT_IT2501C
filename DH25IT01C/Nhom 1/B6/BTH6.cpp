#include <iostream>
#include <ctime>
using namespace std;

//Yeu cau 1
int input() {
	int n;

	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
	} while (n<=0);

	return n;
}

void genArrRand(int *a, int n) {
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 50 + 1;
	}
}

void outputArr(int *a, int n) {
	if (a == NULL) {
		cout << "Mang rong!\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		cout << *(a + i) << " ";
	}

	cout << endl;
}

//Yeu cau 2:
bool isPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int* find(int *a, int n, bool func(int)=isPrime) {
	for (int i = n - 1; i >= 0; i--) {
		if (func(*(a+i)))
			return (a + i);
	}
	return NULL;
}

int count(int *a, int n, int i=0, int res=0) {
	if (i == n)
		return res;

	if (a[i] % 2 == 0)
		return count(a, n, i + 1, 1 + res);

	return count(a, n, i + 1, res);
}

int findExtrem(int *a, int n, int j, int pos = 0) {
	if (j == n)
		return pos;
	
	if (a[j] < a[pos])
		pos = j;

	return findExtrem(a, n, j + 1, pos);
}

void sort(int *a, int n, int i=0) {
	if (i == n-1)
		return;
	int pos = findExtrem(a, n, i + 1, i);
	swap(a[i], a[pos]);
	sort(a, n, i + 1);
}

//Yeu cau 5
//Them phan tu moi vao mang (noi dan kich thuoc)
bool isEven(int n) {
	return n % 2 == 0;
}

void pushBackArr(int*& a, int& n, int x) {
	n = (a == NULL) ? 1 : n + 1;

	int* newArr = new int[n];

	//Chuyen du lieu tu mang a sang newArr
	for (int i = 0; i < n - 1; i++) {
		*(newArr + i) = *(a + i);
	}

	newArr[n - 1] = x;

	delete[]a;
	a = newArr;
}

void filter(int *a, int n, int *&res, int &m, bool func(int)) {
	res = NULL;
	m = 0;

	for (int i = 0; i < n; i++) {
		if (func(a[i]))
			pushBackArr(res, m, a[i]);
	}
}


int main() {
	int *a = NULL, n;

	//Xin cap phat vung nho
	n = input();
	a = new int[n];

	//Thao tac tren mang 1 chieu
	srand(time(NULL));
	genArrRand(a, n);
	outputArr(a, n);

	//Thao tac tim kiem
	cout << "==============TIM KIEM==============\n";
	int *res = find(a, n);

	if (res != NULL)
		cout << res << endl;
	else
		cout << "Khong tim thay!\n";
	
	cout << "==============DEM SO CHAN==============\n";
	cout << "Ket qua: " << count(a, n) << endl;

	cout << "==============SAP XEP==============\n";
	sort(a, n);
	outputArr(a, n);

	cout << "==============LOC MANG==============\n";
	int *r;
	int m;

	filter(a, n, r, m, isPrime);
	cout << "Ket qua: ";
	outputArr(r, m);

	//Giai phong vung nho
	delete[]r;
	delete[]a;
	return 0;
}