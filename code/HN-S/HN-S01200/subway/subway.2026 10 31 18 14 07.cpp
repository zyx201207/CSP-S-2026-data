#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 505, K = 5e5 + 5;
int c, n, m, d, q, x, t, ed, ans = 1e9;
int w[N], k[N];
pii s[N][K];
// s[] means what station this subway across
pii plan[N];
pii sta[M][25];
vector<pii> G[N];
bool vis[N];
void dfs(int u, int used) {
	for (int i = 1; i <= k[u]; i ++) {
		if (s[u][i].fi == ed) {
			ans = min(ans, used);
			return;
		}
	}
	for (pii q : G[u]) {
		int v = q.fi, w = q.se;
		if (vis[v])
			cont
		dfs(v, used + w);
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	while (t --) {
		cin >> c >> n >> m >> d >> q;
		for (int i = 1; i <= m; i ++) {
			cin >> w[i];
		}
		for (int i = 1; i <= n; i ++) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; j ++) {
				cin >> x >> t;
				s[i][j].fi = x;
//				s[i][j].se = t;
				sta[x][++ sta[x][0].fi] = {i, t};
			}
		}
		for (int i = 1; i <= m; i ++) {
			// for every station, connect their subway with time as weight.
			for (int j = 1; j <= sta[i][0].fi; j ++) {
				for (int k = 1; k <= sta[i][0].fi; k ++) {
					if (j != k) {
						G[sta[i][j].fi].push_back(sta[i][k].fi, sta[i][j].se + sta[i][k].se);
					}
				}
			}
		}
		for (int i = 1; i <= q; i ++) {
			cin >> plan[i].fi >> plan[i].se;
			ed = plan[i].se;
			ans = 1e9;
			//
			cout << ans + w[plan[i].fi] + w[plan[i].se] << "\n";
		}
	}
	return 0;
}

