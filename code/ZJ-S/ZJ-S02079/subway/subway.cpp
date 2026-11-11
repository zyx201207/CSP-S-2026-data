#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
#define ll long long
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
int c, n, m, d, q;
int w[MAXN];
inline int read() {
	char ch = getchar();
	int x = 0, f = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
vector<vector<pii>> adj;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(); n = read(); m = read(); d = read(); q = read();
	adj.resize(n + m + 1);
	for (int i = 1; i <= m; i ++ ) cin >> w[i];
	for (int i = 1; i <= n; i ++ ) {
		int k;
		cin >> k;
		if (k == 1) {
			int a1, t1;
			cin >> a1 >> t1;
			continue;
		}
		if (k == 2) {
			int a1, t1, a2, t2;
			cin >> a1 >> t1 >> a2 >> t2;
			adj[a1].push_back({a2, t1 + t2});
			adj[a2].push_back({a1, t1 + t2});
			continue;
		}
		for (int j = 1; j <= k; j ++ ) {
			int a, t;
			cin >> a >> t;
			adj[m + i].push_back({a, t});
			adj[a].push_back({m + i, t});
		}
	}
	while (q -- ) {
		int x = read(), y = read();
		vector<ll> dist(n + m + 1, 1e18);
		priority_queue<pli, vector<pli>, greater<pli>> pq;
		dist[x] = 0;
		pq.push({0, x});
		while (!pq.empty()) {
			auto u = pq.top(); pq.pop();
			if (dist[u.se] != u.fi) continue;
			for (auto i: adj[u.se]) {
				if (dist[i.fi] > i.se + u.fi) {
					dist[i.fi] = i.se + u.fi;
					pq.push({dist[i.fi], i.fi});
				}
			}
		}
		cout << dist[y] + w[x] + w[y] << '\n';
	}
	return 0;
}