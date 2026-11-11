#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::vector;

#define int long long
static constexpr int inf = (int)(1e16);

#define fst first
#define scd second
#define pr std::pair<int,int>
#define ep emplace
#define eb emplace_back

int testid;

static constexpr int MAXN = (int)(5e5) + 10;
static constexpr int MAXK = 510;

int n, k, d, q, w[MAXN];
vector<pr> bel[MAXN];
int dis[MAXK][MAXK];

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> testid;

	cin >> k >> n >> d >> q;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1, len; i <= k; i++) {
		cin >> len;
		for (int j = 1, u, x; j <= len; j++) {
			cin >> u >> x;
			bel[u].eb(i, x);
		}
	}
	for (int i = 1; i <= k; i++)
		std::fill(dis[i], dis[i] + k + 1, inf);
	for (int i = 1; i <= k; i++)
		dis[i][i] = 0;
	for (int u = 1; u <= n; u++) {
		for (const pr &a : bel[u]) {
			for (const pr &b : bel[u]) {
				int c = a.fst, d = b.fst;
				dis[c][d] = min(dis[c][d], a.scd + b.scd);
			}
		}
	}
	for (int t = 1; t <= k; t++)
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
	for (int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
//		cout << "u=" << u << ' ' << "v=" << v << '\n';
		int ans = inf;
		for (const pr &a : bel[u]) {
			for (const pr &b : bel[v]) {
				int c = a.fst, d = b.fst;
				ans = min(ans, a.scd + dis[c][d] + b.scd);
//				cout << "ascd=" << a.scd << ' ';
//				cout << "dis=" << dis[c][d] << ' ';
//				cout << "bscd=" << b.scd << '\n';
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}

	return 0;
}