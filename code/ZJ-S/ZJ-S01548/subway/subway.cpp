#include <bits/stdc++.h>
using namespace std;

using i32 = int; using i64 = long long;

#define For(i, l, r) for (i32 i = (l); i <= (r); i++)
#define eb emplace_back

const i32 N = 1 << 19;
const i32 M = 505;
const i64 inf = 1e18;

inline void cmin(i64& x, i64 y) { (y < x) && (x = y); }

i32 c, n, m, d, q;
i32 w[N];
i64 dis[M][M];
vector < pair < i32, i32 > > f[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(), cin.tie(), cout.tie();
	
	cin >> c >> n >> m >> d >> q;
	For (i, 1, m) cin >> w[i];

	For (i, 1, n) {
		i32 k; cin >> k;
		For (j, 1, k) {
			i32 a, t; cin >> a >> t;
			f[a].eb(i, t);
		}
	}

	For (i, 1, n) For (j, 1, n) dis[i][j] = inf;
	For (i, 1, n) dis[i][i] = 0;

	For (i, 1, m) {
		for (auto [u, w1] : f[i]) for (auto [v, w2] : f[i])
			cmin(dis[u][v], w1 + w2);
	}

	For (z, 1, n) For (x, 1, n) For (y, 1, n) cmin(dis[x][y], dis[x][z] + dis[z][y]);

	For (i, 1, q) {
		i32 x, y; cin >> x >> y;
		i64 ans = inf;
		for (auto [u, w1] : f[x]) for (auto [v, w2] : f[y])
			cmin(ans, dis[u][v] + w1 + w2);
		cout << ans + w[x] + w[y] << '\n';
	}

	return 0;
}