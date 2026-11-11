#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int N = 1005;
const int INF = 1e9;
int ans[N][N];
int dist[N];
bool vis[N];
vector<pii> g[N];
int n;
void dijkstra(int s) {
	for(int i = 1; i < N; i++) {
		dist[i] = INF;
		vis[i] = false;
	}
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dist[s] = 0;
	q.push({dist[s], s});
	while(!q.empty()) {
		auto tmp = q.top(); q.pop();
		int d = tmp.first; int u = tmp.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(auto t : g[u]) {
			int v = t.first; int w = t.second;
			if(dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		ans[s][i] = dist[i];
	}
}
void solve() {
	int k;
	cin >> n >> k;
	for(int i = 1; i < N; i++) g[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back({v, 1});
		g[v].push_back({u, 1});
	}
	for(int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	int res = 2e9;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int x = 0;
			for(int k = 1; k <= n; k++) {
				x = max(x, min(ans[i][k], ans[j][k]));
			}
			res = min(res, x);
		}
	}
	cout << res << endl;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int cid, t;
	cin >> cid >> t;
	while(t--) {
		solve();
	}
	return 0;
}
