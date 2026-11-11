#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int M = 2005;
const long long INF = 1e18;
int a[M];
vector<pii> g[M];
long long dist[M];
bool vis[M];
long long ans[M][M];
int m;
void dijkstra(int s) {
	for(int i = 1; i < M; i++) {
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
	for(int i = 1; i <= m; i++) {
		ans[s][i] = dist[i];
	}
}
//1 ~ m is special point
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	int cnt = m;
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int x, t;
			cin >> x >> t;
			cnt++;
			g[x].push_back({cnt, t});
			g[cnt].push_back({x, t});
			if(j > 1) {
				g[cnt].push_back({cnt - 1, 0});
				g[cnt - 1].push_back({cnt, 0});
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		dijkstra(i);
	}
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << ans[u][v] + a[u] + a[v] << endl;
	}
	return 0;
}
