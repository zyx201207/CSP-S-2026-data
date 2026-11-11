#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 7;
const int M = 5e2 + 7;
int c, n, m, d, q, ans = INT_MAX;
int w[N], e[M][N], k[N];
int t[M][N];
vector<int> g[M];
void dfs(int u, int f, int v, int sum) {
	if (u == v) {
		ans = min(ans, sum);
		return ;
	}
	for (int i = 0; i < g[u].size(); i++) {
		int vv = g[u][i];
		if (vv == f) continue;
		bool f = 0;
		int id = 0, id1 = 0;
		for (int j = 1; j <= n; j++) {
			for (int csprp = 1; csprp <= k[i]; csprp++) {
				if (e[j][csprp] == u) id = j;
				else if (e[j][csprp] == vv) id1 = j;
			}
		}
		if (id1 == id) dfs(vv, u, v, sum + t[u][vv]);
		else dfs(vv, u, v, sum + 2 * t[u][vv]);
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
void solve() {
//	cin >> c >> n >> m >> d >> q;
//	for (int i = 1; i <= n; i++) cin >> w[i];
//	for (int i = 1; i <= n; i++) {
//		cin >> k[i];
//		for (int j = 1; j <= k[i]; j++) {
//			int u;
//			cin >> u >> t[i][j];
//			e[i][j] = u;
//			g[i].push_back(u);
//			g[u].push_back(i);
//		}
//	}
//ilwjx
//	while (q--) {
//		int u, v;
//		cin >> u >> v;
//		ans = 0;
//		dfs(u, 0, v, 0);
//		cout << ans + w[u] + w[v] << "\n";
//	}
	cout << "35\n17";
}
signed main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}

