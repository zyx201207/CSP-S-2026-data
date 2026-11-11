#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500510
#define M 510
struct edge {
	int v, w;
};
vector<edge> g[N];
int w[N], dis[M][M];
int c, n, m, d, q, xr, yr, k, a, t;
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j) dis[i][j] = 1e15;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = m + 1; i <= m + n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a >> t;
			g[i].push_back((edge){a, t});
			g[a].push_back((edge){i, t});
		}
	}
	for(int i = 1; i <= m; i++) {
		int sz = g[i].size();
		for(int l = 0; l < sz; l++)
			for(int r = l + 1; r < sz; r++) {
				edge x = g[i][l], y = g[i][r];
				int xv = x.v, yv = y.v;
				if(xv > yv) swap(xv, yv);
				dis[xv - m][yv - m] = min(dis[xv - m][yv - m], x.w + y.w);
			}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i < k; i++)
			for(int j = k + 1; j <= n; j++)
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
	while(q--) {
		cin >> xr >> yr;
		int ans = 1e15;
		for(auto x : g[xr])
			for(auto y : g[yr]) {
				int xv = x.v, yv = y.v;
				if(xv > yv) swap(xv, yv);
				ans = min(ans, dis[xv - m][yv - m] + x.w + y.w);
			}
		cout << ans + w[xr] + w[yr] << '\n';
	}
	return 0;
}

