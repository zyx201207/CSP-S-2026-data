#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q, w[500005], dis[505][505];  // cnmdq

vector <pair<int, int> > line[500005];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			dis[i][j] = 1e18; 
		}
	}
	for (int i = 1; i <= 500; i++) {
		dis[i][i] = 0;
	} 
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, x, t; j <= k; j++) {
			cin >> x >> t;
			line[x].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto j : line[i]) {
			for (auto k : line[i]) {
				dis[j.first][k.first] = min(dis[j.first][k.first], j.second + k.second);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k) continue;
			for (int j = 1; j <= n; j++) {
				if (j == i || j == k) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			} 
		}
	}
	while (q--) {
		int x, y, ans = 1e18;
		cin >> x >> y;
		for (auto i : line[x]) {
			for (auto j : line[y]) {
				ans = min(ans, dis[i.first][j.first] + i.second + j.second);
			}
		}
//		cout << ans << ' ';
		ans += w[x] + w[y];
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
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
2h
*/
