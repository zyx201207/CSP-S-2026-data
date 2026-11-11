#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300 + 5;
int n, d;
long long x[MAXN];
long long g[MAXN][MAXN], f[MAXN][MAXN];
int vis[MAXN], cnt[MAXN];
int st;

void dfs(int u, int now) {
	vis[u] = 1;
	if (now == f[st][u]) cnt[u]++;
	for (int v = 1; v <= n; v++) {
		if (vis[v] || g[u][v] != 1) continue;
		dfs(v, now + g[u][v]);
	}
	vis[u] = 0;
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = f[i][j] = (max(x[i] - x[j], x[j] - x[i]) <= d ? 1 : INT_MAX);
			if (i == j) g[i][j] = f[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	long long ans = 0;
	for (st = 1; st <= n; st++) {
		for (int j = 1; j <= n; j++) cnt[j] = 0;
		dfs(st, 0);
		for (int j = 1; j <= n; j++) {
			if (cnt[j] != 2) continue;
			ans++;
		}
	}
	cout << ans / 2 << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
}
