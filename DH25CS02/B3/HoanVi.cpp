#include <iostream>
using namespace std; 

int* a, * p;
int n;

void print() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void hoanVi(int i) {
	for (int j = 1; j <= n; j++) {
		if (p[j] == 1) {
			a[i] = j;
			p[j] = 0;

			if (i == n - 1)
				print();
			else
				hoanVi(i + 1);

			//Phuc hoi trang thai de tim loi giai moi
			p[j] = 1;
		}
	}
}

int main() {
	n = 5;

	a = new int[n];
	p = new int[n + 1];

	for (int j = 1; j <= n; j++) {
		p[j] = 1;
	}
	
	hoanVi(0);

	delete[]p;
	delete[]a;
	return 0;
}