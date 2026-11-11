#include <bits/stdc++.h>
#define ll long long
const int N = 2e6 + 5;
const ll INF = 1e17;
int c, n, m, d, q;
/*
考虑求出每两条线路之间的最少时间
*/
std::vector<std::pair<int, ll>> adj[N];
ll dis[N], w[N];
int vis[N];
ll id(int x, int y) {
	return 1ll * x * (n + m + 1) + y;
}
std::unordered_map<ll, ll> mp; 
int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		std::cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k; std::cin >> k;
		for (int j = 1; j <= k; ++j) {
			int l; ll t;
			std::cin >> l >> t;
			adj[m + i].emplace_back(l, t);
			adj[l].emplace_back(m + i, t);
		}
	}
	if (c >= 12 && c <= 15) {
		while (q--) {
			int x, y; std::cin >> x >> y;
			std::queue<int> q;
			for (int i = 1; i <= m + n; ++i) 
				dis[i] = INF, vis[i] = 0;
			dis[x] = 0, q.emplace(x);
			ll T = 0;
			while (!q.empty()) {
				int x = q.front(); q.pop();
				if (vis[x]) continue;
				vis[x] = 1;
				int y; ll w;
				for (std::pair<int, ll> v : adj[x]) {
					std::tie(y, w) = v;
					T = w;
					if (dis[y] > dis[x] + 1) dis[y] = dis[x] + 1, q.emplace(y);
				}
			}
//			std::cout << T << " ";
			std::cout << T * dis[y] + w[x] + w[y] << "\n";
		}
		return 0;
	}
	while (q--) {
		int x, y; std::cin >> x >> y;
		if (mp.count(id(x, y))) {
			std::cout << mp[id(x, y)] + w[x] + w[y] << "\n";
			continue;
		}
		for (int i = 1; i <= m + n; ++i) 
			dis[i] = INF;
		std::priority_queue<std::pair<ll, int>> pq;
		dis[x] = 0, pq.emplace(-dis[x], x);
		while (!pq.empty()) {
			ll d, w; int x, y;
			std::tie(d, x) = pq.top(); pq.pop();
			if (-d != dis[x]) continue;
			for (std::pair<int, ll> v : adj[x]) {
				std::tie(y, w) = v;
				if (dis[y] > dis[x] + w)
					dis[y] = dis[x] + w, pq.emplace(-dis[y], y);
			}
		}
		std::cout << dis[y] + w[x] + w[y] << "\n";
		for (int i = 1; i <= m + n; ++i)
			mp[id(x, i)] = mp[id(i, x)] = dis[i];
	}
}