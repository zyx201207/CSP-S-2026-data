#include <bits/stdc++.h>
using namespace std;
const int MAXM = 5e5 + 5, MAXMM = 1e3 + 5, MAXD = 25;
int c, n, m, d, q;
long long w[MAXM], a[MAXD][MAXM], b[MAXM][MAXD], dis[MAXMM][MAXMM];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(dis, 0x7f, sizeof(dis));
	memset(a, -1, sizeof(a));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, s; i <= n; i++) {
		cin >> s;
		for (int j = 1, now, t; j <= s; j++) {
			cin >> now >> t;
			b[now][i] = a[i][now] = t;
		}
	}
	for (int k = 1; k <= d; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				if (i != j && a[k][i] != -1 && a[k][j] != -1)
					dis[i][j] = min(dis[i][j], b[i][k] + a[k][j]);
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				if (dis[i][k] < 1e12 && dis[k][j] < 1e12)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		cout << dis[u][v] + w[u] + w[v] << "\n";
	}
	return 0;
}