#include <bits/stdc++.h>
using namespace std;
const int N = 5e2+5, M = 5e5+5;
const long long inf = 1e18;
int c, n, m, d, q;
long long a, t;
int x, y;
int K[N];
long long w[M];
long long dist[N][N];

struct node {
	long long to, w;
};
vector<node> line[N], point[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dist, 0x3f, sizeof(dist));
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &K[i]);
		for (int j = 1; j <= K[i]; j++) {
			scanf("%lld%lld", &a, &t);
			line[i].push_back({a, t});
			point[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		for (auto j : line[i]) {
			for (auto k : point[j.to]) {
				dist[i][k.to] = min(dist[i][k.to], k.w + j.w);
				dist[k.to][i] = dist[i][k.to];
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				dist[j][i] = dist[i][j];
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d %d %d\n", i, j, dist[i][j]);
//		}
//	}
	for (int i = 1; i <= q; i++) {
		long long ans = inf;
		scanf("%d%d", &x, &y);
		for (auto u : point[x]) {
			for (auto v : point[y]) {
				ans = min(ans, w[x] + w[y] + u.w + v.w + dist[u.to][v.to]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}