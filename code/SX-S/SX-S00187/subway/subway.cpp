#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500005];
int z[501];
int a[505][50005];
int t[505][50005];




int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c;
	if (c >= 7 && c <= 11) {
		cin >> n >> m >> d >> q;

		for (int i = 1; i <= m; i++) {
			cin >> w[i];
		}
		int ww[m + 1][m + 1];
		memset(ww, INT_MAX, sizeof(ww));
		for (int i = 1; i <= n; i++) {
			cin >> z[i];
			int u, v, w1, w2;
			cin >> u >> w1 >> v >> w2;
			if (u <= v)
				ww[u][v] = w1 + w2;
			else
				ww[v][u] = w1 + w2;
		}

		for (int i = 1; i <= m; i++) {
			for (int j = i + 1; j <= m; j++) {
				for (int k = 1; k <= m; k++) {
					if (k == i || k == j)
						continue;
					if (ww[min(i, k)][max(i, k)] != INT_MAX && ww[min(j, k)][max(j, k)] != INT_MAX) {
						ww[i][j] = min(ww[i][j], ww[min(i, k)][max(i, k)] + ww[min(j, k)][max(j, k)]);

					}
				}
			}
			while (q--) {
				int qd, zd;
				cin >> qd >> zd;
				cout << ww[min(qd, zd)][max(qd, zd)] << endl;
			}
		}

	}
}
