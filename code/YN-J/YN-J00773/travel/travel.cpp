#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2, shu;
	cin >> c1 >> s1 >> c2 >> s2;
	int c = 0;

	if (c1 == c2) {
		shu += '1';
		c = 1;
	} else {
		shu += '0';
	}

	string a, b;
	a = s1[0] + s1[1];
	b = s2[0] + s2[1];

	if (a == b && c == 1) {
		shu += '1';
		c = 2;
	} else {
		shu += '0';
	}

	bool zuo, zuo1;

	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
		zuo = 1;
	} else {
		zuo = 0;
	}

	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
		zuo1 = 1;
	} else {
		zuo1 = 0;
	}

	if (zuo == zuo1 && c == 2) {
		shu += '1';
		c = 3;
	} else {
		shu += '0';
	}

	int cha = abs(s1[2] - s2[2]);

	if (cha == 1 && c == 3) {
		shu += '1';
	} else {
		shu += '0';
	}

	cout << shu;
	return 0;
}
