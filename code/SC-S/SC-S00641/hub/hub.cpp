#include <bits/stdc++.h>

using namespace std;
const int SZ = 456;

int c, TEST, mask;
int n, k;
bool vis[SZ];
int dist[SZ];
vector<int> adj[SZ];

void dfs (int u) {
	vis[u] = 1;
	for (int v : adj[u]) {
		if (vis[v]) continue;
		if (!(mask >> (u - 1) & 1)) continue;
		dfs(v);
	}
}

int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	cin >> c >> TEST;
	if (c > 3) return 0;
	while (TEST--) {
		cin >> n >> k;
		
		for (int i = 1; i <= n; i++) adj[i].clear();
		
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		int res = 2e9;
		for (mask = 0; mask < (1 << n); mask++) {
			if (__builtin_popcount(mask) != k) continue;
			memset(vis, 0, sizeof vis);
			int pp = 0;
			for (int i = 1; i <= n; i++) {
				if (!(mask >> (i - 1) & 1) || vis[i]) continue;
				pp++;
				if (pp > 2) break;
				dfs(i);
			}
			if (pp > 2) continue;
			
			queue<int> qq;
			memset(dist, 0x3f, sizeof dist);
			
			for (int i = 1; i <= n; i++) {
				if (!(mask >> (i - 1) & 1)) continue;
				dist[i] = 0;
				qq.push(i);
			}
			
			while (!qq.empty()) {
				int u = qq.front();
				qq.pop();
				for (int v : adj[u]) {
					if (dist[u] + 1 < dist[v]) {
						dist[v] = dist[u] + 1;
						qq.push(v);
					}
				}
			}
			
			int maxn = 0;
			for (int i = 1; i <= n; i++) {
				maxn = max(maxn, dist[i]);
			}
			
			res = min(res, maxn);
		}
		cout << res << '\n';
	}

	return 0;
}