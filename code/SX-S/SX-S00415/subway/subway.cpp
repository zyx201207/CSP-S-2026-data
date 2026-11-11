#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int w[N], vis[N];
vector<int> a[N], t[N];
long long u, v, mint;

void dfs(int x, int ts) {
	int xv, len;
	if (x == v) {
		mint = min(mint, 1ll * ts);
		return;
	}
	len = a[x].size();
	for (int i = 0; i < len; i++) {
		xv = a[x][i];
		if (!vis[xv]) {
			vis[xv] = 1;
			dfs(xv, ts + t[x][i]);
			vis[xv] = 0;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c, n, m, d, q, tt;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v >> tt;
			a[i].push_back(v);
			t[i].push_back(tt);
		}
	}
	while (q--) {
		cin >> u >> v;
		memset(vis, 0, sizeof(vis));
		vis[u] = 1;
		mint = LLONG_MAX;
		dfs(v, w[u]);
		cout << mint;
	}
	return 0;
}
