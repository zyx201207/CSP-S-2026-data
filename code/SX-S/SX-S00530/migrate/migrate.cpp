#include <bits/stdc++.h>
using namespace std;
int c, t, x, n, d,  s, m, p;
int a[10000000], b[10000000], q[100000];

int l(int z, int q) {
	if (q - z == 2) {
		if (b[z] + b[z + 1] <= d  &&  b[z + 1] + b[z + 2] <= d)
			return 1;
	}
	if (q - z == 3) {
		if (b[z] + b[z + 1] + b[z + 2] <= d  &&  b[z + 1] + b[z + 2] + b[z + 3] <= d)
			return 1;
	}
	if (q - z == 4) {
		if (b[z] + b[z + 1] + b[z + 2] + b[z + 3] <= d  &&  b[z + 1] + b[z + 2] + b[z + 3] + b[z + 4] <= d)
			return 1;
	}
	return 0;
}

int f(int e, int f) {
	p = 0;
	for (int i = e; i <= f; i++) {
		for (int j = i + 2; j <= i + 4; j++) {
			p = p + l(i, j);
		}
	}
	if (p == 1)
		return 2;
	else
		return 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int j = 1; j <= t; j++) {
		x = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n - 1; i++) {
			b[i] = a[i + 1] - a[i];
			if (i >= 2) {
				if (b[i] == b[i - 1])
					x++;
			}
		}
		if (x == n - 2) {
			s = b[1];
			if (d < s * 2 || d >= s * 3)
				cout << 0 << endl;
			else
				cout << n - 3 << endl;
		} else {
			s = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 3; j <= n; j++) {
					if (f(i, j) == 2)
						s++;
				}
			}
			cout << s << endl;
		}
	}
}
