#include <bits/stdc++.h>
using namespace std;
int x, y, ans;
int w[500009], k[500009], v[500009];
bool a[10009][10009];
int c, n, m, d, q;

void dfs(int x, int b) {
	if (x == y) {
		ans = min(ans, b);
	}
	for (int i = 1; i <= m; i++) {
		if (a[x][i]) {
			a[x][i] = false, a[i][x] = false;
			dfs(i, b + v[x] + v[i]);
			a[x][i] = true, a[i][x] = true;
		}
	}
	return ;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		for (int j = 1; j <= s; j++) {
			cin >> k[i] >> v[i];
		}
		for (int j = 1; j < n; j++) {
			a[k[i]][k[i + 1]] = true;
			a[k[i + 1]][k[i]] = true;
		}
	}
	while (q--) {
		cin >> x >> y;
		ans = 1e9;
		dfs(x, w[x] + w[y]);
		cout << ans << endl;
	}
	return 0;
}