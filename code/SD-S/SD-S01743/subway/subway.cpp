#include <bits/stdc++.h>

using namespace std;

const int N = 505, M = 5e5 + 5;

#define int long long
using ll = long long;
using pii = pair<int, int>;

int read() {
	int res = 0, si = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') si = -si; ch = getchar(); }
	while (ch >= '0' && ch <= '9') res = 10 * res + ch - '0', ch = getchar();
	return res * si;
}

int c, n, m, d, q;
ll w[M], dis[N][N];
pii sta[M][25]; int cnt[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) {
		w[i] = read();
	}
	for (int i = 1, k; i <= n; i++) {
		k = read();
		for (int j = 1, a, t; j <= k; j++) {
			a = read(), t = read();
			sta[a][++cnt[a]] = {i, t};
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = 1e18;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= cnt[i]; j++) {
			for (int k = j + 1; k <= cnt[i]; k++) {
				int u = sta[i][j].first, v = sta[i][k].first;
				ll w1 = sta[i][j].second, w2 = sta[i][k].second;
				dis[u][v] = dis[v][u] = min(dis[u][v], w1 + w2);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x = read(), y = read();
		ll ans = 9e18;
		for (int i = 1; i <= cnt[x]; i++) {
			for (int j = 1; j <= cnt[y]; j++) {
				int u = sta[x][i].first, v = sta[y][j].first;
				ll w1 = sta[x][i].second, w2 = sta[y][j].second;
				ans = min(ans, dis[u][v] + w[x] + w[y] + w1 + w2);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
