#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	int u;
	ll d;
	const bool operator > (const node& o) const{
		return d > o.d;
	}
};
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
	cin.tie(nullptr)->sync_with_stdio(false);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<vector<pair<int, ll>>> adj(2 * m + n + 1);
	vector<vector<pair<int, ll>>> g(2 * m + n + 1);
	for (int i = 1; i <= m; i++) {
		ll w;
		cin >> w;
		adj[i].push_back({m + i, w});
		adj[m + i].push_back({i, w});
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int a;
			ll t;
			cin >> a >> t;
			adj[2 * m + i].push_back({m + a, t});
			adj[m + a].push_back({2 * m + i, t});
		}
	}
	vector<ll> dis(2 * m + n + 1, inf);
	dis[1] = 1;
	vector<bool> vis(2 * m + n + 1, 0);
	vector<int> fa(2 * m + n + 1, 0);
	priority_queue<node, vector<node>, greater<node>> pq;
	pq.push({1, 0});
	while (!pq.empty()){
		int u = pq.top().u;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].first;
			ll w = adj[u][i].second;
			if (dis[v] > dis[u] + w){
				fa[v] = u;
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
			}
		}
	}
	for (int i = 1; i <= 2 * m + n; i++)
		if (fa[i])
			g[fa[i]].push_back({i, dis[i] - dis[fa[i]]});
	vector<int> siz(2 * m + n + 1, 0), son(2 * m + n + 1, 0), top(2 * m + n + 1), dep(2 * m + n + 1, 0);
	vector<ll> dt(2 * m + n + 1, 0);
	function<void(int)> dfs1 = [&](int u){
		siz[u] = 1;
		dep[u] = dep[fa[u]] + 1;
		for (int i = 0; i < g[u].size(); i++){
			int v = g[u][i].first;
			dt[v] = dt[u] + g[u][i].second;
			dfs1(v);
			siz[u] += siz[v];
			if (siz[son[u]] < siz[v]) son[u] = v;
		}
	};
	function<void(int, int)> dfs2 = [&](int u, int tp){
		top[u] = tp;
		if (son[u]) dfs2(son[u], tp);
		for (int i = 0; i < g[u].size(); i++){
			int v = g[u][i].first;
			if (v != son[u]) dfs2(v, v);
		}
	};
	auto lca = [&](int u, int v){
		while (top[u] != top[v]){
			if (dep[top[u]] < dep[top[v]])
				swap(u, v);
			u = fa[top[u]];
		}
		return dep[u] < dep[v] ? u : v;
	};
	dfs1(1);
	dfs2(1, 1);
	while (q--){
		int u, v;
		cin >> u >> v;
		cout << dt[u] + dt[v] - 2 * dt[lca(u, v)] << '\n';
	}
	return 0;
}