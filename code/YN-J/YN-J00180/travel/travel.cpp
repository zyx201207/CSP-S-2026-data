#include <bits/stdc++.h>
using namespace std;
int c1, c2, s1, s2;

bool check(char a, char b ) {
	if (a >= 'A' and a <= 'C') {
		return 1;
	} else {
		return 0;
	}
	if (b >= 'A' and b <= 'C') {
		return 0;
	}	else {
		return 1;
	}
}
signed main() {
	freopen("travel.in", "I", stdin)
	freopen("travel.out", "W", stdout)
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0000";
	}
	string ss1 = "", ss2 = "";
	for (string i = 0; i <= 2; i++) {
		ss1 += s1[i];
		ss2 += s2[i];
	}
	if (ss1 = ss2) {
		cout << "1";
	} else {
		cout << "000";
	}
	return 0;
	if (check s[1][2], s2[2] == 1) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	return 0;
	if (check[s1][2], s2[2] == 1) {
		cout << "1";
	} else {
		cout << "0";
		return 0;
	}
	return 0;
}
