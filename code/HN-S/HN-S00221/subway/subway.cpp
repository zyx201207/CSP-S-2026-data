#include <bits/stdc++.h>
using namespace std;

const long long INF = 100000000;

long long w[500001];

vector<pair<int, long long>> path[500001];

// dist[i][j]：把路径抽象成点，dist[i][j]即为第i条路径到第j条路径所用最短时间 
long long dist[500][500];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin.tie(NULL);
	
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j)
		dist[i][j] = INF;
		
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		while (k--) {
			int a; long long t; cin >> a >> t;
			path[a].push_back({i, t});
		}
	}
	
	for (int p = 0; p < m; p++)
		for (int i = 0; i < path[p].size(); i++) for (int j = 0; j < i; j++) {
			int u = path[p][i].first, v = path[p][j].first;
			dist[u][v] = dist[v][u] = min(dist[u][v], path[p][i].second + path[p][j].second);
		}
	
	// Floyd		
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++) if (i != k)
			for (int j = 0; j < n; j++) if (j != i && j != k) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
	
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y;
		long long mn = INF;
		for (auto r : path[x]) for (auto c : path[y])
			mn = min(mn, dist[r.first][c.first] + r.second + c.second);
		cout << mn + w[x] + w[y] << '\n';
	}
	
	return 0;
}
