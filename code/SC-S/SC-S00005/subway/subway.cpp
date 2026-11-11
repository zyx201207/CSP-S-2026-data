#include <bits/stdc++.h>

#define rep(i, s, e) for(int i = s; i <= (e); ++i)
#define _rep(i, s, e) for(int i = s; i >= (e); --i)
#define fep(i, s, e) for(int i = s; i < (e); ++i)
#define _fep(i, s, e) for(int i = s; i > (e); --i)

#define int long long
#define pii pair<int, int>

using namespace std;

constexpr int inf = numeric_limits<int>::max() >> 1;
constexpr int ninf = numeric_limits<int>::min() >> 1;
constexpr int mod = 998244353;
constexpr double eps = 1e-6;

int _, n, m, q, a[500005], dis[505][505];
vector<pii> vec[500005];

inline void solve() {
	cin >> _ >> n >> m >> _ >> q;
	rep(i, 1, m) cin >> a[i];
	rep(i, 1, n) {
		int k, x, y; cin >> k;
		while(k--) {
			cin >> x >> y;
			vec[x].push_back({i, y});
		}
	}
	rep(i, 1, n) rep(j, 1, n) {
		dis[i][j] = i == j ? 0 : inf;
	}
	rep(i, 1, m) {
		int sz = vec[i].size(), u, v;
		fep(x, 0, sz) fep(y, 0, x) {
			u = vec[i][x].first, v = vec[i][y].first;
			dis[u][v] = dis[v][u] = min(dis[u][v], vec[i][x].second + vec[i][y].second);
		}
	}
	rep(k, 1, n) rep(i, 1, n) if(dis[i][k] != inf) {
		rep(j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	while(q--) {
		int x, y, ans = inf; cin >> x >> y;
		for(auto [u, i] : vec[x]) for(auto [v, j] : vec[y]) {
			ans = min(ans, dis[u][v] + i + j);
		}
		cout << ans + a[x] + a[y] << '\n';
	}
	return;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}