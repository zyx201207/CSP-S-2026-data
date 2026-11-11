#include <bits/stdc++.h>
using namespace std;

const int N = 125755;
long long c, n, m, D, Q, tot, w[N], d[N], vis[N];
vector<pair<int, int>> g[N];
struct qnode {
	long long u, dis;

	bool operator < (const qnode & r) const {
		return dis > r.dis;
	}
};

int main () {

	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);

	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> c >> n >> m >> D >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	tot = m;
	for (int i = 1; i <= n; i++) {
		int x, h;
		tot++;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back ({tot, b});
			g[tot].push_back ({a, b});
			if (j >= 2) {
				g[a].push_back ({h, 0});
				g[h].push_back ({a, 0});
			}
			h = a;
		}
	}

	while (Q--) {
		int x, y;
		cin >> x >> y;

		for (int i = 0; i <= n+m; i++) {
			d[i] = 1e18;
		}

		priority_queue<qnode> q;
		d[x] = 0;
		q.push ({x, 0});

		while (q.size()) {
			qnode z = q.top();
			q.pop();
			int u = z.u, dis = z.dis;

			if (vis[u]) {
				continue;
			}
			vis[u] = 1;

			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].first;
				int w = g[u][i].second;

				if (d[u]+w < d[v]) {
					d[v] = d[u] + w;
					q.push ({v, d[v]});
				}
			}
		}

		cout << w[x] + w[y] + d[y] << "\n";
	}

	return 0;
}
