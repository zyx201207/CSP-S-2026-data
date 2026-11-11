#include <bits/stdc++.h>
#define int long long
#define pil pair <int, int>
using namespace std;
const int N = 510, M = 1e3 + 10;
int w[N];
//vector <pil> g[N];
int fl[N + M][N + M];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];	
	}
	for (int i = 1; i <= n + m; i ++) {
		for (int j = 1; j <= n + m; j ++) {
			fl[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= n; i ++) {
		int t;
		cin >> t;
		for (int j = 1; j <= t; j ++) {
			int v, w;
			cin >> v >> w;
//			g[m + i].push_back({w, v});
//			g[v].push_back({w, (m + i)});
			fl[m + i][v] = w;
			fl[v][m + i] = w;
		}
	}
	for (int i = 1; i <= n + m; i ++) {
		fl[i][i] = 0;	
	}
	for (int k = 1; k <= n + m; k ++) {
		for (int i = 1; i <= n + m; i ++) {
			for (int j = 1; j <= n + m; j ++) {
				fl[i][j] = min(fl[i][j], fl[i][k] + fl[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i ++) {
		int st, e;
		cin >> st >> e;
		cout << fl[st][e]  + w[st] + w[e] << '\n';
	}
	return 0;
}