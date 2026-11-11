#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, f[505][505], w[500005];
vector< pair<int, int> > sl[500005];
vector< pair<int, int> > awa[500005];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int x, t;
			cin >> x >> t;
			sl[i].emplace_back(x, t);
			awa[x].emplace_back(i, t);
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 0; j < awa[i].size(); j++)
			for (int k = j + 1; k < awa[i].size(); k++){
				int u = awa[i][j].first, v = awa[i][k].first;
				f[u][v] = f[v][u] = min(f[u][v], awa[i][j].second + awa[i][k].second);
			}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--){
		int x, y;
		cin >> x >> y;
		int res = LLONG_MAX;
		for (int i = 0; i < awa[x].size(); i++)
			for (int j = 0; j < awa[y].size(); j++)
				res = min(res, awa[x][i].second + awa[y][j].second + f[awa[x][i].first][awa[y][j].first]);
		cout << res + w[x] + w[y] << "\n";
	}
	return 0;
}
