#include <bits/stdc++.h>
using namespace std;

int main() {
	foreopen("string.in", "r", stdin);
	foreopen("string.out", "w", stdout);
	int n, a, y, z, q;
	string c, l, x;
	l = "";
	x = "";
	y = 0;
	q = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			x = x + c;
		}
		y += a;
		l += x;
		x = "";
	}
	z = ceil(y / 2);
	for (int p = 1; p <= z; p++) {
		if (l[0] != l[y - p]) {
			q += 1;
		}
	}
	cout << q;

	return 0;
}