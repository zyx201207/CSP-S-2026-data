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

ll c, n, m, d, q;
ll w[500005], k[505], a[505], t[505];
ll x, y, dis[1505][1505], vis[1505];
vector<e> g[100505];

void calc (ll s) {
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

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
			g[a[j]].push_back({i + m, t[j]});
			g[i + m].push_back({a[j], t[j]});
		}
	}
	for (int i = 1; i <= m; i++) {
		calc(i);
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}