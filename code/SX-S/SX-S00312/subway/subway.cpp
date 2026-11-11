#include <bits/stdc++.h>
using namespace std;
int w[500005];
int ln[505][505], a[505], b[505], M = INT_MAX / 2;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) {
				ln[i][j] = 0;
			} else
				ln[i][j] = M;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> b[j];
			for (int l = 1; l <= j; l++) {
				if (j == l)
					continue;
				ln[a[j]][a[l]] = b[l] + b[j];
				ln[a[l]][a[j]] = b[l] + b[j];
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			if (i == k)
				continue;
			for (int j = 1; j <= m; j++) {
				if (i == j || j == k)
					continue;
				if (ln[i][j] > ln[i][k] + ln[k][j]) {
					ln[i][j] = ln[i][k] + ln[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + ln[x][y] << endl;
	}
	return 0;
}
