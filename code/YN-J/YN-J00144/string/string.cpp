#include <bits/stdc++.h>
using namespace std;

string jia(string a, string b) {
	int al = a.size(), bl = b.size();
	char c[100] = {}, d[100] = {}, e[100] = {};
	for (int i = 0; i < al; i++) {
		c[i] = a[al - 1 - i];
	}
	for (int i = 0; i < bl; i++) {
		d[i] = b[bl - 1 - i];
	}
	if (al == 0) {
		return b;
	} else if (bl == 0) {
		return a;
	}
	int x1 = 0, zl = max(al, bl);
	for (int i = 0; i < zl; i++) {
		int a1 = c[i] - '0', b1 = d[i] - '0';
		int z = a1 + b1 + x1;
		x1 = z / 10;
		if (x1 != 0 && i == zl - 1) {
			zl++;
		}
		e[i] = z % 10 + '0';
	}
	string s;
	for (int i = zl - 1; i >= 0; i--) {
		s += e[i];
	}
	return s;
}

string jian(string a, string b) {
	int al = a.size(), bl = b.size();
	char c[100] = {}, d[100] = {}, e[100] = {};
	for (int i = 0; i < al; i++) {
		c[i] = a[al - 1 - i];
	}
	for (int i = 0; i < bl; i++) {
		d[i] = b[bl - 1 - i];
	}
	int x1 = 0, zl = max(al, bl);
	for (int i = 0; i < zl; i++) {
		int a1 = c[i] - '0', b1 = d[i] - '0', z;
		if (a1 - x1 < b1) {
			z = a1 - x1 - b1 + 10;
			x1 = 1;
		} else {
			z = a1 - x1 - b1;
			x1 = 0;
		}
		e[i] = z + '0';
	}
	string s;
	bool f3 = true;
	for (int i = zl - 1; i >= 0; i--) {
		if (f3 && e[i] == '0') {
		} else {
			s += e[i];
			f3 == false;
		}
	}
	if (f3) {
		s = "0";
		return s;
	}
	return s;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a2, b2;
	cin >> n;
	char a[200005];
	char b[200005];
	for (int i = 1; i <= n; i++) {
		cin >> a2 >> b[i];
		a[i] = a2;
	}
	long long c, d, nn;
	string g = "", gg = "", ggg = "", x = "", x2 = "" ;
	gg += a[1];
	ggg += a[n];
	int l = 2, r = n - 1;
	bool f1 = false;
	bool f2 = false;
	if (int(a[1]) >= int(a[n])) {
		x = jian(gg, ggg);
		l = 1;
		f1 = true;
	} else {
		x = jian(ggg, gg);
		r = n;
		f2 = true;
	}
	if (b[1] != b[n]) {
		g = jia(g, x);
	} else {
		g = "0";
	}
	while (l <= r) {
		c = int(a[l]);
		d = int(a[r]);
		string gm = "", gm2 = "";
		gm += a[l];
		gm2 += a[r];
		long long x3 = nn;
		if (b[l] == b[r]) {
			if (c >= d && !f1) {
				x = jian(gm, gm2);
				nn = c - d;
				r--;
				f1 = true;
				f2 = false;
			} else if (x3 >= d && f1) {
				x = jian(x, gm2);
				nn = x3 - d;
				r--;
				f1 = true;
				f2 = false;
			} else if (x3 < d && f1) {
				x = jian(gm2, x);
				nn = d - x3;
				l++;
				f1 = false;
				f2 = true;
			} else if (c < d && !f2) {
				x = jian(gm2, gm);
				nn = d - c;
				l++;
				f2 = true;
				f1 = false;
			} else if (x3 >= c && f2) {
				x = jian(x, gm);
				nn = x3 - c;
				l++;
				f1 = false;
				f2 = true;
			} else if (x3 < c && f2) {
				x = jian(gm, x);
				nn = c - x3;
				r++;
				f1 = true;
				f2 = false;
			}
		} else {
			if (c >= d && !f1) {
				x = jian(gm, gm2);
				x2 += a[r];
				r--;
				f1 = true;
				f2 = false;
			} else if (x3 >= d && f1) {
				x = jian(x, gm2);
				x2 += a[r];
				r--;
				f1 = true;
				f2 = false;
			} else if (x3 < d && f1) {
				x = jian(gm2, x);
				x2 = x;
				l++;
				f1 = false;
				f2 = true;
			} else if (c < d && !f2) {
				x = jian(gm2, gm);
				x2 += a[l];
				l++;
				f2 = true;
				f1 = false;
			} else if (x3 >= c && f2) {
				x = jian(x, gm);
				x2 += a[l];
				l++;
				f1 = false;
				f2 = true;
			} else if (x3 < c && f2) {
				x = jian(gm, x);
				x2 = x;
				r++;
				f1 = true;
				f2 = false;
			}
			g = jia(g, x2);
			x2 = "";
		}
	}
	cout << g;
	return 0;
}