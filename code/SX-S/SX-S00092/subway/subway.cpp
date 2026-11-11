#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500005];

void A() {
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	vector<bool> vis(m + 1, 0);
	vector<vector<long long> > f(m + 1, vector<long long>(m + 1, 999999999999999));
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= 1; j++) {
			if (k == 1) {
				int a, t;
				cin >> a >> t;
				break;
			} else {
				long long a, t1, b, t2;
				cin >> a >> t1 >> b >> t2;
				vis[a] = 1;
				vis[b] = 1;
				f[a][b] = min(f[a][b], t1 + t2);
				f[b][a] = min(f[b][a], t1 + t2);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		f[i][i] = 1;
	}
	for (int k = 1; k <= m; k++) {
		if (vis[k] == 0)
			continue;
		for (int i = 1; i <= m; i++) {
			if (vis[i] == 0)
				continue;
			for (int j = 1; j <= m; j++) {
				if (vis[j] == 0)
					continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << f[x][y] + w[x] + w[y] << "\n";
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	if (c >= 7 && c <= 11) {
		A();
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	vector<vector<long long>> dis(m + 1, vector<long long>(m + 1, 999999999999999));
	vector<vector<pair<int, long long>>> g1(m + 1);
	vector<vector<pair<int, long long>>> g2(m + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			if (k == 1)
				break;
			g1[a].push_back({i, t});
			g2[i].push_back({a, t});
		}
	}
	auto dij = [&](int s)->void{
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> qq;
		qq.push({0, s});
		vector<bool> vis1(m + 1, 0);
		vis1[s] = 1;
		dis[s][s] = 0;
		while (!qq.empty()) {
			long long x = qq.top().first, y = qq.top().second;
			qq.pop();
			if (dis[s][y] > x)
				continue;
			for (auto i : g1[y]) {
				for (auto j : g2[i.first]) {
					if (!vis1[j.first] && j.first != y && dis[s][j.first] > x + j.second + i.second) {
						dis[s][j.first] = x + j.second + i.second;
						vis1[j.first] = 1;
						qq.push({dis[s][j.first], j.first});
					}
				}
			}
		}
	};
	vector<bool> vis(m + 1, 0);
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		if (vis[x] == 1) {
			cout << dis[x][y] + w[y] + w[x] << "\n";
			continue;
		}
		if (vis[y] == 1) {
			cout << dis[y][x] + w[x] + w[y] << "\n";
			continue;
		}
		dij(x);
		vis[x] = 1;
		cout << dis[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}
