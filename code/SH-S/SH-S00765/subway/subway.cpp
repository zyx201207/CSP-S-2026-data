#include <bits/stdc++.h>
using namespace std;
#define int long long
int C, n, m, d, q, w[500005], ans[505][505];
vector<pair<int, int> >g[500005];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		while (k--){
			int x, y;
			cin >> x >> y;
			g[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			ans[i][j] = 1e18;
		}
		ans[i][i] = 0;
	}
	for (int i = 1; i <= m; i++){
		for (int j = 0; j < g[i].size(); j++){
			for (int u = j + 1; u < g[i].size(); u++){
				int x = g[i][j].first, y = g[i][u].first;
				ans[x][y] = min(ans[x][y], g[i][j].second + g[i][u].second);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			ans[i][j] = min(ans[i][j], ans[j][i]);
		}
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
			}
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		int res = 1e18;
		for (int i = 0; i < g[x].size(); i++){
			for (int j = 0; j < g[y].size(); j++){
				int u = g[x][i].first, v = g[y][j].first;
				res = min(res, w[x] + w[y] + ans[u][v] + g[x][i].second + g[y][j].second);
			}
		}
		cout << res << '\n';
	}
	return 0;
}
