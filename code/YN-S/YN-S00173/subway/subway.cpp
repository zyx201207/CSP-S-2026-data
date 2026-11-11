#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn = 505, Maxm = 2e4 + 5;
int c, n, m, d, q, w[Maxm], k[Maxn], a[Maxn][Maxm], t[Maxn][Maxm], dis[Maxn][Maxm], vis[Maxn][Maxm];
vector <int> e[Maxm];

struct node {
	int xl, id, cost;
	bool operator < (const node &cmp) const {
		return cost > cmp.cost;
	}
};

int dijkstra(int s, int f) {
	memset(vis, 0, sizeof vis);
	int res = LLONG_MAX;
	priority_queue <node> pq;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k[i]; j++)
			if (a[i][j] == s)
				pq.push({i, s, t[i][j]});
	while (!pq.empty()) {
		node u = pq.top();
		pq.pop();
		if (u.id == f) {
			res = min(res, u.cost);
			continue;
		}
		if (vis[u.xl][u.id])
			continue;
		vis[u.xl][u.id] = 1;
		for (int i : e[u.id]) {
			for (int j = 1; j <= k[i]; j++) {
				int v = a[i][j], nc = 0;
				if (i == u.xl)
					nc = u.cost + dis[i][v], pq.push({i, v, nc});
				else
					nc = u.cost + dis[i][u.id], pq.push({i, u.id, nc});
			}
		}
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			e[a[i][j]].push_back(i);
			dis[i][a[i][j]] = t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + dijkstra(x, y) + w[y] << '\n';
	}
	return 0;
}