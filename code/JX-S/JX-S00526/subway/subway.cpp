#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int min(int x, int y) { return x > y ? y : x; }

void solve() {
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	vector<vector<pair<int, int> > > sub(m + 1);
	vector<int> w(m + 1);
	vector<vector<int> > G(n + 1, vector<int>(n + 1, 0x3f3f3f3f3f3f3f3f));
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int x, y; cin >> x >> y;
			sub[x].push_back({i, y});
		}
	}
	for(int i = 1; i <= m; i++)
		for(auto [x, y] : sub[i])
			for(auto [a, b] : sub[i])
				G[x][a] = G[a][x] = min(G[x][a], b + y);
	for(int i = 1; i <= n; i++) G[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
	for(int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for(auto [a, ta] : sub[x])
			for(auto [b, tb] : sub[y])
				ans = min(ans, ta + tb + G[a][b]);
		cout << ans + w[x] + w[y] << '\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}