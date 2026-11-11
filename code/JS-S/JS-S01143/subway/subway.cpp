#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 505, M = 5e5 + 5, inf = 1e18;
ll tc = 1, c, n, m, d, q, w[M];
ll dis[N][N];

struct trsf {
	ll id, t;
};

vector<trsf> g[M];

void init() {
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
}

void floyd() {
	for (ll k = 1; k <= n; k++) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

ll query(ll x, ll y) {
	ll res = inf;
	for (ll o = 0; o < (ll)g[x].size(); o++) {
		for (ll p = 0; p < (ll)g[y].size(); p++) {
			res = min(res, w[x] + g[x][o].t + dis[g[x][o].id][g[y][p].id] + g[y][p].t + w[y]);
		}
	}
	return res;
}

void solve() {
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	init();
	for (ll i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (ll i = 1; i <= n; i++) {
		ll k;
		scanf("%lld", &k);
		while (k--) {
			ll x, tt;
			cin >> x >> tt;
			g[x].push_back({ i, tt });
			for (ll o = 0; o < (ll)g[x].size(); o++) {
				ll j = g[x][o].id;
				dis[i][j] = dis[j][i] = min(dis[i][j], tt + g[x][o].t);
			}
		}
	}
	floyd();
	while(q--) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", query(x, y));
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	while (tc--) { solve(); }
	return 0;
}