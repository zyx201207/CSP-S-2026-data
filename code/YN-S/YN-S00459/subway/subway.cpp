#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, x1, yy, ans;
const int N = 505;
const int M = 5e5 + 5;
const int NM = 2e4 + 5;
int w[M], k[N], a[N][NM], t[N][NM], b[M];
void dfs(int z, int x, int y, int ti) {
	if (z == yy) {
		ans = min(ans, ti + t[x][y]);
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (i != x && a[i][j] == z)
				dfs(z, i, j, ti + t[x][y] + t[i][j]);
		}
	}
	for (int j = 1; j <= k[x]; j++) {
		if (b[a[x][j]] == 0) {
			b[a[x][j]] = 1;
			dfs(a[x][j], x, j, ti);
			b[a[x][j]] = 0;
		}
	}

}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= q; i++) {
		ans = INT_MAX;
		memset(b, 0, sizeof(b));
		cin >> x1 >> yy;
		b[x1] = 1;
		dfs(x1, 0, 0, w[x1] + w[yy]);
		cout << ans << "\n";
	}
	return 0;
}
/*
Wantong is played by laosou.
*/