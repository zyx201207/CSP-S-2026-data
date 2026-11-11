#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 510;
const int M = 5e5 + 10;
const i64 INF = 1e18;

struct node {
	int u, v;
};

struct E {
	int to;
	i64 w;
};

struct V {
	int x;
	i64 dis;
	bool operator < (const V &tmp) const {
		return tmp.dis < dis;
	}
};

int c, n, m, d, qq;
int p[N];

bool vis[N];

i64 tim[M];
i64 dis[N][N], w[N][N];

std::vector <i64> a[N];
std::vector <i64> t[N];
std::vector <node> sub[M];

std::vector <E> edge[N];
std::priority_queue <V> q;

void dijkstra (int st) {
	dis[st][st] = 0;
	q.push((V){st, 0});

	for (int i = 1; i <= n; ++i) {
		vis[i] = 0;
	}
	while (!q.empty()) {
		int x = q.top().x;
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;

		for (auto to : edge[x]) {
			if (dis[st][x] + to.w < dis[st][to.to]) {
				dis[st][to.to] = dis[st][x] + to.w;
				q.push((V){to.to, dis[st][to.to]});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> c >> n >> m >> d >> qq;
	for (int i = 1; i <= m; ++i) {
		std::cin >> tim[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			w[i][j] = INF;
			dis[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> p[i];
		for (int j = 1; j <= p[i]; ++j) {
			i64 u, v;
			std::cin >> u >> v;

			sub[u].push_back((node){i, j - 1});
			a[i].push_back(u), t[i].push_back(v);
		}
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < sub[i].size(); ++j) {
			for (int k = j + 1; k < sub[i].size(); ++k) {
				node u = sub[i][j], v = sub[i][k];
				w[u.u][v.u] = std::min(w[u.u][v.u], t[u.u][u.v] + t[v.u][v.v]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (w[i][j] != INF) {
				edge[i].push_back((E){j, w[i][j]});
				edge[j].push_back((E){i, w[i][j]});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
	}

	while (qq--) {
		int u, v;
		std::cin >> u >> v;

		i64 ans = INF;
		for (auto i : sub[u]) {
			for (auto j : sub[v]) {
				ans = std::min(ans, tim[u] + tim[v] + t[i.u][i.v] + t[j.u][j.v] + dis[i.u][j.u]);
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}