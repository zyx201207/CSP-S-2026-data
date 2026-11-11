#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++ )
#define per(i, l, r) for(int i = (l); i >= (r); i -- )
#define frein(s) freopen(s, "r", stdin)
#define freout(s) freopen(s, "w", stdout)
#define int long long
#define endl '\n'
using namespace std;

static constexpr int N = 5e5 + 5;
static constexpr int INF = 0x3f3f3f3f3f3f3f3f;
using PII = pair<int, int>;
static int c, n, m, d, q, w[N], k[N], dis[505][505];
vector<pair<int, int> > g[N], at[N];

void floyd() {
	rep(i, 1, n) rep(j, 1, n) rep(k, 1, n)
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

signed main() {
	frein("subway.in"), freout("subway.out");
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		cin >> k[i];
		rep(j, 1, k[i]) {
			int a, t;
			cin >> a >> t;
			at[i].emplace_back(a, t);
		}
		rep(j, 0, (int)at[i].size() - 1) {
			g[at[i][j].first].emplace_back(i + m, at[i][j].second);
			g[i + m].emplace_back(at[i][j].first, at[i][j].second);
		}
	}
	memset(dis, 0x3f, sizeof dis);
	rep(i, 1, n) {
		for(auto p : g[i + m]) {
			int u = p.first;
			for(auto p2 : g[u]) {
				int v = p2.first, w = p2.second;
				if(v != i + m && v > m) {
					dis[i][v - m] = min(dis[i][v - m], p.second + w);
					dis[v - m][i] = min(dis[v - m][i], p.second + w);
				}
			}
		}
	}
	rep(i, 1, n) dis[i][i] = 0;
	floyd();
	rep(i, 1, q) {
		int u, v;
		cin >> u >> v;
		int ans = INF;
		for(auto p : g[u]) for(auto p2 : g[v]) {
			ans = min(ans, p.second + p2.second + dis[p.first - m][p2.first - m]);
		}
		cout << w[u] + w[v] + ans << endl;
	}
	return 0;
}
//code by wsy_I.luogu uid: 1152799
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/