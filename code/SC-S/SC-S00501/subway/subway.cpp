#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505, M = 500005, D = 22, inf = 1e18;
ll c, n, m, d, q;
ll w[M];
ll dis[N][N], tot[M];
struct node {
	ll v, w;
};
node vec[M][D];
inline void read(ll &x) {
	x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(c), read(n), read(m), read(d), read(q);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i != j) dis[i][j] = inf;
		}
	}
	for (ll i = 1; i <= m; i++) read(w[i]);
	ll k, x, y;
	for (ll i = 1; i <= n; i++) {
		read(k);
		for (ll j = 1; j <= k; j++) {
			read(x), read(y);
			vec[x][++tot[x]] = {i, y};
		}
	}
	for (ll i = 1; i <= m; i++) {
		ll len = tot[i];
		for (ll j = 1; j <= len; j++) {
			for (ll k = 1; k <= len; k++) {
				ll u = vec[i][j].v, v = vec[i][k].v, temp = vec[i][j].w + vec[i][k].w;
				dis[u][v] = min(dis[u][v], temp), dis[v][u] = min(dis[v][u], temp);
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			for (ll k = 1; k <= n; k++) {
				dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]);
			}
		}
	}
	while (q--) {
		read(x), read(y);
		ll len_x = tot[x], len_y = tot[y], res = inf;
		for (ll i = 1; i <= len_x; i++) {
			for (ll j = 1; j <= len_y; j++) {
				ll u = vec[x][i].v, v = vec[y][j].v, temp = vec[x][i].w + vec[y][j].w;
				res = min(res, dis[u][v] + temp);
			}
		}
		printf("%lld\n", res + w[x] + w[y]);
	}
	return 0;
}