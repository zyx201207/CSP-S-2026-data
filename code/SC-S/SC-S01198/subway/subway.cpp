#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 505;
const int maxm = 5e5 + 5;
const LL INF = 1e18;
int c, n, m, d, q, len, a, x, y;
LL t, w[maxm], dis[maxn][maxn];
vector<pair<int ,LL > > v[maxm];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> len;
		while (len--) {
			cin >> a >> t;
			v[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < v[i].size(); j++)
			for (int k = j + 1; k < v[i].size(); k++) {
				dis[v[i][j].first][v[i][k].first] = 
					min(dis[v[i][j].first][v[i][k].first], v[i][j].second + v[i][k].second);
				dis[v[i][k].first][v[i][j].first] = 
					min(dis[v[i][k].first][v[i][j].first], v[i][k].second + v[i][j].second);
			}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == j || i == k || j == k) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
	while (q--) {
		cin >> x >> y;
		LL ans = INF;
		for (int i = 0; i < v[x].size(); i++)
			for (int j = 0;j < v[y].size(); j++)
				ans = min(ans, dis[v[x][i].first][v[y][j].first] + v[x][i].second + v[y][j].second);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}