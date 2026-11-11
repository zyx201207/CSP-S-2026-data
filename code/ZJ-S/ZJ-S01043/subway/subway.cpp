/*

希望能过吧

显然地铁口并不重要
考虑将每一个地铁拆开
每一条线上的站台都建一个点，站厅建一个点
同一号地铁站的不同站台向站厅连边 t[i][j]
同一条线上的相邻站台连边 0

将一条线缩为一个点，直接向站厅连边
每一个点的度数不超过 d
m * d
二分图

直接让每一个站厅相连的线互相连边
m * d^2
n * n
每次询问枚举两个站厅分别到哪个站台
q * d^2
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 2, M = 5e5 + 2;
int n, m, d, q, a[M];
long long E[N][N];
vector<pair<int, int>> px[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int sid; cin >> sid;
	cin >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++) {
		int k; cin >> k;
		for (int j = 1, x, y;j <= k;j++) {
			cin >> x >> y;
			px[x].push_back({i, y});
		}
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) if (i != j)
			E[i][j] = 1e18;
	for (int i = 1;i <= m;i++)
		for (int j = 0;j < (int)px[i].size();j++) {
			int x = px[i][j].first, xt = px[i][j].second;
			for (int k = j + 1;k < (int)px[i].size();k++) {
				int y = px[i][k].first, yt = px[i][k].second;
				E[x][y] = E[y][x] = min<long long>(E[x][y], xt + yt);
			}
		}
	// floyd n = 500 ...
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
	while (q--) {
		int u, v; cin >> u >> v;
		if (u == v) { cout << 0 << "\n"; continue; }
		long long ans = 1e18;
		for (int i = 0;i < (int)px[u].size();i++) {
			int x = px[u][i].first, xt = px[u][i].second;
			for (int j = 0;j < (int)px[v].size();j++) {
				int y = px[v][j].first, yt = px[v][j].second;
				ans = min(ans, E[x][y] + xt + yt);
			}
		}
		ans += a[u] + a[v];
		cout << ans << "\n";
	}

	return 0;
}