#include <bits/stdc++.h>
// Oh fuck this program cannot be run in this conputer.
// I don't know my point.
// I will die
// This is my last ccf csp travel
// goodbye
using namespace std;
const int N = 5e5 + 5;
bool vis[N];
int dis[N];
int w[N];
int k[N];
int a[505][N], t[505][N];
vector<pair<int, int>> adj[N];
int dijkstra(int s, int e) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // first距离 second点 
	pq.push({0, s});
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	while(pq.size()) {
		int u = pq.top().first;
		pq.pop();
		if(vis[u]) {
			continue;
		}
		vis[u] = true;
		for(auto& t : adj[u]) {
			int v = t.first;
			int w = t.second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
			}
			if(!vis[v]) {
				pq.push({dis[v], v});
			}
		}
	}
	return dis[e] + w[s] + w[e];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, m, n, d, q;               // 测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	cin >> c >> m >> n >> d >> q;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	int cnt = n + 1;
	for(int i = 1; i <= m; i++) {
		cin >> k[i];
		int ne = cnt++;
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			adj[ne].push_back({a[i][j], t[i][j]});
			adj[a[i][j]].push_back({ne, t[i][j]});
		}
	}
	while(q--) {
		int s, e;
		cin >> s >> e;
		cout << dijkstra(s, e) << "\n";
	}
	return 0;
}

