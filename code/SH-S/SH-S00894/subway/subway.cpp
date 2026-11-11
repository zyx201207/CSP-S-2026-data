#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("subway.in");
ofstream fout("subway.out");
using i64 = long long;
constexpr int MAX_STATION = 5e5 + 5;
constexpr int MAX_LINE = 505;
constexpr i64 INF = 1e18;
int w[MAX_STATION];
vector<pair<int, i64> > G[MAX_STATION];
i64 dis[MAX_LINE][MAX_LINE];
int main() {
	int c, n, m, d, q;
	fin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) fin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k;
		fin >> k;
        for (int j = 1; j <= k; ++j) {
            int u;
            i64 t;
            fin >> u >> t;
            G[u].push_back({i, t});
        }
	}
	for (int u = 1; u <= n; ++u) {
		fill(dis[u] + 1, dis[u] + n + 1, INF);
		dis[u][u] = 0;
	}
	for (int u = 1; u <= m; ++u)
		for (int pos1 = 0; pos1 < int(G[u].size()); ++pos1)
			for (int pos2 = 0; pos2 < int(G[u].size()); ++pos2) {
				pair<int, i64> x1 = G[u][pos1], x2 = G[u][pos2];
				dis[x1.first][x2.first] = min(dis[x1.first][x2.first], x1.second + x2.second);
			}
	for (int mid = 1; mid <= n; ++mid)
		for (int u = 1; u <= n; ++u)
			for (int v = 1; v <= n; ++v) {
				if (dis[u][mid] == INF) continue;
				if (dis[mid][v] == INF) continue;
				dis[u][v] = min(dis[u][v], dis[u][mid] + dis[mid][v]);
			}
	while (q--) {
		int u, v;
		fin >> u >> v;
		i64 ans = INF;
		for (const pair<int, i64>& x1 : G[u])
			for (const pair<int, i64>& x2 : G[v]) {
				if (dis[x1.first][x2.first] == INF) continue;
				ans = min(ans, x1.second + dis[x1.first][x2.first] + x2.second);
			}
		fout << w[u] + ans + w[v] << '\n';
	}
	return 0;
}
