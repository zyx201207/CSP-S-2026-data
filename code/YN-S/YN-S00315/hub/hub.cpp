#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX, n, k, f[20], dist[20], vis[20], fl[20];
vector<int>e[20];

int find(int x) {
	if (f[x] == x)
		return x;
	f[x] = find(f[x]);
	return f[x];
}

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		if (fl[i]) {
			q.push({0, i});
			dist[i] = 0;
		} else
			dist[i] = 1e9;
	}
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto v : e[u]) {
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				q.push({dist[v], v});
			}
		}
	}
}

void dfs(int u) {
	if (u == n + 1) {
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i++)
			f[i] = i, cnt += fl[i];
		if (cnt != k)
			return;
		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (fl[i])
				for (auto v : e[i])
					if (fl[v] && find(i) != find(v))
						f[find(i)] = find(v);
		for (int i = 1; i <= n; i++)
			if (fl[i])
				cnt += (f[i] == i);
		if (cnt > 2)
			return ;
		dijkstra();
		for (int i = 1; i <= n; i++)
			res = max(res, dist[i]);
		ans = min(ans, res);
		return;
	}
	fl[u] = 1;
	dfs(u + 1);
	fl[u] = 0;
	dfs(u + 1);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		cout << ans << '\n';
		ans = INT_MAX;
		for (int i = 1; i <= n; i++)
			e[i].clear();
	}
	return 0;
}
//100+24+8(?)+15 ,=(