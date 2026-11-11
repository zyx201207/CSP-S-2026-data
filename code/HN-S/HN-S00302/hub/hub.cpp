#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, k;
int ans = INT_MAX;
vector<int> q[1000010];
bool vis[1000010];
int dis[1010][1010];
int a[1000010];
void dfs(int u, int s, int fa) {
	for (int i = 0; i < q[u].size(); i++) {
		int v = q[u][i];
		if (v == fa) continue;
		dis[s][v] = dis[s][u] + 1;
		dfs(v, s, u);
	}
	return;
}
void dfs2(int u, int fa) {
	vis[u] = true;
	for (int i = 0; i < q[u].size(); i++) {
		int v = q[u][i];
		if (vis[v]) continue;
		dfs2(v, u);
	}
	return;
}
bool check() {
	for (int i = 1; i <= n; i++) vis[i] = true;
	for (int i = 1; i <= k; i++) vis[a[i]] = false;
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		if (!vis[a[i]]) {
			cnt++;
			if (cnt > 2) return false;
			dfs2(a[i], 0);
		}
	}
	return true;
}
void dfs1(int x, int cnt) {
	if (cnt > k) {
		if (!check()) return;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			int d = INT_MAX;
			for (int j = 1; j <= k; j++) {
				d = min(d, dis[i][a[j]]);
//				cout << i << ' ' << a[j] << ' ' << dis[i][a[j]] << endl;
			}
			res = max(res, d);
		}
		ans = min(ans, res);
		return;
	}
	if (x > n) return;
	dfs1(x + 1, cnt);
	a[cnt] = x;
	dfs1(x + 1, cnt + 1);
	return;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			q[u].push_back(v);
			q[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			dfs(i, i, 0);
		}
		dfs1(1, 1);
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) {
			q[i].clear();
			for (int j = 1; j <= n; j++) {
				dis[i][j] = 0;
			}
		}
		ans = INT_MAX;
	}
	return 0;
}
