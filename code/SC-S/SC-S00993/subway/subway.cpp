#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int t[500005];
int dis[500505];
bool vis[500505];
vector<pair<int, int> > G[500505];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
void dijk(int st, int to) {
	while (!Q.empty())
		Q.pop();
	for (int i = 1; i <= n + m; i++)
		dis[i] = LONG_LONG_MAX / 2, vis[i] = false;
	dis[st] = 0;
	Q.push({0, st});
	while(!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if (u == to) {
			cout << dis[u] + t[st - n] + t[u - n] << "\n";
			return;
		}
		if (vis[u]) 
			continue;
		vis[u] = true;
		for (auto k : G[u]) {
			int v = k.first, w = k.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				Q.push({dis[v], v});
			}
		}
	}
	return;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> t[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int v, w;
			cin >> v >> w;
			G[i].push_back({n + v, w});
			G[n + v].push_back({i, w});
		}
	}
	if (20 <= c && c <= 21) {
		int dist = LONG_LONG_MAX;
		for (int i = n + 1; i <= m; i++) {
			if (G[i].size() == 2) {
				int tot = 0;
				for (auto k : G[i])
					tot += k.second;
				dist = min(dist, tot);
			}
		}
		cout << dist << " ";
		int ans = LONG_LONG_MAX;
		while(q--) {
			int u, v;
			cin >> u >> v;
			for (auto i : G[u + n])
				for (auto j : G[v + n]) {
					if (i.first == j.first) ans = min(ans, i.second + j.second);
					else ans = min(ans, i.second + j.second + dist);
				}
			
			cout << ans + t[u] + t[v] << "\n";
		}
	} else {
		while (q--) {
			int u, v;
			cin >> u >> v;
			dijk(u + n, v + n);
		}
	}
	return 0;
}