#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct e {
	ll v, d;
};

struct node {
	ll v, d;
	bool operator< (const node a) const {
		return d > a.d;
	}
};

ll ans, c, t, n, d, l, x[2000005], r[2000005];
vector<e> g[5005];
ll dis[305][305], vis[305], v[305][305];

void calc (ll s) {
	memset(v, 0, sizeof(v));
	memset(vis, 0, sizeof(vis));
	memset(dis[s], 0x3f, sizeof(dis[s]));
	priority_queue<node> pq;
	dis[s][s] = 0, pq.push({s, 0});
	while (!pq.empty()) {
		ll u = pq.top().v;
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto _ : g[u]) {
			ll v = _.v, d = _.d;
			if (dis[s][v] > dis[s][u] + d) {
				dis[s][v] = dis[s][u] + d;
				pq.push({v, dis[s][v]});
			}
		}
	}
}

void solve () {
	memset(r, 0, sizeof(r));
	cin >> n >> d;
	x[n + 1] = 1e18, l = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		cin >> x[i];
		while (l <= i && x[l] + d < x[i]) {
			l++;
		}
		r[l] = i;
	}
	while (l <= n + 1 && x[l] + d < x[n + 1]) {
		l++;
	}
	r[l] = n + 1;
	for (ll i = 1; i <= n; i++) {
		r[i] = max(r[i], r[i - 1]);
		for (int j = i; j <= r[i]; j++) {
			for (int k = i + 1; k <= r[i]; k++) {
				if (!v[j][k]) {
					g[j].push_back({k, 1});
					v[j][k] = 1;
				}
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		calc(i);
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = i + 1; j <= n; j++) {
			ll w = dis[i][j], cnt = 0;
			for (ll k = i + 1; k < j; k++) {
				if (dis[i][k] + dis[k][j] == w) {
					cnt++;
				}
			}
			if (cnt == 2) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}