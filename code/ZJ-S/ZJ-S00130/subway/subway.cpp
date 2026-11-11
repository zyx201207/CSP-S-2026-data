#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 510, K = 500010, M = 500010, Q = 100010;
const ll inf = 1ll << 60;
int c, n, m, d, q, k[K];
ll w[M];
vector<ll> a[N], t[N], g[M];
ll dist[N][N];
int vis[N][M];

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dist[i][j] = inf;
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			ll A, T; scanf("%lld%lld", &A, &T);
			a[i].push_back(A);
			t[i].push_back(T);
			vis[i][A] = T;
			g[A].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int kk = 0; kk < k[i]; kk++) {
			for (int j = i + 1; j <= n; j++) if(vis[j][a[i][kk]]) {
				dist[i][j] = dist[j][i] = min(dist[i][j], vis[j][a[i][kk]] + t[i][kk]);
			}
		}
	}
	for (int kk = 1; kk <= n; kk++) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if(dist[i][kk] < inf && dist[kk][j] < inf && i != kk && kk != j)
					dist[j][i] = dist[i][j] = min(dist[i][kk] + dist[kk][j], dist[i][j]);
			}
		}
	}
	for (; q--; ) {
		int x, y; scanf("%d%d", &x, &y);
		ll ans = inf;
		for (int i = 0; i < (int)g[x].size(); i++) {
			for (int j = 0; j < (int)g[y].size(); j++) {
				int u = g[x][i], v = g[y][j];
				ans = min(ans, vis[u][x] + dist[u][v] + vis[v][y] + w[x] + w[y]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
