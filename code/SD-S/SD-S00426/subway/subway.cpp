#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 5e5 + 500;

ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c - '0'; c = getchar();}
	return x * f;
}

ll c, n, m, d, q;
std::vector<std::pair<int, int> > z[MAXN];
ll a[MAXN];

std::map<std::pair<ll, ll>, ll> ansy;
ll dist[MAXN];
std::priority_queue<std::pair<ll, ll> > heap;
ll ans[505][20005];
ll ansx[3][MAXN];

void add(ll s, ll e, ll d) {
	z[s].emplace_back(e, d);
	z[e].emplace_back(s, d);
}

void dij(ll s) {
	for (int i = 1; i <= n + m; i++)
		dist[i] = LONG_LONG_MAX;
	dist[s] = 0;
//	heap.clear();
	heap.push({0, s});
	while(heap.size()) {
		ll now = heap.top().second;
		heap.pop();
		for (auto to : z[now]) {
			if(dist[to.first] > dist[now] + to.second) {
				dist[to.first] = dist[now] + to.second;
				heap.push({-dist[to.first], to.first});
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		ll k = read();
		for (int j = 1; j <= k; j++) {
			ll x = read(), t = read();
			add(x, i + m, t);
		}
	}
//	for (int i = 1; i <= (n + 1) * m; i++) {
//		std::cout << z[i].size() << ' ';
//		for (auto j : z[i])
//			std::cout << j.first << ' ' << j.second << ' ';
//		std::cout << '\n';
//	}
	if(n <= 2) {
		for (int i = m + 1; i <= m + n; i++) {
			dij(i);
			for (int j = 1; j <= m; j++)
				ansx[i - m][j] = dist[j];
		}
		while(q--) {
			ll x = read(), y = read();
			ll res = LONG_LONG_MAX;
			for (int i = 1; i <= n; i++) {
				if(ansx[i][y] == LONG_LONG_MAX || ansx[i][x] == LONG_LONG_MAX)
					continue;
				res = std::min(res, ansx[i][x] + ansx[i][y]);
			}
			std::cout << res + a[x] + a[y] << '\n';
		}
		return 0;
	}
	if(n > 2e4) {
		for (int i = m + 1; i <= m + n; i++) {
			dij(i);
			for (int j = 1; j <= m; j++)
				ansy[{i - m, j}] = dist[j];
		}
		while(q--) {
			ll x = read(), y = read();
			ll res = LONG_LONG_MAX;
			for (int i = 1; i <= n; i++) {
				if(ansy[{i, y}] == LONG_LONG_MAX || ansy[{i, x}] == LONG_LONG_MAX)
					continue;
				res = std::min(res, ansy[{i, y}] + ansy[{i, x}]);
			}
			std::cout << res + a[x] + a[y] << '\n';
		}
		return 0;
	}
	for (int i = m + 1; i <= m + n; i++) {
		dij(i);
		for (int j = 1; j <= m; j++)
			ans[i - m][j] = dist[j];
	}
	while(q--) {
		ll x = read(), y = read();
		ll res = LONG_LONG_MAX;
		for (int i = 1; i <= n; i++) {
			if(ans[i][y] == LONG_LONG_MAX || ans[i][x] == LONG_LONG_MAX)
				continue;
			res = std::min(res, ans[i][x] + ans[i][y]);
		}
		std::cout << res + a[x] + a[y] << '\n';
	}
	return 0;
}

