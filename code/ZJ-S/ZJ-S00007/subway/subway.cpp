#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
using ll = long long;
const int N = 505, M = 5e5 + 10;

ll w[M];
vector<pair<int, int> > vec[M];
ll f[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = 1, k, v, t; i <= n; i++) {
		cin >> k;
		while (k--) cin >> v >> t, vec[v].emplace_back(i, t);
	}
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < vec[i].size(); j++)
			for (int k = j + 1; k < vec[i].size(); k++) {
				int u = vec[i][j].first, v = vec[i][k].first;
				ll d = vec[i][j].second + vec[i][k].second;
				f[u][v] = min(f[u][v], d);
				f[v][u] = min(f[v][u], d);
			}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		int u, v;
		cin >> u >> v;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		// for (auto [v1, t1] : vec[u])
		for (int i = 0; i < vec[u].size(); i++)
			for (int j = 0; j < vec[v].size(); j++)
				ans = min(ans, f[vec[u][i].first][vec[v][j].first] + vec[u][i].second + vec[v][j].second);
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}