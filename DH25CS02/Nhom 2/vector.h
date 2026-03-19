#include <iostream>
#include <ctime>
using namespace std;

void init(int*& a, int& n) {
	a = NULL;
	n = 0;
}

int input() {
	int n;

	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
	} while (n <= 0);

	return n;
}

void inputArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]=";
		cin >> *(a + i);
	}
}

//Sinh mang ngau nhien
void genArrRand(int* a, int n) {
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 20 + 1;
	}
}

void outputArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(a + i) << "\t";
	}
	cout << endl;
}

//Tim kiem tren mang: min, max, key
bool cmpMin(int a, int b) {
	return a < b;
}

bool cmpMax(int a, int b) {
	return a > b;
}

int* findExtrem(int* a, int n, bool func(int, int) = cmpMin) {
	if (a == NULL)
		return NULL;

	int* res = a;

	for (int i = 1; i < n; i++) {
		if (func(*(a + i), *res))
			res = (a + i);
	}

	return res;
}

int* find(int* a, int n, const int key) {
	for (int i = 0; i < n; i++) {
		if (*(a + i) == key)
			return (a + i);
	}
	return NULL;
}

int* concateArr(int* a, int n, int* b, int m, int& size) {
	int* c = new int[n + m];
	size = n + m;

	//Chep du lieu tu a sang c
	for (int i = 0; i < n; i++) {
		*(c + i) = *(a + i);
	}

	//Chep du lieu tu b sang c
	for (int i = 0; i < n; i++) {
		*(c + n + i) = *(b + i);
	}

	return c;
}

//Dao nguoc mang
void reverseArr(int* a, int n) {
	if (a == NULL)
		return;

	int* l = a, * r = (a + n - 1);

	while (l < r) {
		swap(*l++, *r--);
	}
}

//Sap xep
void sortArr(int* a, int n, bool func(int, int)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (func(*(a + j), *(a + i)))
				swap(*(a + j), *(a + i));
		}
	}
}

//Tinh tong mang
int sumArr(int* a, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += *(a + i);
	}

	return sum;
}

//Them phan tu moi vao mang (noi dan kich thuoc)
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
