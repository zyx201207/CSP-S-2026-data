#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
using ll = long long;
const ll inf = 1e15;
using pll = pair<int, int>;
vector <pair<int, int> > g[N];
vector <pair<int, int> > t[M];
int k[N], w[M];
ll f[N][N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i ++)
		cin >> w[i];
	for (int i = 1 ; i <= n ; i ++) {
		cin >> k[i];
		g[i].resize(k[i] + 1);
		for (int j = 1 ; j <= k[i] ; j ++)
			cin >> g[i][j].first >> g[i][j].second,
			t[g[i][j].first].push_back({i, g[i][j].second});
	}
	for (int i = 0 ; i <= n ; i ++)
		for (int j = 0 ; j <= n ; j ++)
			if (i != j) 
				f[i][j] = inf;
	for (int i = 1 ; i <= n ; i ++)
		for (int j = 1 ; j <= k[i] ; j ++) {
			for (pll v : t[g[i][j].first]) {
				ll ds = g[i][j].second + v.second;
				f[i][v.first] = min(f[i][v.first], ds);
				f[v.first][i] = f[i][v.first];
			}
		}
	for (int k = 1 ; k <= n ; k ++)
		for (int i = 1 ; i <= n ; i ++)
			for (int j = 1 ; j <= n ; j ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (int i = 1 ; i <= q ; i ++) {
		int x, y; cin >> x >> y;
		ll res = inf;
		for (pll u : t[x])
			for (pll v : t[y]) {
				res = min(res, w[x] + w[y] + u.second + v.second + f[u.first][v.first]);
			}
		cout << res << '\n';
	}
	return 0;
}