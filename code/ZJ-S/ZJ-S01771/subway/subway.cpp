// LUOGU NAME: NEKOB0Y

// 首先是多个询问，然后点数很多。
// 中间点却很少，每一个点和中间点的连线也很少。
// 一个出行方案一定是 u -> 一个中间点 -> 另一个中间点 -> v。
// 常数似乎有点大，但似乎能过吗？
// 应避免对代码常数的考察。 ——CCF

// 拿 subway3.out 和 subway7.ans 对比是什么玩意啊！
// 能相信 CCF 少爷机吗？$O((m+q)d^2)$

#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

constexpr int N = 1e3 + 10, M = 5e5 + 10;
constexpr int INF = 1e18;
vector<pii> g[M];
int C, n, m, d, q, a[M], dis[N][N];

// 难道这不算 signed main() 吗？
auto main() -> signed {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> a[i];

	for (int i = 1, x; i <= n; i ++) {
		cin >> x;

		for (int j = 1, v, d; j <= x; j ++) {
			cin >> v >> d;
			g[v].emplace_back(i, d);
		}
	}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) dis[i][j] = INF;
	for (int i = 1; i <= n; i ++) dis[i][i] = 0;

	for (int i = 1; i <= m; i ++)
		for (auto I : g[i]) for (auto J : g[i])
			dis[I.first][J.first] = min(dis[I.first][J.first],
				I.second + J.second);

	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);

	for (int u, v; q; q --) {
		cin >> u >> v;
		if (u == v) {
			cout << 0 << '\n';
			continue;
		}

		int ans = INF;
		for (auto i : g[u]) for (auto j : g[v])
			ans = min(ans, i.second + j.second + dis[i.first][j.first]);
		cout << ans + a[u] + a[v] << '\n';
	}

	return 0;
}