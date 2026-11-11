#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;
const ll inf = 1e18;
const int N = 505;
const int M = 5e5 + 10;
const int T = N + M;
int c, n, m, d, q;
ll wei[M];
ll G[505][505];
vector<PLL> sta[M]; // station
inline void add(ll u, ll v, ll w) {
	G[u][v] = min(G[u][v], w);
	G[v][u] = min(G[v][u], w);
}
ll dis[505][505]; bool vis[505][505];
vector<PLL> g[505];
void Dijkstra(ll st) {
	for (ll i = 1; i <= n; i ++) {
		dis[st][i] = inf; vis[st][i] = 0;
	}
	priority_queue<PLL, vector<PLL>, greater<PLL> > heap;
	dis[st][st] = 0;
	heap.push({0, st});
	while (!heap.empty()) {
		ll u = heap.top().second; heap.pop();
		if (vis[st][u]) continue;
		vis[st][u] = 1;
		for (auto it: g[u]) {
			ll v = it.first, w = it.second;
			if (dis[st][u] + w < dis[st][v]) {
				dis[st][v] = dis[st][u] + w;
				heap.push({dis[st][v], v});
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++) {
		scanf("%lld", &wei[i]);
	}
	for (int i = 1; i <= n; i ++) {
		int len, a; ll t; scanf("%d", &len);
		for (int j = 1; j <= len; j ++) {
			scanf("%d %lld", &a, &t);
			sta[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			G[i][j] = inf;
		}
		G[i][i] = 0;
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 0; j < (int)sta[i].size(); j ++) {
			for (int k = j + 1; k < (int)sta[i].size(); k ++) {
				// sta[i][j].first <-> sta[i][k].first
				// wei: sta[i][j].second + sta[i][k].second
				add(sta[i][j].first, sta[i][k].first
				, sta[i][j].second + sta[i][k].second);
			}
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) 
			if (G[i][j] != inf) {
				g[i].push_back({j, G[i][j]});
			}
	for (int i = 1; i <= n; i ++)
		Dijkstra(i);
	for (int ti = 1; ti <= q; ti ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x == y) {
			printf("0\n");
			continue;
		}
		ll ans = 1e18;
		for (auto i: sta[x]) {
			for (auto j: sta[y]) {
				ans = min(ans, dis[i.first][j.first] + i.second + j.second);
			}
		}
		printf("%lld\n", wei[x] + wei[y] + ans);
	}
	return 0;
}
