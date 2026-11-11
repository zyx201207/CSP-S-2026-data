#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card1.in", "r", stdin);
	freopen("card1.out", "w", stdout);
	int m, n, a, b[10086], s = 0, p[10086] = {};
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		b[i] = a;
	}
	int y = 1, t = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int o = y; o <= m; o++) {
				if (b[o] == i) {
					s = 1;

				}
			}
			y++;
			if (y > m) {
				y--;
			}
			p[i] += s;
			s = 0;
		}
		y = t + 1;

	}
	for (int i = 1; i <= n; i++) {
		cout << p[i] << " ";
	}
	return 0;
}