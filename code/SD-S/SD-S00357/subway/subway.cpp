// 54

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 510, M = 5e5 + 10;

int n, m, _, d, q, w[M];
ll f[N][N];
vector<pair<int, int>> sub[M];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> _ >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i ) cin >> w[i];
	for (int i = 1; i <= n; ++ i ) {
		int k;
		cin >> k;
		while (k -- ) {
			int a, t;
			cin >> a >> t;
			sub[a].emplace_back(i, t); 
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; ++ i ) f[i][i] = 0;
	for (int i = 1; i <= m; ++ i ) {
		for (int j = 0; j < sub[i].size(); ++ j )
			for (int k = 0; k < j; ++ k ) {
				int x = sub[i][j].first, y = sub[i][k].first;
				f[x][y] = f[y][x] = min(f[x][y], (ll)sub[i][j].second + sub[i][k].second);
			}
	}
	for (int k = 1; k <= n; ++ k )
		for (int i = 1; i <= n; ++ i )
			for (int j = 1; j <= n; ++ j )
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q -- ) {
		int x, y;
		cin >> x >> y;
		ll res = 8e18;
		for (auto e1 : sub[x])
			for (auto e2 : sub[y]) {
				res = min(res, e1.second + e2.second + f[e1.first][e2.first]);
			}
		cout << res + w[x] + w[y] << '\n';
	}
	return 0;
}
