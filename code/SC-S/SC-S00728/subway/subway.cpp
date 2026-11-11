/*
地铁口到站厅要花时间 : w

题终于读懂了 14:50

直接跑最短路就是对的

时间复杂度，所以是边数量是 m, 点是 m，时间复杂度 O(q * m log m)

图你发现是一个二分图状物。

d 就是度数最大值，d <= 2 经典就是链或环，这个是容易的？

A 性质是啥不明确。

B 性质可以退化成 bfs

做到 15：40 就不做了。

你考虑有什么性质：

1. 二分图，所以只有偶环
2. 每个点度 <= 20
3. 其实 k[i] 就是右部点的度数，d 就是左部点个数。

特殊性质 A，你发现，如果会出现偶环，那么这两个点一定是独立出去的。

否则，就是森林，直接做树上距离即可。

但是，只能是树，因为保证联通。


目前得分 44
---------------------------------------------------

特殊性质 B

B 性质 qm 是容易的，+= 16


---------------------------------------------------

d <= 2

只有链和偶环，发现被 A 性质包含了。

所以现在 52 分。


*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

/*
注意，m 是点数，n 是线路数
*/

int c, n, m, d, q;
long long w[MAXN];
vector<pair<int, int>> adj[MAXN * 2];

void addedge(int u, int v, int w) {
	adj[u].emplace_back(v, w);
	adj[v].emplace_back(u, w);
}

void init() { // 拜托，多测要清空
	
}

void dijkstra(int st, vector<long long> &dis) {	
	for (int i = 1; i <= m + n; ++i) {
		dis[i] = 1e16;
	}
	dis[st] = 0;
	priority_queue<pair<long long, int>> pq;
	pq.push({0, st});
	while (pq.size()) {
		auto [du, u] = pq.top(); pq.pop();

		if (-du > dis[u]) continue;
		for (auto [v, w] : adj[u]) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push({-dis[v], v});
			}
		}
	}
}

void bfs(int st, vector<long long> &dis) {	
	for (int i = 1; i <= m + n; ++i) {
		dis[i] = -1;
	}
	dis[st] = 0;
	queue<int> q; q.push(st);
	while (q.size()) {
		auto u = q.front(); q.pop();

		for (auto [v, w] : adj[u]) {
			if (dis[v] != -1) continue;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	
	long long allt = -1;
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t; cin >> a >> t; 
			addedge(a, i + m, t);
			if (allt == -1) {
				allt = t;
			} else if (allt != t) {
				allt = -2;
			}
		}
	}
	vector<vector<long long>> dis(n + 1, vector<long long>(n + m + 1));
	if (allt != -2) {
		for (int i = 1; i <= n; ++i) {
			bfs(i + m, dis[i]);
		}
		for (int i = 1; i <= q; ++i) {
			int u, v; cin >> u >> v;
			long long ans = 1e16;
			for (int j = 1; j <= n; ++j) {
				ans = min(ans, (dis[j][u] + dis[j][v]) * allt);
			}
			cout << ans + w[u] + w[v] << '\n';
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			dijkstra(i + m, dis[i]);
		}
		for (int i = 1; i <= q; ++i) {
			int u, v; cin >> u >> v;
			long long ans = 1e16;
			for (int j = 1; j <= n; ++j) {
				ans = min(ans, dis[j][u] + dis[j][v]);
			}
			cout << ans + w[u] + w[v] << '\n';
		}
	}
	
	

	
	return 0;
}
/*
空间开够 / 开大了吗
需要卡常吗
还剩多少时间
*/