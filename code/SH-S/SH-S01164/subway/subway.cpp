#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int N = 505;
const int M = 1505; // µãÊý 
int c, n, m, d, q, w[M], k[N], a[N][M], t[N][M], g[M][M], dis[M][M];
void solve() {
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n + m) rep(j, 1, n + m) g[i][j] = INT_MAX / 3;
	rep(i, 1, n) {
		cin >> k[i];
		rep(j, 1, k[i]) {
			cin >> a[i][j] >> t[i][j];
			g[m + i][a[i][j]] = t[i][j];
			g[a[i][j]][m + i] = t[i][j];
		}
	} 
//	for(int i = 1; i <= m + n; ++ i) {
//		for(int j = 1; j <= m + n; ++ j) {
//			cout << g[i][j] << ' ';
//		} cout << '\n';
//	}
	for(int k = 1; k <= m + n; ++ k) 
		for(int i = 1; i <= m + n; ++ i)
			for(int j = 1; j <= m + n; ++ j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
//	for(int i = 1; i <= m + n; ++ i) {
//		for(int j = 1; j <= m + n; ++ j) {
//			cout << g[i][j] << ' ';
//		} cout << '\n';
//	}
	while(q --) {
		int x, y; cin >> x >> y;
		cout << g[x][y] + w[x] + w[y] << '\n'; 
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
} 
