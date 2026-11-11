#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 505, M = 5e5 + 5, D = 21;

int c, n, m, d, q, w[M], s[M][D], x[M][D], cnt[M];
i64 dis[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			for (int j = 1; j <= cnt[a]; ++j) {
				dis[i][s[a][j]] = min(dis[i][s[a][j]], i64{t} + x[a][j]);
			}
			++cnt[a];
			s[a][cnt[a]] = i;
			x[a][cnt[a]] = t;
		}
	}
	for (int i = 1; i <= n; ++i) {
		dis[i][i] = 0;
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = min(dis[i][j], dis[j][i]);
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		i64 ans = LLONG_MAX;
		for (int i = 1; i <= cnt[u]; ++i) {
			for (int j = 1; j <= cnt[v]; ++j) {
				ans = min(ans, dis[s[u][i]][s[v][j]] + x[u][i] + x[v][j]);
			}
		}
		ans += w[u] + w[v];
		cout << ans << '\n';
	}
	return 0;
}