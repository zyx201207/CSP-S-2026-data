#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, n, m, d, q, cnt = 1;
ll w[500005], val[500005], head[500005], to[1000005], nxt[1000005], fa[500005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>

void add(ll u, ll v, ll ac) {
	nxt[++cnt] = head[u];
	to[cnt] = v;
	val[cnt] = ac;
	head[u] = cnt;
}

ll find(int u) {
	if (u == fa[u]) {
		return u;
	}
	return fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u != v) {
		fa[u] = v;
	}
}

void dijk(ll u, ll end) {

}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1, k; i <= n; i++) {
		cin >> k;
		ll from = i;
		for (ll j = 1, u, v; j <= k; j++) {
			cin >> u >> v;
			add(from, u, v);
			merge(from, u);
			from = u;
		}
	}
	for (ll i = 1, l, r; i <= q; i++) {
		ll ans = 0;
		cin >> l >> r;
		ans += (w[l] + w[r]);

	}
}