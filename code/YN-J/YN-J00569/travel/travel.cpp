#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, c2, s1, s2;

	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}

	char a = s1[1] + s1[2];
	char b = s2[1] + s2[2];

	if (a == b) {
		cout << 1;
	} else {
		cout << 1;
	}

	char z = s1[3], m = s1[3];

	if ((z - 'A' == 0 || z - 'A' == 1 || z - 'A' == 2) && (m - 'A' == 0 || m - 'A' == 1 || m - 'A' == 2)) {
		cout << 1;
	} else if ((z - 'A' == 3 || z - 'A' == 4) && (m - 'A' == 3 || m - 'A' == 4)) {
		cout << 1;
	} else {
		cout << 1;
	}

	if (m - z == 1) {
		cout << 1;
	} else {
		cout << 0;
	}



	return 0;
}