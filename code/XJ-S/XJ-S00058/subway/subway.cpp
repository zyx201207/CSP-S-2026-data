#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int c, n, m, d, q, w[maxn], a[510][maxn], t[510][maxn];
vector <PII> G[maxn];
int dis[510][510], vis[510][510];
void dijkstra(int s) {
	for(int j = 1; j <= m; j ++) {
		dis[s][j] = INF;
	}
	dis[s][s] = t[s][s];
	memset(vis, 0, sizeof vis);
	priority_queue<PII, vector <PII>, greater <PII> > q;
	q.push({dis[s][s], s});
	vis[s][s] = 1;
	while(q.size()) {
		PII f = q.top();
		int u = f.second;
		q.pop();
//		cout << u << ' ';
		if(!vis[u]) {
			continue;
		}
		vis[s][u] = 1;
		for(int i = 0; i < G[u].size(); i ++) {
			PII it = G[u][i];
			int v = it.first;
			int w = it.second + t[v][v];
			if(dis[s][u] + w < dis[s][v]) {
				vis[s][v] = 1;
				dis[s][v] = dis[s][u] + w;
				q.push({dis[s][v], v});
			}
		}
	}
//	cout << "\nn\n";
}
int main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for(int i = 1, k; i <= n; i ++) {
		cin >> k;
		for(int j = 1; j <= k; j ++) {
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 2; j <= k; j ++) {
			G[a[i][j - 1]].push_back({a[i][j], t[a[i][j]]][a[i][j - 1]});
		}
	}

	for(int i = 1; i <= m; i ++) {
		dijkstra(i);
	}
//	for(int i = 1; i <= m; i ++) {
//		for(int j = 1; j <= m; j ++) {
//			cout << dis[i][j] << ' ';
//		}
//		cout << "\n";
//	}

	while(q --) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + dis[x][y] - t[y][y] << "\n";
	}

	return 0;
}

