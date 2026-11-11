#include <bits/stdc++.h>
using namespace std;
int c1, s1, c2, s2, c = 0, d = 0, b = 0, a = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1, s1, c2, s2;
	if (c1 == c2) {
		c = 1;
	} else {
		c = 0;
	}
	if (s1 / 10 == s2 / 10) {
		d = 1;
	} else {
		d = 0;
	}
	if (s1 % 10 + s2 % 10 == 'AB' || 'BC' || 'AC' || 'FD') {
		b = 1;
	} else {
		b = 0;
	}
	if (s1 % 10 == s2 % 10 + 1 || s1 % 10 + 1 == s2 % 10) {
		a = 1;
	} else {
		a = 0;
	}
	cout << c << d << b << a;
	return 0;
}