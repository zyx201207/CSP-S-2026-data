#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;

const int N = (int)6e5 + 11, M = 511;
int C, n, m, d, q, nm, l[N];
ll a[N], dis[M][M];
vector<pair<int, ll> > edges[N], g[M];
bool b[N];

inline void Dij(int x) {
	for (int i = 0; i <= n; i++)
		dis[x][i] = 1LL << 60, b[i] = 0;
	dis[x][x] = 0;
	for (int i = 1; i < n; i++) {
		int pos = 0;
		for (int j = 1; j <= n; j++)
			if (dis[x][j] < dis[x][pos] && !b[j])
				pos = j;
		b[pos] = 1;
//		printf("x=%d\n", x);
		int len = (int)g[pos].size();
		for (int j = 0; j < len; j++) {
			int y = g[pos][j].fi;
			ll z = g[pos][j].se;
			if (dis[x][pos] + z < dis[x][y])
				dis[x][y] = dis[x][pos] + z;
		}
	}
//	for (int i = 1; i <= n; i++)
//		printf("%lld ", dis[x][i]);
//	printf("\n");
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &n, &m, &d, &q);
	nm = n + m;
	for (int i = 1; i <= m; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		int len;
		scanf("%d", &len);
		while (len--) {
			int x;
			ll w;
			scanf("%d%lld", &x, &w);
			edges[m + i].push_back({x, w});
			edges[x].push_back({m + i, w});
			++l[x], ++l[m + i];
		}
	}
	for (int i = 1 + m; i <= nm; i++)
		for (int j = 0; j < l[i]; j++) {
			int x = edges[i][j].fi;
			ll w = edges[i][j].se;
			for (int k = 0; k < l[x]; k++) {
				int y = edges[x][k].fi;
				if (y != i)
					g[i - m].push_back({y - m, w + edges[x][k].se}), g[y - m].push_back({i - m, w + edges[x][k].se});//, printf("%d %d %lld\n", y - m, i - m, w + edges[x][k].se);
			}
		}
	for (int i = 1; i <= n; i++)
		Dij(i);
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		ll ans = 1LL << 60;
		for (int i = 0; i < l[u]; i++)
			for (int j = 0; j < l[v]; j++)
				ans = min(ans, edges[u][i].se + edges[v][j].se + dis[edges[u][i].fi - m][edges[v][j].fi - m]);
		printf("%lld\n", ans + a[u] + a[v]);
	}
	return 0;
}
