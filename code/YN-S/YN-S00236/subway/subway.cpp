#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int c, n, m, d, q, w[N], dis[505][505], vis[505];
vector<pair<int, int>>g[N], e[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, val;
			cin >> x >> val;
			g[x].push_back({i, val});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			for (int k = j + 1; k < g[i].size(); k++) {
				e[g[i][j].first].push_back({g[i][k].first, g[i][j].second + g[i][k].second});
				e[g[i][k].first].push_back({g[i][j].first, g[i][j].second + g[i][k].second});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[j] = 0;
		}
		priority_queue<pair<int, int>>pq;
		pq.push({0, i});
		while (!pq.empty()) {
			auto tmp = pq.top();
			pq.pop();
			if (vis[tmp.second])
				continue;
			vis[tmp.second] = 1;
			dis[i][tmp.second] = -tmp.first;
			for (auto v : e[tmp.second]) {
				pq.push({tmp.first - v.second, v.first});
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for (int i = 0; i < g[x].size(); i++) {
			for (int j = 0; j < g[y].size(); j++) {
				ans = min(ans, dis[g[x][i].first][g[y][j].first] + w[x] + w[y] + g[x][i].second + g[y][j].second);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
