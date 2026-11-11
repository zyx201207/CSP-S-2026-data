#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 5;
ll c, n, m, dd, q, w[N], res, dist[505][505], d[505];
const ll INF = 500000000005;
struct node{
	ll to, w;
};
vector<node> ee[N];
bool vis[505];
ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int main() {
  	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), dd = read(), q = read();
	for(ll i = 1; i <= m; i++) {
		w[i] = read();
	}
	for(ll i = 1; i <= n; i++) {
		ll l;
		l = read();
		for(ll j = 1; j <= l; j++) {
			ll a, t;
			a = read(), t = read();
			ee[a].push_back({i, t});
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			if(i == j) continue;
			dist[i][j] = INF;
		}
	}
	for(ll i = 1; i <= m; i++) {
		for(ll j = 0; j < ee[i].size(); j++) {
			for(ll k = j + 1; k < ee[i].size(); k++) {
				ll u = ee[i][j].to, v = ee[i][k].to, um = ee[i][j].w, vm = ee[i][k]. w;
				if(dist[u][v] > (um+vm)) {
					dist[v][u] = dist[u][v] = um + vm;
				}
			} 
		}
	}
	for(ll k = 1; k <= n; k++) {
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			} 
		}
	}
	for(ll i = 1; i <= q; i++) {
	    memset(vis, 0, sizeof vis);
	    res = 0;
		ll x, y;
		x = read(), y = read();
		ll ans = w[x] + w[y];
		ll res = 500000000005;
		for(ll j = 0; j < ee[x].size(); j++) {
			for(ll k = 0; k < ee[y].size(); k++) {
				ll u = ee[x][j].to, v = ee[y][k].to;
				res = min(res, dist[u][v] + ee[x][j].w + ee[y][k].w);
			}
		}
		ans += res;
		printf("%lld\n", ans);
	}
	return 0;
}
