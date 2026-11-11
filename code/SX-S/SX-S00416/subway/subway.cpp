#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = LLONG_MAX, a[100010], b[510][100000], v[100010], vis[5100];

void dfs(int x, int y, int k, long long s) {
	if (x == y) {
		ans = min(ans, s + b[k][y]);
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (b[k][i] && !v[i]) {
			v[i] = 1;
			dfs(i, y, k, s);
			v[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (b[i][x] && !vis[i]) {
			vis[i] = 1;
			dfs(x, y, i, s + b[k][x] + b[i][x]);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long y, x, q;
	cin >> n >> n >> m >> q >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		for (int j = 1; j <= x; j++) {
			cin >> y;
			cin >> b[i][y];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		v[x] = 1;
		for (int j = 1; j <= n; j++) {
			if (b[j][x]) {
				vis[j] = 1;
				dfs(x, y, j, a[x] + a[y] + b[j][x]);
				vis[j] = 0;
			}
		}
		v[x] = 0;
		cout << ans << endl;
		ans = LLONG_MAX;
	}
	return 0;
}
