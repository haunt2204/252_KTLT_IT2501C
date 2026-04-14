#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void delSpace(char *str) {
	int len = strlen(str);
	//Xoa o dau chuoi
	while (isspace(str[0])) {
		for (int i = 0; i < len; i++) {
			str[i] = str[i + 1];
		}
		len--;
	}
	//Xoa o cuoi chuoi
	while (isspace(str[len - 1])) {
		str[len - 1] = '\0';
		len--;
	}
	//Xoa khoang trang o giua chuoi
	for (int i = 0; i < len; i++) {
		if (isspace(str[i]) && isspace(str[i + 1])) {
			for (int j = i; j < len; j++) {
				str[j] = str[j + 1];
			}
			len--;
			i--;
		}
	}
}

char* delSpaceN(char *str) {
	char *res = new char[strlen(str)];
	res[0] = '\0';
	char *p = strtok(str, " ");

	while (p!=NULL) {
		strcat(res, p);
		p = strtok(NULL, " ");
		if(p!=NULL)
			strcat(res, " ");
	}
	
	return res;
}

void capital(char *str) {
	int len = strlen(str);
	str[0] = toupper(str[0]);
	for (int i = 1; i < len; i++) {
		if (isspace(str[i - 1]))
			str[i] = toupper(str[i]);
		else
			str[i] = tolower(str[i]);
	}
}

char* normalize(char *str) {
	//Xoa khoang trang du thua
	//delSpace(str);
	char *res = delSpaceN(str);
	//Viet hoa ky tu dau tien
	capital(res);

	return res;
}

int main() {
	char str[] = "  tRuong dAi    hOC   Mo     ";

	/*normalize(str);

	cout << str << endl;*/
	char *res = normalize(str);
	cout << res << endl;

	delete[]res;
	return 0;
}
