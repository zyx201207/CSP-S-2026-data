#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
int c, n, m, d, q, add[MAXN], dis[MAXN][MAXN];
vector<pair<int, int> > e[500005];

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++)
		cin >> add[i];
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			e[a].push_back(make_pair(i, t));
		}
	}
	for (int i = 1; i <= m; i++)
		for (auto edu : e[i])
			for (auto edv : e[i]) {
				int u = edu.first, v = edv.first, w = edu.second + edv.second;
				if (dis[u][v] > w)
					dis[u][v] = dis[v][u] = w;
			}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int u, v, ans = 2e9;
		cin >> u >> v;
		for (int i = 0; i < e[u].size(); i++)
			for (int j = 0; j < e[v].size(); j++) {
				int x = e[u][i].first, y = e[v][j].first, t = e[u][i].second + e[v][j].second;
				ans = min(ans, add[u] + t + dis[x][y] + add[v]);
			}
		cout << ans << '\n';
	}
	return 0;
}