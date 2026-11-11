#include<bits/stdc++.h>
#define int long long
using namespace std;
#define N 505
#define M 500005
vector<pair<int, int>>ve[M];
int T, n, m, d, q, ans, a[M], c[N], w[N][N], inf = 2e18;
signed main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> T >> n >> m >> d >> q;//快读太废物了
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		for (int j = 1, v, t; j <= c[i]; j++) cin >> v >> t, ve[v].emplace_back (i, t);
		for (int j = 1; j <= n; j++) if (i != j) w[i][j] = inf;
	}
	for (int i = 1; i <= m; i++) for (auto st : ve[i]) for (auto ed : ve[i]) {
				int u = st.first, v = ed.first;
				if (u != v) w[u][v] = st.second + ed.second;
			}
	for (int k = 1; k <= n; k++) for (int u = 1; u <= n; u++) for (int v = 1; v <= n; v++) if (w[u][k] + w[k][v] < w[u][v]) w[u][v] = w[v][u] = w[u][k] + w[k][v];
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y, ans = inf;
		for (auto st : ve[x]) for (auto ed : ve[y]) ans = min (ans, w[st.first][ed.first] + st.second + ed.second);
		cout << ans + a[x] + a[y] << '\n';
	}
	return 0;
}