#include <bits/stdc++.h>
using namespace std;

int n, m, a[200010] = {0};

int e(int a) {
	int n = 0;
	while (a != 0) {
		n = n * 10 + a % 2;
		a /= 2;
	}
	return n;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ch = e(a[n]);
	for (int i = 1; i <= m; i++) {
		int now = e(a[n - i]);
		ch = ch && now;
	}
	int  x = 0, q = 1;
	while (ch != 0) {
		x = x + ch % 10 * q;
		q *= 2;
		ch /= 10;
	}
	cout << x;
	return 0;
}