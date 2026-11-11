#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++ i)
#define per(i, r, l) for(int i = (r); i >= (l); -- i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
using namespace std;
const int N = 505, M = 5e5 + 10;
int C, n, m, D, q, W[M], f[N][N];
vector<pii> p[M];
void Jail() {
	cin >> C >> n >> m >> D >> q;
	rep(i, 1, m) {
		cin >> W[i];
	}
	rep(i, 1, n) {
		int k;
		cin >> k;
		rep(j, 1, k) {
			int x, w;
			cin >> x >> w;
			p[x].pb({i, w});
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			f[i][j] = (i == j ? 0 : 1e18);
		}
	}
	rep(x, 1, m) {
		for(int i = 0; i < p[x].size(); ++ i) {
			for(int j = i + 1; j < p[x].size(); ++ j) {
				int u = p[x][i].fi, v = p[x][j].fi, w = p[x][i].se + p[x][j].se;
				if(u != v) {
					f[u][v] = f[v][u] = min(f[u][v], w);
				}
			}
		}
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q --) {
		int x, y, res = 1e18;
		cin >> x >> y;
		for(int i = 0; i < p[x].size(); ++ i) {
			for(int j = 0; j < p[y].size(); ++ j) {
				int u = p[x][i].fi, v = p[y][j].fi, w = p[x][i].se + p[y][j].se;
				res = min(res, f[u][v] + w);
			}
		}
		cout << res + W[x] + W[y] << endl;
	}
}
signed main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	while(T --) Jail();
	return 0;
}
