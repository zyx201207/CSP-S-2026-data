#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q;
vector<int> w;
vector<vector<pair<int, int>>> out;
vector<vector<int>> dist;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	w.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}

	dist.resize(n + 1, vector<int>(n + 1, 1e18));
	out.resize(m + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			out[a].push_back({i, t});
		}
	}

	for (int i = 1; i <= m; i++) {
		if (out[i].size() >= 2) {
			for (int j = 0; j < out[i].size(); j++) {
				for (int k = j + 1; k < out[i].size(); k++) {
					dist[out[i][j].first][out[i][k].first] =
					    min(dist[out[i][j].first][out[i][k].first],
					        out[i][j].second + out[i][k].second);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dist[i][j] = min(dist[i][j], dist[j][i]);
			dist[j][i] = min(dist[i][j], dist[j][i]);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k || i == k)
					continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dist[i][j] << " ";
//		}
//		cout << endl;
//	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		int ans = w[u] + w[v];
		// the W array is essentially irrelevant; only two mandatory
		// ends are concerned

		// baoijefioajwefja ewg
		//aef
		int cand = 1e18;
		for (auto num1 : out[u]) {
			for (auto num2 : out[v]) {
				cand = min(cand, num1.second + num2.second +
				           dist[num1.first][num2.first]);
			}
		}
		ans += cand;
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
//
32
17
-----
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
-----
35
16
*/