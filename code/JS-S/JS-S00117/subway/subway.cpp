#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], k[505], a[505][505], t[505][505];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", w + i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", k + i);
		for (int j = 1; j <= k[i]; ++j) {
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	if (n == 1) {
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", w[x] + w[y] + t[1][x] + t[1][y]);
		}
	}
	if (n == 2) {
		int c12;
		for (int i = 1; i <= k[1]; ++i) {
			for (int j = 1; j <= k[2]; ++j) {
				if (a[1][i] == a[2][j]) {
					c12 = a[1][i];
				}
			}
		}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			bool a1 = false, b1 = false, a2 = false, b2 = false;
			for (int i = 1; i <= k[1]; ++i) {
				if (a[1][i] == x) {
					a1 = true;
				}
				if (a[1][i] == y) {
					b1 = true;
				}
			}
			for (int i = 1; i <= k[2]; ++i) {
				if (a[2][i] == x) {
					a2 = true;
				}
				if (a[2][i] == y) {
					b2 = true;
				}
			}
			if (a1 && b1) {
				printf("%d\n", w[x] + w[y] + t[1][x] + t[1][y]);
			}
			else if (a2 && b2) {
				printf("%d\n", w[x] + w[y] + t[2][x] + t[2][y]);
			}
			else if (a1 && b2) {
				printf("%d\n", w[x] + w[y] + t[1][x] + t[2][y] + t[1][c12] + t[2][c12]);
			}
			else if (a2 && b1) {
				printf("%d\n", w[x] + w[y] + t[2][x] + t[1][y] + t[1][c12] + t[2][c12]);
			}
		}
	}
	return 0;
}
