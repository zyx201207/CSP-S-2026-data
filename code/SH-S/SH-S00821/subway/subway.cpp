#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;
using ll = long long;
constexpr int N = 510;
constexpr int M = 5e5 + 10;
constexpr ll INF = 2e18;
int c, n, m, d, T, k, a, t;
struct Query {
	ll y, index;
	Query(ll _2, int _3) : y(_2), index(_3) { }
};
vector<Query> q[M];
ll ans[M]; 
struct Edge {
	ll to, t;
	Edge(ll _1, ll _2) : to(_1), t(_2) { }
};
vector<Edge> G[M + N];
ll w[M];
vector<ll> dijkstra(int);
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> c >> n >> m >> d >> T;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a >> t;
			G[a].emplace_back(i+M, t); // +M for metro, +0 for stations
			G[i+M].emplace_back(a, t);
		}
	}
	int x, y;
	for (int i = 1; i <= T; ++i) {
		cin >> x >> y;
		q[x].emplace_back(y, i);
	}
	for (int i = 1; i <= m; ++i) {
		if (!q[i].size()) continue;
		auto res = dijkstra(i);
		for (auto qq : q[i]) ans[qq.index] = res[qq.y] + w[i] + w[qq.y];
	}
	for (int i = 1; i <= T; ++i) cout << ans[i] << "\n";
	return 0;
} 

// ----------------------------------------------------------
struct node {
	ll id, dis;
	bool operator< (const node& other) const { return dis > other.dis; }
};
priority_queue<node> Q;
vector<ll> dijkstra(int s) {
	vector<ll> dis(N + M, INF);
	Q.push({s, 0}), dis[s] = 0;
	while (!Q.empty()) {
		auto u = Q.top();
		Q.pop();
		if (u.dis > dis[u.id]) continue;
		ll d = u.dis;
		for (auto e: G[u.id]) {
			ll v = e.to, t = e.t;
			if (d + t < dis[v]) dis[v] = d + t, Q.push({v, d+t});
		}
	}
	return dis;
}
