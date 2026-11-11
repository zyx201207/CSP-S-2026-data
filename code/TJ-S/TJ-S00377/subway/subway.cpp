#include <bits/stdc++.h>

int c, n, m, d, q, w[500005], k[505];
std::vector<int> a[505], t[505];
std::vector<int> xa[500005], xt[500005];
long long dis[505][505];

void read(int &x) {
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) {
		read(w[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; ++j) {
			int x, y;
			read(x); read(y);
			a[i].push_back(x);
			t[i].push_back(y);
			xa[x].push_back(i);
			xt[x].push_back(y);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= n; ++i) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < xa[i].size(); ++j) {
			for (int s = j + 1; s < xa[i].size(); ++s) {
				int x = xa[i][j], y = xa[i][s];
				dis[x][y] = std::min(dis[x][y], 1ll * xt[i][j] + xt[i][s]);
				dis[y][x] = std::min(dis[y][x], dis[x][y]);
			}
		}
	}
	for (int s = 1; s <= n; ++s) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = std::min(dis[i][j], dis[i][s] + dis[s][j]);
			}
		}
	} 
	for (int T = 1; T <= q; ++T) {
		int st, ed;
		read(st);
		read(ed);
		long long ans = 1e18;
		for (int i = 0; i < xa[st].size(); ++i) {
			for (int j = 0; j < xa[ed].size(); ++j) {
				int x = xa[st][i], y = xa[ed][j];
				ans = std::min(ans, dis[x][y] + w[st] + w[ed] + xt[st][i] + xt[ed][j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
