#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e5 + 10, N = 510;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, D, q, w[M];
int k[N];
vector<pair<int, int>> v[M];
int d[N][N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	memset(d, 0x3f, sizeof(d));
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int a, t;
			cin >> a >> t;
			for (auto p : v[a]) {
				int o = p.first, ot = p.second;
				d[i][o] = d[o][i] = min(d[i][o], t + ot);
			}
			v[a].emplace_back(i, t);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		int ans = inf;
		for (auto p : v[a]) {
			for (auto q : v[b]) {
				ans = min(ans, d[p.first][q.first] + p.second + q.second);
			}
		}
		cout << ans + w[a] + w[b] << endl;
	}
	return 0;
}
