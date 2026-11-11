// gaoxuke xajdfz SN-S00361
#include <bits/stdc++.h>
using namespace std;

namespace gxk {
	void main() ;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	gxk::main();
	return 0;
}

// ---

#define int long long
#define rep(x, l, r) for (int x = (l); x <= (r); x++)
#define per(x, r, l) for (int x = (r); x >= (l); x--) 

namespace Maky {
	template <typename T> inline void chkmin(T &x, T y) {
		x = (x < y ? x : y);
		return ;
	}
	template <typename T> inline void chkmax(T &x, T y) {
		x = (x > y ? x : y);
		return ;
	}
} using namespace Maky;

namespace gxk {
	constexpr int maxn = 510, maxm = 500010;
	
	int c, n, m, d, q, w[maxm], f[maxn][maxn];
	vector <pair <int, int> > G[maxm];
	
	/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
	*/
	
	void main() {
		cin >> c >> n >> m >> d >> q;
		rep (i, 1, m) cin >> w[i];
		rep (i, 1, n) {
			int k;
			cin >> k;
			int u, t;
			rep (j, 1, k) {
				cin >> u >> t;
				G[u].push_back({i, t});
			}
		}
		
		rep (i, 1, n) rep (j, 1, n) f[i][j] = (i == j ? 0 : (int)(1e18));
		rep (i, 1, m) {
//			cout << i << '\n';
			for (auto x : G[i]) {
				for (auto y : G[i]) {
					int v = x.second + y.second;
					chkmin(f[x.first][y.first], v);
//					cout << x.first << ' ' << y.first << ' ' << v << '\n';
				}
			}
		}
		rep (k, 1, n) rep (i, 1, n) rep (j, 1, n) chkmin(f[i][j], f[i][k] + f[k][j]);
//		rep (i, 1, n) {
//			rep (j, 1, n) cout << f[i][j] << ' ';
//			cout << '\n';
//		}
		
		while (q--) {
			int x, y;
			cin >> x >> y;
			int res = (int)(1e18);
			for (auto a : G[x]) {
				for (auto b : G[y]) {
//					cout << a.first << ' ' << b.first << ' ' << f[a.first][b.first] + a.second + b.second << '\n';
					chkmin(res, f[a.first][b.first] + a.second + b.second);
				}
			}
			cout << res + w[x] + w[y] << '\n';
		}
		
		return ;
	}
}
