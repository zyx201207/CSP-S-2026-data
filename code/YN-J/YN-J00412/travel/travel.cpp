#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, s, d, f;
	cin >> a >> s >> d >> f;
	long long q = 0;
	char z;
	char x;
	x = f[2];
	z = s[2];
	cout << z << " " << x;

	long long g = 0;
	if (a[0] != '0') {
		g = a[0] - '0';
		g = g * 10 + a[1] - '0';
	} else {
		g = a[1] - '0';
	}
	int h = 0;
	if (d[0] != '0') {
		h = d[0] - '0';
		h = h * 10 + d[1] - '0';
	} else {
		h = d[1] - '0';
	}
	if (g == h) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}

	for (long long i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			long long w = s[i] - '0';
			q = q * 10 + w;
		} else {

		}
	}
	long long r = 0;
	long long e = 0;
	for (long long i = 0; i < f.size(); i++) {
		if (f[i] <= '9' && f[i] >= '0') {
			long long r = f[i] - '0';
			e = e * 10 + r;
		} else {

		}
	}
	if (q == e) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		r = 1;
		return 0;
	}
	if (r == 0) {

	}
	if (z == x) {
		cout << 1 << 0;
		return 0;
	} else if (z >= 'A' && z <= 'C' && x >= 'A' && x <= 'C') {
		cout << 1;
		if (z - x == 1) {
			cout << 1;
			return 0;
		} else if (z - x == -1) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}

	} else if (z >= 'D' && z <= 'F' && x >= 'D' && x <= 'F') {
		cout << 1;
		cout << 1;
		return 0;
	} else {
		cout << 0 << 0;
	}
	return 0;
}