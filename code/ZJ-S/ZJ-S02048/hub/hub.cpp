#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, k;
vector<int> g[100001];

bool vis[101];
void dfs(int u, int msk) {
	if (vis[u] || ((msk >> (u-1)) & 1) == 0) return;
	vis[u] = 1;
	for (int v : g[u]) dfs(v, msk);
}

int dis[101][101];
void dfs2(int x, int u) {
	vis[u] = 1;
	for (int v : g[u]) if (!vis[v]) dfs2(x, v), dis[x][v] = dis[x][u] + 1;
}

void solve() {
	///cout << "a";
	memset(dis, 0x3f, sizeof(dis));
	cin >> n >> k;
	for (int i = 1;i <= n;i++) g[i].clear();
	for (int i = 1;i <= n-1;i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n <= 10) {
		int anssss = 1e18;
	for (int x = 0;x < ((1<<n)-1);x++) {
		if (__builtin_popcount(x) != k) continue;
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 1;i <= n;i++) {
			if (((x >> (i-1)) & 1) && !vis[i]) dfs(i, x), cnt++;
		}
		if (cnt > 2) continue;
		for (int i = 1;i <= n;i++) {
			memset(vis, 0, sizeof(vis));
			dis[i][i] = 0;
			dfs2(i, i);
		}
		int ans = -114514;
		for (int i = 1;i <= n;i++) {
			int minn = 1e18;
			for (int j = 1;j <= n;j++) {
				//cout << dis[i][j] << " ";
				if (((x >> (j-1)) & 1)) minn = min(minn, dis[i][j]);
			}
			ans = max(ans, minn);
		}
		anssss = min(anssss, ans);
		cout << anssss << "\n";
	}
	
	} 
	
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
