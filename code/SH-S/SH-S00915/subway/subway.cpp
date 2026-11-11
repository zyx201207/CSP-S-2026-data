#include <bits/stdc++.h>
using namespace std;
int dis[1000005], vis[1000005];
struct node {
	int w;
	vector <pair <int, int> > g;
} st[1005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> st[i].w;
	for (int i = 1; i <= n; i++) {
		int k, lst = 0;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			a += (i - 1) * n;
			st[a].g.push_back({n * n + j, t});
			st[n * n + j].g.push_back({a, t});
			if (lst) {
				st[a].g.push_back({lst, 0});
				st[lst].g.push_back({a, 0});
			} lst = a;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		memset(dis, 0x3f, sizeof vis);
		memset(vis, 0, sizeof vis);
		priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
		for (int i = 0; i < n; i++) {
			pq.push({0, i * n + x});
			dis[i * n + x] = 0;
		}
		while (!pq.empty()) {
			auto u = pq.top(); pq.pop();
			if (vis[u.second]) continue;
			vis[u.second] = 1;
			for (auto p : st[u.second].g) {
				if (dis[p.first] > dis[u.second] + p.second) {
					dis[p.first] = dis[u.second] + p.second;
					pq.push({dis[p.first], p.first});
				}
			}
		}
		int minn = 1e9;
		for (int i = 0; i < n; i++) minn = min(minn, dis[i * n + y]);
		cout << minn + st[x].w + st[y].w << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
