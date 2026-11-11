#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1001; 
int w[N];
int G[N][N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	memset(G, 0x3f, sizeof G);
	for (int i = 1, k, x, t; i <= n; ++i) {
		cin >> k;
		cin >> x >> t;
		for (int j = 2, a, b; j <= k; ++j) {
			cin >> a >> b;
			G[x][a] = min(G[x][a], b + t);
			G[a][x] = min(G[a][x], b - t);
		}
	}
	for (int i = 1; i <= m; ++i) G[i][i] = 0;
	for (int mid = 1; mid <= m; ++mid) {
		for (int s = 1; s <= m; ++s) {
			for (int e = 1; e <= m; ++e) {
				G[s][e] = min(G[s][e], G[s][mid] + G[mid][e]);
			}
		}
	}
//	for (int i = 1; i <= m; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			cerr << G[i][j] << ' ';
//		}
//		cerr << endl;
//	}
	while(q--) {
		int xx, yy;
		cin >> xx >> yy;
		cout << max(G[xx][yy], G[yy][xx]) + w[xx] + w[yy] << endl;
	}
	return 0;
}
