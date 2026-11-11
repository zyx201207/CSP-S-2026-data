#include <bits/stdc++.h>
#define p_q priority_queue
#define int long long
#define endl "\n"
using namespace std;
vector<pair<int, int>> num[500005];
int dis[500005], res[500005], x[1000005];

int dij(int s, int e) {
	p_q <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> z;
	z.push({s, 0});
	while (z.size()) {
		auto i = z.top();
		int u = i.first, ww = i.second;
		z.pop();
		for (auto j : num[u]) {
			int v = j.first, w = j.second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				z.push({v, 0});
			}
		}
	}
	return dis[e];
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> res[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= 2 * k; j++)
			cin >> x[j];
		int u = x[1];
		for (int j = 3; j <= 2 * k; j += 2) {
			num[u].push_back({x[j], x[j - 1]});
			num[x[j]].push_back({u, x[j + 1]});
		}
	}
	while (q--) {
		int s, e;
		cin >> s >> e;
		cout << res[s] + res[e] + dij(s, e) << endl;
	}
	return 0;
}
