#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<int,int>
const int N = 5e5+5, M = 503;
int C, n, m, kk, w[N], D, qes, x, y;
ll d[M][M];//dis  edge
vector<pll>e[M];//line  to station  time
vector<pll>to[N];//station  to line  time

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(d, 0x1f, sizeof d);
	for (int i = 1; i < M; i++)
		d[i][i] = 0;
	cin >> C >> n >> m >> D >> qes;
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &kk);
		for (int j = 1; j <= kk; j++) {
			scanf("%d%d", &x, &y);
			e[i].push_back({x, y});
			to[x].push_back({i, y});
		}
	}

	//edge of one to another
	for (int i = 1; i <= n; i++) {
		for (pll u : e[i]) {
			//a:station
			int a = u.first, b = u.second;
			for (pll v : to[a]) {
				//c:line
				int c = v.first, f = v.second;
				if (c == i)
					continue;
				d[i][c] = min(d[i][c], (ll) b + f);
				d[c][i] = d[i][c];
			}
		}
	}

	//floyd
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]),
				          d[j][i] = d[i][j];

	while (qes--) {
		scanf("%d%d", &x, &y);
		ll ans = 1e16;
		for (pll u : to[x])
			for (pll v : to[y])
				ans = min(ans, (ll) d[u.first][v.first]
				          + u.second + v.second);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
