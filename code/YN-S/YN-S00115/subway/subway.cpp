#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q;
int w[500010];
int t[500010][30];
int k[600];
int a[600][600];

struct node {
	int to, nt, val;
} edge[500010];
int head[500010], tot;

void add(int u, int v, int w) {
	edge[++tot] = {v, head[u], w};
	head[u] = tot;
}

struct node2 {
	int u, ls, sum;
	friend bool operator<(node2 q, node2 w) {
		return q.sum > w.sum;
	}
};
priority_queue<node2>p;
bool vis[500010];

int bfs(int x, int y) {
	int ans = 2e18;
	p.push({x, 0, 0});
	vis[x] = 1;

	while (!p.empty()) {
		node2 u = p.top();
		p.pop();

		for (int i = head[u.u]; i; i = edge[i].nt) {

			int v = edge[i].to;
			int cnt = u.sum + t[u.ls][u.u] + t[edge[i].val][u.u];

			if (v == y) {
				if (edge[i].val == u.ls)
					ans = min(ans, u.sum + t[u.ls][v]);
				else
					ans = min(ans, cnt + t[edge[i].val][v]);
			} else if (!vis[v]) {
				vis[v] = 1;

				if (edge[i].val == u.ls) {

					p.push({v, u.ls, u.sum});
				} else {

					p.push({v, edge[i].val, cnt});
				}
			}
		}
	}

	return ans;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> k[i];

		for (int j = 1; j <= k[i]; j++) {

			cin >> a[i][j] >> t[i][a[i][j]];

			if (j >= 2) {
				add(a[i][j - 1], a[i][j], i);
				add(a[i][j], a[i][j - 1], i);
			}
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + bfs(x, y) << '\n';

		for (int i = 1; i <= 500010; i++) {

			vis[i] = 0;
		}

		while (!p.empty()) {
			p.pop();
		}
	}

	return 0;
}