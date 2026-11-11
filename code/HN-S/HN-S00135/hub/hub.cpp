#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
using namespace std;
int n, k, ans, f[4005];
int vis[4005], dis[4005];
vector<int> e[4005];
void ddfs(int u, int fa) {
	vis[u] = 1;
	for (auto v : e[u]) {
		if (v == fa) continue;
		if (!f[v]) continue;
		ddfs(v, u);
	}
}
void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			vis[i] = 0;
			dis[i] = inf;
		} else {
			vis[i] = 1;
			dis[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : e[u]) {
			if (vis[v]) continue;
			vis[v] = 1, dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}
void dfs(int now, int cnt) {
	if (cnt >= k) {
		int c = 0;
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= n; i++) {
			if (f[i] && !vis[i]) {
				ddfs(i, 0);
				c++;
			}
		}
		if (c > 2) return;
		bfs();
		int mx = 0;
		for (int i = 1; i <= n; i++) mx = max(mx, dis[i]);
		ans = min(ans, mx);
		return;
	}
	if (now >= n) return;
	for (int i = now + 1; i <= n; i++) {
		f[i] = 1;
		dfs(i, cnt + 1);
		f[i] = 0;
	}
}
void solve() {
	cin >> n >> k, ans = inf;
	for (int i = 1; i <= n; i++) {
		e[i].clear();
		f[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(0, 0);
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T = 1, c;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}

