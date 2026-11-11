#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e2 + 6;
const int M = 2e4;
int c, n, m, d, q;
int w[N], k[N];
int a[N][M];
LL t[N][M];
LL v[N][M];
struct Node {
	int l, w;
};
LL ans;
bool vis[M];
vector <Node> E[M];
void dfs(int u, int e, LL step, int z) {
	if (u == e) {
		ans = min(ans, step + v[z][e]);
		return ;
	}
	for (int j = 0; j < E[u].size(); ++j) {
		int l = E[u][j].l, w = E[u][j].w;
		for (int i = w + 1; i <= k[l]; ++i) {
			if (vis[a[l][i]]) continue;
			vis[a[l][i]] = 1;
			if (l != z) {
				dfs(a[l][i], e, step + v[z][u] + v[l][u], l);
			} else {
				dfs(a[l][i], e, step, z);
			}
			vis[a[l][i]] = 0;
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> a[i][j] >> t[i][j];
			v[i][a[i][j]] = t[i][j];
			E[a[i][j]].push_back({i, j});
		}
	}
	while (q--) {
		int x, y;
		ans = 1e18;
		cin >> x >> y;
		memset(vis, 0, sizeof vis);
		dfs(x, y, 0, 0);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
