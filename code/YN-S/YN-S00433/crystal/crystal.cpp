#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, a[50005], b[50005], c = 100000000002, d, e, y[50005];
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int x = 1; x <= n; x++) {
		c = 100000000002;
		for (int i = 1; i <= n; i++) {
			if (a[i] < c) {
				c = a[i];
				d = i;
			}
		}
		a[d] = 100000000003;
		b[x] = c;
	}
	for (int i = 1; i <= n; i++) {
		y[i] = b[i];
	}
	int r = b[1], f = 0, g = 0, x = 1;
	d = b[n / 2];
	for (int i = 2; i <= n; i++) {
		if (r == y[i]) {
			f++;
		}
		if (f > g) {
			g = f;
			d = r;
			x = i;
		}
		r = y[i];
	}
	int h = m, j = m;
	r = b[x];
	int l;
	if (n % 2 == 0) {
		e = b[n / 2];
		l = n / 2;
	} else {
		e = b[n / 2 + 1];
		l = n / 2 + 1;
	}
	while (h >= 1 || j >= 1) {
		if (b[l] != e && h > 0) {
			b[l]++;
			h--;
		} else {
			l--;
		}
		if (y[r] != d && j > 0) {
			y[r]++;
			j--;
		} else {
			r--;
		}
	}
	r = b[1];
	f = 1;
	g = 1;
	d = 0;
	x = 0;
	for (int i = 2; i <= n; i++) {
		if (r == b[i]) {
			f++;
		}
		if (f > g) {
			g = f;
		}
	}
	d = g;
	r = b[1];
	f = 1;
	g = 1;
	for (int i = 2; i <= n; i++) {
		if (r == y[i]) {
			f++;
		}
		if (f > g) {
			g = f;
		}
	}
	x = g;
	if (d > x) {
		cout << d;
	} else {
		cout << x;
	}
	return 0;
}