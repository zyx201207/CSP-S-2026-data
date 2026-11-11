#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7, M = 2e4 + 7, Q = 1e5 + 7;
int c, n, m, d, q, w[M], k[N], a[M], t[M], cnt, x[Q], y[Q], ans[Q], fa[N + M];
long long p[1500][1500], dis[M + N];
bool vis[M];
vector<pair<int, int>>e[N + M];

struct node {
	int u, v, w;
	friend bool operator<(node x, node y) {
		return x.w < y.w;
	}
} g[N];

void init() {
	for (int i = 1; i <= n + m; i++)
		fa[i] = i;
}

int find(int x) {
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
}

inline void add(int x, int y, int z) {
	e[x].push_back({y, z});
	e[y].push_back({x, z});
}

void dijkstra(int s) {
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= m + n; i++) {
		dis[i] = 0x3f3f3f3f;
	}
	dis[s] = 0ll;
	priority_queue<pair<long long, int>>q;
	q.push({0, s});
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (int i = 0; i < e[u].size(); i++) {
			int v = e[u][i].first, w = e[u][i].second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({-dis[v], v});
			}
		}
	}
}

void dij(int s) {
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= m + n; i++) {
		p[s][i] = 0x3f3f3f3f;
	}
	p[s][s] = 0ll;
	priority_queue<pair<long long, int>>q;
	q.push({0, s});
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (int i = 0; i < e[u].size(); i++) {
			int v = e[u][i].first, w = e[u][i].second;
			if (p[s][v] > p[s][u] + w) {
				p[s][v] = p[s][u] + w;
				q.push({-p[s][v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
			if ((0 <= c && c <= 8) || (12 <= c && c <= 15))
				g[++cnt] = {a[j], m + i, t[j]};
			else
				add(a[j], m + i, t[j]);
		}
	}
	if ((0 <= c && c <= 8) || (12 <= c && c <= 15)) {
		for (int i = 1; i <= q; i++) {
			cin >> x[i] >> y[i];
		}
		init();
		sort(g + 1, g + cnt + 1);
		for (int i = 1; i <= cnt; i++) {
			if (find(g[i].u) != find(g[i].v)) {
				merge(g[i].u, g[i].v);
				add(g[i].u, g[i].v, g[i].w);
			}
		}
		for (int u = 1; u <= m; u++) {
			dijkstra(u);
			for (int i = 1; i <= q; i++) {
				if (x[i] == u) {
					ans[i] = dis[y[i]] + w[x[i]] + w[y[i]];
				}
			}
		}
		for (int i = 1; i <= q; i++) {
			cout << ans[i] << '\n';
		}
	} else {
		for (int u = 1; u <= m; u++) {
			dij(u);
		}
		for (int i = 1; i <= q; i++) {
			cin >> x[i] >> y[i];
			cout << p[x[i]][y[i]] + w[x[i]] + w[y[i]] << '\n';
		}
	}
	return 0;
}