#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k[501], a[501][500001], x, y;
long long w[100001], t[501][500001], minn = 1e10, tot = 0;

void dfs(int x, int y, long long tot, int wz) {
	if (wz == y) {
		minn = min(minn, tot);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (a[i][j] == wz && a[i][j + 1] <= y) {
				for (int f = j; f <= k[i]; f++) {
					dfs(x, y, tot + t[i][j] + t[i][f], a[i][f]);
				}
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		dfs(x, y, w[x] + w[y], x);
		cout << tot;
	}
	return 0;
}
