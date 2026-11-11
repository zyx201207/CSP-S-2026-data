#include <bits/stdc++.h>

#define ll long long
#define str string
#define db double

using namespace std;

constexpr ll MAXN = 505;
constexpr ll MAXM = 5e5 + 5;

struct edge {
	int to, val;

	edge(int x, int y) : to(x), val(y) {}
};

struct node {
	ll v, dis;

	node(ll x, ll y) : v(x), dis(y) {}
	bool operator<(const node& x) const {
		return dis > x.dis;
	}
};

ll c, n, m, d, q, w[MAXM], dis[MAXN][MAXN];
vector<edge> grh[MAXM];
vector<edge> line[MAXN];
bitset<MAXN> vis;

void Dijkstra(int src) {
	priority_queue<node> q;

	vis = 0, dis[src][src] = 0;
	q.emplace(src, 0);

	while (q.size()) {
		ll u = q.top().v;
		q.pop();

		if (vis[u]) continue;
		vis[u] = 1;

		for (const auto& v : line[u])
			if (dis[src][v.to] > dis[src][u] + v.val) {
				dis[src][v.to] = dis[src][u] + v.val;
				q.emplace(v.to, dis[src][v.to]);
			}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	memset(dis, 0x3f, sizeof dis);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;

		int nowa = 0, nowt = 0;
		for (int j = 1; j <= k; ++j) {
			cin >> nowa >> nowt;

			for (const auto& v : grh[nowa]) {
				line[i].emplace_back(v.to, v.val + nowt);
				line[v.to].emplace_back(i, v.val + nowt);
			}

			grh[nowa].emplace_back(i, nowt);
		}
	}

	for (int i = 1; i <= n; ++i) Dijkstra(i);

	vector<ll> Havx, Havy;

	while (q--) {
		ll x, y, ans = 1e18;
		cin >> x >> y, Havx.clear(), Havy.clear();

		for (const auto& u : grh[x])
			for (const auto& v : grh[y])
				ans = min(ans, dis[u.to][v.to] + u.val + v.val);

		cout << ans + w[x] + w[y] << '\n';
	}

	return 0;
}

/*
一个有向图，每次查询两个点之间的最短距离
现做法：对于每组点，跑 Dijkstra，时间复杂度 O(q \times m \times log_2{m})，常数很大
我去原来是无向图，草，CCF 你写题面给我写好的啊！！！浪费我两小时！！！
所以不可能重复经过同一个地铁线，那么最多最多 500
计算出地铁线两两之间的最短距离即可
*/