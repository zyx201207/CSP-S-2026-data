#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()

const int inf = LONG_LONG_MAX;
int n, k, ans;
vector<vector<int>>G, dis;
vector<int>dep, s;
vector<bool>vis, ok;

void dfs_dis(int root, int u, int fa, int step) {
	dis[root][u] = step;
	for (auto v : G[u]) {
		if (v == fa)	continue;
		dfs_dis(root, v, u, step + 1);
	}
}

void dfs_t(int u, int fa) {
	ok[u] = 1;
	for (auto v : G[u]) {
		if (v == fa || !vis[v])	continue;
		dfs_t(v, u);
	}
}

void dfs() {
	if (s.size() == k) {
		ok.assign(n + 5, 0);
		int cnt = 0, maxx = -1;
		for (auto x : s)
			if (!ok[x]) {
				cnt++;
				dfs_t(x, 0);
			}
		if (cnt > 2)	return;
		for (int i = 1; i <= n; i++) {
			int d = inf;
			for (auto x : s)
				d = min(d, dis[i][x]);
			if (d != inf)
				maxx = max(maxx, d);
		}
		if (maxx != -1)
			ans = min(ans, maxx);
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			s.push_back(i);
			vis[i] = 1;
			dfs();
			vis[i] = 0;
			s.pop_back();
		}
}

void work() {
	ans = inf;
	cin >> n >> k;
	s.clear();
	G.assign(n + 5, vector<int>());
	vis.assign(n + 5, 0);
	dis.assign(n + 5, vector<int>(n + 5, 0));
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		dfs_dis(i, i, 0, 0);
	dfs();
	cout << ans << "\n";
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1, c;
	cin >> c >> T;
	while (T--)	work();
	return 0;
}
/*

*/