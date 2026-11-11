#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define oo (1e18)
#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define smax(a, b) (a = max(a, (b)))
#define smin(a, b) (a = min(a, (b)))
using namespace std;
// using namespace __gnu_pbds;

const int N = 5e2 + 7, M = 5e5 + 7, D = 25;
int c, n, m, d, q;
int w[M], dis[N][N];
int vis[N];
vector<pii> t[M]; 
vector<pii> E[N];

priority_queue<pii> Q;
inline void dij(int s) {
	fill(vis + 1, vis + 1 + n, 0);
	fill(dis[s] + 1, dis[s] + 1 + n, oo);
	dis[s][s] = 0;
	Q.push(mkp(0, s));
	while (!Q.empty()) {
		auto tp = Q.top(); Q.pop();
		int u = tp.se;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto it : E[u]){
			int to = it.fi, val = it.se;
			if (vis[to]) continue;
			if (dis[s][to] > dis[s][u] + val) {
				dis[s][to] = dis[s][u] + val;
				Q.push(mkp(-dis[s][to], to));
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		int K;
		cin >> K;
		rep(j, 1, K) {
			int x, y;
			cin >> x >> y;
			t[x].eb(mkp(i, y));
		}
	}
	rep(i, 1, n) rep(j, 1, n) if (i != j) dis[i][j] = oo; 
	rep(i, 1, m) {
		rep(j, 0, (int)t[i].size() - 1) {
			rep(k, 0, j - 1) {
				int u = t[i][j].fi, v = t[i][k].fi;
				int val = t[i][j].se + t[i][k].se;
				smin(dis[u][v], val);
				smin(dis[v][u], val);
			}
		}
	}
	rep(i, 1, n) rep(j, 1, n) if (i != j && dis[i][j] != oo)
		E[i].eb(mkp(j, dis[i][j]));
	rep(i, 1, n) dij(i);
	rep(tt, 1, q) {
		int x, y;
		cin >> x >> y;
		int ans = oo;
		rep(j, 0, (int)t[x].size() - 1) {
			rep(k, 0, (int)t[y].size() - 1) {
				int u = t[x][j].fi, v = t[y][k].fi;
				int val = t[x][j].se + t[y][k].se;
				smin(ans, val + dis[u][v]);
				// if (val + dis[u][v] + w[x] + w[y] == 32) cout << u << ' ' << v << '\n';
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}

	return 0;
}