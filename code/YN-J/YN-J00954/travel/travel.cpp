#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c[20] = {0};
	gets(c);
	int c_len = strlen(c);

	if ((c[0] == c[7]) && (c[1] == c[8])) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if ((c[3] == c[10]) && (c[4] == c[11])) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}

	if ((c[5] == 'F' && c[12] == 'D') || (c[5] == 'D' && c[12] == 'F')) {
		cout << "11";
	} else if (c[5] == 'A' && c[12] == 'B') {
		cout << "11";
	} else if (c[5] == 'A' && c[12] == 'C') {
		cout << "10";
	} else if (c[5] == 'B' && c[12] == 'A') {
		cout << "11";
	} else if (c[5] == 'B' && c[12] == 'c') {
		cout << "11";
	} else if (c[5] == 'C' && c[12] == 'A') {
		cout << "10";
	} else if (c[5] == 'C' && c[12] == 'B') {
		cout << "11";
	} else {
		cout << "00";
	}
	return 0;
}