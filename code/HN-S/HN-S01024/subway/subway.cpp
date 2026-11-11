#include <bits/stdc++.h>

using ll = long long;
#define f first
#define s second
#define pb push_back
const int inf = (1 << 30) - 1;
const ll INF = 1ll << 60;

const int N = 5e5 + 10;
struct node {
	ll d;
	int u;
	bool operator < (const node &A) const {
		return d > A.d;
	}
};
int c, n, m, d, Q, w[N], k[510];
ll dis[510], dist[510][510];
std::priority_queue<node> q;
std::vector<std::pair<int, int>> g[510], id[N];

void dijkstra(int s) {
	std::fill(dis + 1, dis + n + 1, INF);
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		ll d = q.top().d;
		int u = q.top().u;
		q.pop();
		if (d > dis[u]) continue;
		for (auto &y : g[u]) {
			int v = y.f, w = y.s;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v}); 
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) std::cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int lst = 0;
		std::cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int v, w;
			std::cin >> v >> w;
			id[v].pb({i, w});
		}
	}
	for (int i = 1; i <= m; i++) for (auto &y : id[i]) for (auto &v : id[i]) if (y.f != v.f) g[y.f].pb({v.f, y.s + v.s}), g[v.f].pb({y.f, y.s + v.s});
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		for (int j = 1; j <= n; j++) dist[i][j] = dis[j];
	}
	while (Q--) {
		int s, t;
		ll ans = INF;
		std::cin >> s >> t;
		for (auto &v : id[s]) for (auto &y : id[t]) ans = std::min(ans, v.s + dist[v.f][y.f] + y.s);
		std::cout << ans + w[s] + w[t] << '\n';
	}
}
