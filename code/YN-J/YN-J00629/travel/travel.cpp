#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int f = 0;
	if (c1 == c2) {
		f = 1;
		cout << 1;
	} else {
		cout << 0;
	}
	int a = 0, b = 0;
	if (s1[0] == s2[0] && s1[1] == s2[1] && f == 1) {
		a = 1;
		cout << 1;
	} else {
		cout << 0;
	}
	if (s1[2] >= 'A' && s1[2] <= 'C' && a == 1) {
		if (s2[2] >= 'A' && s2[2] <= 'C') {
			b = 1;
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		if (s2[2] == 'D' || s2[2] == 'F') {
			b = 1;
			cout << 1;
		} else {
			cout << 0;
		}
	}
	int c, d, e;
	c = s1[2] - 48 + 1;
	d = s1[2] - 48 - 1;
	e = s2[2] - 48;
	if (a == 1 && b == 1 && c == e) {
		cout << 1;
	} else {
		if (a == 1 && b == 1 && d == e ) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}