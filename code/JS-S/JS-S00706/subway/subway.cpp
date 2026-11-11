#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int, ll> > sub[500005];
ll w[500005];
ll dis[505][505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int a;
			ll t;
			scanf("%d %lld", &a, &t);
			sub[a].emplace_back(i, t);
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (auto A : sub[i]) {
			for (auto B : sub[i]) {
				int x = A.first, y = B.first;
				ll X = A.second, Y = B.second;
				dis[x][y] = min(dis[x][y], X + Y);
				dis[y][x] = min(dis[y][x], X + Y);
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
		int u, v;
		scanf("%d %d", &u, &v);
		ll ans = 0x3f3f3f3f3f3f3f3fll;
		for (auto A : sub[u]) {
			for (auto B : sub[v]) {
				ans = min(ans, w[u] + w[v] + A.second + B.second + dis[A.first][B.first]);
			}
		}
		printf("%lld\n", ans);
	}
}