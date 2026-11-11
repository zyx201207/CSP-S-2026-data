#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e5 + 10;
long long c, n, m, d, q, x, y;
long long w[maxn], k[maxn];
vector<pair<long long, long long>>g[maxn];
vector<long long>dis[maxn];

vector<long long> dijkstra(long long s, long long n) {
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	vector<long long>ans(n, 12345670000000), vis(n, 0);
	pq.push({0, s});
	ans[s] = 0;
	while (!pq.empty()) {
		long long w = pq.top().first;
		long long to = pq.top().second;
		pq.pop();
		if (vis[to]) {
			continue;

		}

		vis[to] = 1;
		ans[to] =  w;
		for (long long i2 = 0; i2 < g[to].size(); i2++) {
			pq.push({g[to][i2].first + w, g[to][i2].second});

		}
	}
	return ans;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) {
		cin >> w[i];
	}
	if (0 <= c && c <= 3) {
		int a, t;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] == 1)
				continue;
			for (int i2 = 0; i2 < k[i]; i2++) {
				cin >> a >> t;
				g[m + i + 2].push_back({t, a});
				g[a].push_back({t, m + i + 2});
			}
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + n + 3);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	} else if (4 <= c && c <= 6) {
		int a, t;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] == 1)
				continue;
			for (int i2 = 0; i2 < k[i]; i2++) {
				cin >> a >> t;
				g[m + i + 2].push_back({t, a});
				g[a].push_back({t, m + i + 2});
			}
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + n + 3);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	} else if (7 <= c && c <= 8) {
		long long t1, t2, a1, a2, x, y;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] != 2)
				continue;
			cin >> a1 >> t1 >> a2 >> t2;
			g[a1].push_back({t1 + t2, a2});
			g[a2].push_back({t1 + t2, a1});
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + 1);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	} else if (9 <= c && c <= 11) {
		long long t1, t2, a1, a2, x, y;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] != 2)
				continue;
			cin >> a1 >> t1 >> a2 >> t2;
			g[a1].push_back({t1 + t2, a2});
			g[a2].push_back({t1 + t2, a1});
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + 1);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	} else if (12 <= c && c <= 15) {
		int a, t;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] == 1)
				continue;
			for (int i2 = 0; i2 < k[i]; i2++) {
				cin >> a >> t;
				g[m + i + 2].push_back({t, a});
				g[a].push_back({t, m + i + 2});
			}
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + n + 3);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	} else if (16 <= c && c <= 19) {
		int a, t;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] == 1)
				continue;
			for (int i2 = 0; i2 < k[i]; i2++) {
				cin >> a >> t;
				g[m + i + 2].push_back({t, a});
				g[a].push_back({t, m + i + 2});
			}
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + n + 3);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	} else if (20 <= c && c <= 21) {
		int a, t;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] == 1)
				continue;
			for (int i2 = 0; i2 < k[i]; i2++) {
				cin >> a >> t;
				g[m + i + 2].push_back({t, a});
				g[a].push_back({t, m + i + 2});
			}
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + n + 3);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	} else if (22 <= c && c <= 23) {
		int a, t;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] == 1)
				continue;
			for (int i2 = 0; i2 < k[i]; i2++) {
				cin >> a >> t;
				g[m + i + 2].push_back({t, a});
				g[a].push_back({t, m + i + 2});
			}
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + n + 3);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	} else if (24 <= c && c <= 25) {
		int a, t;
		for (long long i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] == 1)
				continue;
			for (int i2 = 0; i2 < k[i]; i2++) {
				cin >> a >> t;
				g[m + i + 2].push_back({t, a});
				g[a].push_back({t, m + i + 2});
			}
		}
		for (long long i = 1; i <= q; i++) {
			cin >> x >> y;
			if (dis[x].empty())
				dis[x] = dijkstra(x, m + n + 3);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	}
}