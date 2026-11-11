#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
vector<int > g[N];
int dis[N];
bool vis[N];
void Bfs (int i, int j) {
	queue<int > q;
	q.push(i);
	for (int ii = 0; ii <= 1000000; ii++) {
		dis[ii] = -1;
		vis[ii] = false;
	}
	dis[i] = 0;
	vis[i] = true;
	while (!q.empty()) {
		int u = q.front();
		if (u == j) {
			break;
		}
		q.pop();
		if (vis[u]) {
			break;
		}
		for (int v : g[u]) {
			for (int k = 0; k < 4; k++) {
				int nx = v + dx[k];
				if (vis[nx] == 0 && dis[nx] < dis[i] + 1) {
					dis[nx] = dis[i] + 1;
					q.push(nx);
				}
			}
		}
	}
}
void solve () {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			Bfs(i, j);
			ans = min(ans, dis[n]);
		}
	}
	cout << ans;
	return;
}
signed main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; cin >> c >> t;
	while (t--) solve();
	return 0;
}
