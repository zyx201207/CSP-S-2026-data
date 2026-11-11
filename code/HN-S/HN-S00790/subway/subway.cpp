#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, n, m, d, q;
int w[500005];
int tt[500005][505];

bitset<505> vis[500005];
struct node {
	int pos, id, t;
};
vector<node> e[500005];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int lst, t;
		cin >> lst >> t;
		e[0].emplace_back(node{lst, i, t});
		tt[lst][i] = t;
		for (int j = 1; j < k; j++) {
			int v;
			cin >> v >> t;
			e[lst].emplace_back(node{v, i, t});
			tt[v][i] = t;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= m; i++) {
			vis[i].reset();
		}
		queue<node> q;
		for (int i = 1; i <= n; i++) {
			q.push({x, i, tt[x][i]});
		}
		int ans = LLONG_MAX;
		while (!q.empty()) {
			int u = q.front().pos, id = q.front().id, w = q.front().t;
			if (u == y) {
				ans = min(ans, w + tt[u][id]);
				continue;
			}
			if (vis[u][id]) {
				continue;
			}
			vis[u][id] = true;
			for (node p : e[u]) {
				int v = p.pos, id1 = p.id, t = p.t;
				if (id == id1) {
					q.push({v, id, w});
				} else {
					q.push({v, id1, w + t});
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}