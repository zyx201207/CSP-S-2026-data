#include <bits/stdc++.h>

using namespace std;
#define int long long
	
const int inf = (1LL << 60);

const int N = 2000 + 7, M = 1e6 + 7, D = 20 + 7;

struct info {
	int id, t;
	info(int a, int b) : id(a), t(b) {}
};

int c, n, m, d, q, w[M];
vector<info> adj[M];
vector<info> edge[M];

int dis[N][N];

bool vis[M];

void dij(int *ds, int s) {
	fill(vis + 1, vis + m + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	ds[s] = 0;
	while (!q.empty()) { 
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto x : edge[u]) {
			int v = x.id, ww = x.t;
			if (ds[u] + ww < ds[v]) {
				ds[v] = ds[u] + ww;
				q.push({ds[v], v});
			}
		}
	}
	// for (int i = 1; i <= m; i++) printf("%lld ", ds[i]);
	// puts("");
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	// printf("de : %lld %lld\n", w[520], w[5490]);
	bool markB = true;
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%lld", &k);
		int pre = 0;
		for (int j = 1; j <= k; j++) {
			int v, t;
			scanf("%lld%lld", &v, &t);
			adj[v].emplace_back(i, t);
		}
	}
	// for (int i = 1; i <= n; i++) printf("%lld\n", (int)edge[i].size());
	// printf("%lld\n", T);
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		for (auto v : adj[i]) {
			for (auto p : adj[i]) if (v.id != p.id) {
				int vid = v.id, pid = p.id;
				dis[vid][pid] = min(dis[vid][pid], v.t + p.t);
			}
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			edge[i].emplace_back(j, dis[i][j]);
		}
	}
	memset(dis, 0x3f,sizeof(dis));
	for (int i = 1; i <= n; i++) dij(dis[i], i);
	for (; q--; ) {
		int u, v;
		scanf("%lld%lld", &u, &v);
		int ans = inf;
		for (auto j : adj[u]) for (auto p : adj[v]) ans = min(ans, w[u] + w[v] + dis[j.id][p.id] + j.t + p.t);
		printf("%lld\n", ans);
	} 
	return 0;
}

// g++ subway.cpp -o subway -g -O2 -std=c++14 -static
// ./subway
// time ./subway