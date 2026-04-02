#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void init(int*& a, int& n) {
	a = NULL;
	n = 0;
}

int input(string title = "") {
	int n;

	do {
		cout << "Nhap " << title << " = ";
		cin >> n;
	} while (n <= 0);

	return n;
}

void inputArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> *(a + i);
	}
}

void outputArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(a + i) << "\t";
	}
	cout << endl;
}

//Sinh mang ngau nhien
void genArrRand(int* a, int n) {
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 20 + 1;
	}
}

//Tinh toan tren mang: tinh tong, tinh tong co dieu kien
bool isEven(int n) {
	return n % 2 == 0;
}

int sumArr(int* a, int n, bool func(int) = NULL) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (func == NULL || func(*(a + i)))
			sum += *(a + i);
	}

	return sum;
}

//Tim kiem: tim min, max, key
bool min(int a, int b) {
	return a < b;
}

bool max(int a, int b) {
	return a > b;
}

int* findExtrem(int* a, int n, bool func(int, int) = min) {
	if (a == NULL)
		return NULL;

	int* res = a;

	for (int i = 1; i < n; i++) {
		if (func(*(a + i), *res))
			res = (a + i);
	}

	return res;
}

int* find(int* a, const int n, const int key) {
	for (int i = 0; i < n; i++) {
		if (*(a + i) == key)
			return (a + i);
	}

	return NULL;
}

//Dao nguoc mang
void reverseArr(int* a, int n) {
	if (a == NULL)
		return;

	int* l = a;
	int* r = a + n - 1;

	while (l < r) {
		swap(*l++, *r--);
	}
}

//Noi mang
int* concateArr(int* a, int n, int* b, int m, int& size) {
	int* c = new int[n + m];
	size = n + m;
	//Chep cac phan tu tu a sang c
	for (int i = 0; i < n; i++) {
		*(c + i) = *(a + i);
	}

	//Chep cac phan tu tu b sang c
	for (int i = 0; i < m; i++) {
		*(c + n + i) = *(b + i);
	}
	return c;
}

//Sap xep
void sortArr(int* a, int n, bool func(int, int) = min) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (func(*(a + j), *(a + i)))
				swap(*(a + j), *(a + i));
		}
	}
}

//Them phan tu vao mang (noi dan kich)
void pushBackArr(int*& a, int& n, const int x) {
	n = (a == NULL) ? 1 : n + 1;
	int* newArr = new int[n];

	//Chuyen doi du lieu
	for (int i = 0; i < n - 1; i++) {
		*(newArr + i) = *(a + i);
	}

	//Them x vao mang
	newArr[n - 1] = x;

	//Giai phong vung nho cu
	delete[]a;
	a = newArr;
}
