#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl '\n'
const int N = 505;
const int M = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
void Min(auto &x, auto y) {
	x = x < y ? x : y; 
}

int c, n, m, d, q;
int K, a;
ll w[M], t; 
int x, y;

vector<pii> g[M];
ll dis[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> K;
		for (int j = 1; j <= K; j++) {
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int u = 0; u < g[i].size(); u++) {
			for (int v = u + 1; v < g[i].size(); v++) {
				int tra = g[i][u].se + g[i][v].se;
				int iu = g[i][u].fi;
				int iv = g[i][v].fi;
				Min(dis[iu][iv], tra);
				Min(dis[iv][iu], tra);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				Min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		cin >> x >> y;
		ll res = inf;
		for (int u = 0; u < g[x].size(); u++) {
			for (int v = 0; v < g[y].size(); v++) {
				int xu = g[x][u].fi;
				int yv = g[y][v].fi;
				int ti = g[x][u].se + g[y][v].se;
				Min(res, dis[xu][yv] + ti);
			}
		}
		cout << w[x] + w[y] + res << endl;
	}
	return 0;
}  // wzHzm 1:18
