#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define sz(x) ((int)x.size())
#define pb push_back
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MLE cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
using namespace std;
const int M = 5e5 + 5, inf = 1e16;
bool Mbe;
int C, n, m, d, q, b[M], dis[505][505];
struct V {
	int x, y;
};
vector<V> g[M];
void sol() {
	cin >> n >> m >> d >> q;
	F(i, 1, n) {
		F(j, 1, n) dis[i][j] = inf;
		dis[i][i] = 0;
	}
	F(i, 1, m) {
		cin >> b[i];
		g[i].clear();
	}
	F(i, 1, n) {
		int len, c, t; cin >> len;
		F(j, 1, len) {
			cin >> c >> t;
			g[c].pb((V){i, t});
		}
	}
	F(i, 1, m) {
		int len = sz(g[i]);
		F(j, 0, len - 1) {
			F(k, j + 1, len - 1) {
				int u = g[i][j].x, v = g[i][k].x;
				dis[u][v] = dis[v][u] = min(dis[u][v], g[i][j].y + g[i][k].y);
			}
		}
	}
	F(k, 1, n) {
		F(i, 1, n) if (dis[i][k] < inf) {
			F(j, 1, n) if (dis[k][j] < inf) {
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	F(i, 1, q) {
		int x, y; cin >> x >> y;
		int lx = sz(g[x]), ly = sz(g[y]), ans = inf;
		F(j, 0, lx - 1) {
			F(k, 0, ly - 1) {
				ans = min(ans, dis[g[x][j].x][g[y][k].x] + g[x][j].y + g[y][k].y);
			}
		}
		cout << ans + b[x] + b[y] << '\n';
	}
}
bool Med;
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	FIO
	int T = 1; cin >> C;
	while (T--) sol();
//	MLE
	return 0;
}

