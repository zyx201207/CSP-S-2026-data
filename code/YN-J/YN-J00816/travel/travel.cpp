#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int a1 = 0, b1 = 0, c1 = 0, d1 = 0;
	a1 += a[0] - '0';
	a1 *= 10;
	a1 += a[1] - '0';
	b1 += b[0] - '0';
	b1 *= 10;
	b1 += b[1] - '0';
	c1 += c[0] - '0';
	c1 *= 10;
	c1 += c[1] - '0';
	d1 += d[0] - '0';
	d1 *= 10;
	d1 += d[1] - '0';
	if (c1 == a1) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (b1 == d1 && c1 == a1) {
		cout << "1";
	} else {
		cout << "0";
	}
	int b2, d2;
	if (b[2] <= 'C') {
		b2 = 1;
	} else {
		b2 = 0;
	}
	if (d[2] <= 'C') {
		d2 = 1;
	} else {
		d2 = 0;
	}
	if (b2 == d2 && b1 == d1 && c1 == a1) {
		cout << "1";
	} else {
		cout << "0";
	}
	int n = abs(b[2] - d[2]);
	if (n == 1 && b2 == d2 && b1 == d1 && a1 == c1) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}