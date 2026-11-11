#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int dep[N], buc[N];
int n, d, a[N], vis[N], awa[N];
vector<int> g[N];
void dfs(int u, int fa) {
	dep[u] = 1;
	for (int v : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		dep[v] = dep[u] + 1;
	}
}
void build(int i) {
	if (i > n) return;
	int j = i + 1;
	while (j <= n && a[j] - a[i] <= d) {
		g[a[i] + vis[i] * n + 10000].push_back(a[j] + vis[j] * n + 10000);
		g[a[j] + vis[j] * n + 10000].push_back(a[i] + vis[i] * n + 10000);
		build(j);
		vis[j]++;
		j++;
	}
	i--;
	vis[i]++;
}
void solve() {
	memset(vis, 0, sizeof(vis));
	memset(dep, 0, sizeof(dep));
	memset(buc, 0, sizeof(buc));
	memset(awa, 0, sizeof(awa));
	for (int i = 1; i <= 10000; i++) g[i].clear();
	cin >> n >> d;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10000; j++) g[j].clear();
		memset(vis, 0, sizeof(vis));
		memset(dep, 0, sizeof(dep));
		build(i);
		dfs(a[i], 0);
		for (int j = 1; j < N; j++) 
			buc[dep[j]]++;
		for (int j = 1; j < N; j++) {
			if (buc[j] == 2) ans++;
		}
	}
	cout << ans << endl;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}