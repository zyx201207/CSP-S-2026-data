#include <bits/stdc++.h>
#define nmf(i, s, e) for (int i = s; i <= e; i++)
#define ref(i, s, e) for (int i = s; i >= e; i--)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int testid;
int n, m, d, q;
int w[500005];
vector<pair<int, int>> grh[500005];
LL dis[505][505];
void solve() {
	cin >> n >> m >> d >> q;
	nmf(i, 1, m)cin >> w[i];
	nmf(i, 1, n) {
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			grh[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	nmf(i, 1, n) dis[i][i] = 0;
	nmf(u, 1, m) {
		assert((int)grh[u].size() <= d);
		for (auto i = grh[u].begin(); i != grh[u].end(); i++) {
			for (auto j = i + 1; j != grh[u].end(); j++) {
				dis[i->first][j->first] = min(dis[i->first][j->first], (LL)i->second + j->second);
				dis[j->first][i->first] = min(dis[j->first][i->first], (LL)i->second + j->second);
			}
		}
	}
	nmf(k, 1, n) {
		nmf(i, 1, n) {
			nmf(j, 1, n) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int u, v;
	while (q--) {
		cin >> u >> v;
		LL ans = 0x3f3f3f3f3f3f3f3f;
		for (auto i = grh[u].begin(); i != grh[u].end(); i++) {
			for (auto j = grh[v].begin(); j != grh[v].end(); j++) {
				ans = min(ans, dis[i->first][j->first] + i->second + j->second);
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}
}
signed main() {
#ifndef LOCAL
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> testid;
	int T = 1;
	while (T--)
		solve();
	cerr << "Time Used : " << clock() * (1000.0 / CLOCKS_PER_SEC) << " ms." << endl;
}