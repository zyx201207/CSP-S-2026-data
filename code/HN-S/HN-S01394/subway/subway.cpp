#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
const int N = 505;
const int M = 500005;
int c, n, m, d, q, w[M], len[M];
llong dist[N][N];
pair<int, int> bel[M][25];
vector<pair<int, llong> > e[N];
set<pair<llong, int> > s;
void dijkstra(int st) {
	memset(dist[st], 127, sizeof(dist[st]));
	dist[st][st] = 0;
	s.clear();
	for (int i = 1; i <= n; i++)
		s.insert({dist[st][i], i});
	while (!s.empty()) {
		int x = s.begin() -> second;
		s.erase(s.begin());
		for (auto i : e[x])
			if (dist[st][x] + i.second < dist[st][i.first]) {
				s.erase({dist[st][i.first], i.first});
				dist[st][i.first] = dist[st][x] + i.second;
				s.insert({dist[st][i.first], i.first});
			}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
		len[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int a, t;
			scanf("%d%d", &a, &t);
			bel[a][++len[a]] = {i, t};
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= len[i]; j++) {
			int u = bel[i][j].first, tu = bel[i][j].second;
			for (int k = j + 1; k <= len[i]; k++) {
				int v = bel[i][k].first, tv = bel[i][k].second; 
				e[u].push_back({v, 0LL + tu + tv});
				e[v].push_back({u, 0LL + tv + tu});
			}
		}
	for (int i = 1; i <= n; i++)
		dijkstra(i);
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		llong ans = 1LL << 60LL;
		for (int i = 1; i <= len[u]; i++) {
			int x = bel[u][i].first, tx = bel[u][i].second;
			for (int j = 1; j <= len[v]; j++) {
				int y = bel[v][j].first, ty = bel[v][j].second;
				ans = min(ans, 0LL + tx + dist[x][y] + ty);
			}
		}
		printf("%lld\n", 0LL + w[u] + ans + w[v]);
	}
	return 0;
}
