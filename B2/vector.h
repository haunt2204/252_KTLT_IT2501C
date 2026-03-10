#include <iostream>
#include <ctime>
using namespace std;

void init(int *&a, int &n) {
	a = NULL;
	n = 0;
}

int input() {
	int n;

	do {
		cout << "Nhap n = ";
		cin >> n;
	} while (n <= 0);

	return n;
}

void inputArr(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> *(a + i);
	}
}

void outputArr(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(a + i) << " ";
	}
	cout << endl;
}

void genArrRand(int *a, int n) {
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 20 + 1;
	}
}

bool isLess(int a, int b) {
	return a < b;
}

int *findExtrem(int *a, int n, bool func(int, int) = isLess) {
	if (a == NULL)
		return NULL;

	int *res = a;

	for (int i = 1; i < n; i++) {
		if (func(*(a + i), *res))
			res = (a + i);
	}

	return res;
}

int *find(int *a, const int n, const int key) {
	for (int i = 0; i < n; i++) {
		if (*(a + i) == key) {
			return (a + i);
		}
	}

	return NULL;
}

//Noi 2 mang a va b tra ve mang ket qua
int* concateArr(const int* a, const int n, const int *b, const int m, int &size) {
	int *c = new int[n + m];
	size = n + m;

	for (int i = 0; i < n; i++) {
		*(c + i) = *(a + i);
	}

	for (int i = 0; i < m; i++) {
		*(c + n + i) = *(b + i);
	}

	return c;
}


//Them phan tu noi dan kich thuoc
void pushBackArr(int *&a, int &n, const int x) {
	n = (a == NULL) ? 1 : n + 1;
	int *newArr = new int[n];

	//Chuyen du lieu tu mang cu sang mang moi
	for (int i = 0; i < n - 1; i++) {
		*(newArr + i) = *(a + i);
	}

	//Them x vao mang
	newArr[n - 1] = x;

	//Giai phong vung nho cu
	delete[]a;
	a = newArr;
}

//Sap xep mang 
void sortArr(int *a, int n, bool func(int, int) = isLess) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (func(*(a + j), *(a + i)))
				swap(*(a + j), *(a + i));
		}
	}
}

//Dao nguoc mang
void reverseArr(int *a, int n) {
	int *l = a;
	int *r = (a + n - 1);
	while (l < r) {
		swap(*l++, *r--);
	}
}

//Tinh toan: tinh tong, dem,...
int sumArr(int *a, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += a[i];

	return sum;
}
