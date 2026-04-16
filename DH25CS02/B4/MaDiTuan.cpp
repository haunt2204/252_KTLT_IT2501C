#include <iostream>
using namespace std;

#define SIZE 8

int banCo[SIZE][SIZE] = { { 0 } };
int dd[] = { -2,-2,-1,1,2,2,1,-1 };
int dc[] = { -1,1,2,2,1,-1,-2,-2 };

//Ghi nhan ket qua
void print() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << banCo[i][j] << " ";
		}
		cout << endl;
	}
	cout << "=========================\n";
}

void nuocDi(int n, int i, int j) {
	for (int k = 0; k < 8; k++) {
		int dMoi = i + dd[k];
		int cMoi = j + dc[k];

		if (dMoi >= 0 && dMoi < SIZE && cMoi >= 0 && cMoi < SIZE && banCo[dMoi][cMoi] == 0) {
			banCo[dMoi][cMoi] = n;

			if (n == SIZE * SIZE)
				print();
			else
				nuocDi(n + 1, dMoi, cMoi);

			//Phuc hoi trang thai de tim loi giai moi
			banCo[dMoi][cMoi] = 0;
		}
	}
}

int main() {
	banCo[2][2] = 1;

	nuocDi(2, 2, 2);

	return 0;
}