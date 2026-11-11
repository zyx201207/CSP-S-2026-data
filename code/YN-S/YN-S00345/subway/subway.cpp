#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5;

struct node {
	ll v, val;
};

vector<node> g[N];
ll c, m, n, d, q, ans = LLONG_MAX;
ll w[N], dis[N];

void dfs(ll u, ll endv) {
	if (u == endv) {
		ans = min(ans, dis[u]);
		return ;
	}
	for (auto it : g[u]) {
		ll v = it.v, val = it.val;
		if (dis[u] + val > dis[v])
			continue;
		dis[v] = dis[u] + val;
		dfs(v, endv);
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}

	for (ll i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		for (ll j = 1; j <= x; j++) {
			ll v, val;
			cin >> v >> val;
			g[m + i].push_back({v, val});
			g[v].push_back({m + i, val});
		}
	}

	for (ll i = 1; i <= q; i++) {
		for (ll j = 1; j <= m + n; j++) {
			dis[j] = LLONG_MAX;
		}
		ans = LLONG_MAX;
		ll x, y;
		cin >> x >> y;
		dis[x] = 0;
		dfs(x, y);
		cout << ans + w[x] + w[y] << "\n";
//		for (ll j = 1; j <= m + n; j++) {
//			cout << dis[j] << " ";
//		}
//		cout << "\n";
	}
	return 0;
}