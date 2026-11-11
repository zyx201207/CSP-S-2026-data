#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll maxn = 2e6 + 5;
const ll INF = 1e18;

ll n, m, d, q;
ll dis[505][505];
ll w[maxn];
vector<ll> a[505], t[505];
vector<ll> node[500005];
vector<ll> ret[500005];
struct nd {
	ll v, w;
};
vector<nd> e[505];
ll vis[505], ds[505];
ll mn[505][505];

void solve() {
	cin >> n >> m >> d >> q;

	for (ll u = 1; u <= n; u++) {

		for (ll v = 1; v <= n; v++) {

			dis[u][v] = INF;
			mn[u][v] = INF;
		}
	}

	for (ll i = 1; i <= m; i++)

		cin >> w[i];

	for (ll i = 1; i <= n; i++) {

		ll k;
		cin >> k;
		a[i].resize(k + 1);
		t[i].resize(k + 1);

		for (ll j = 1; j <= k; j++) {

			cin >> a[i][j] ;
			cin >> t[i][j];
			node[a[i][j]].push_back(i);
			ret[a[i][j]].push_back(t[i][j]);
		}
	}

	for (ll j = 1; j <= m; j++) {

		for (ll u = 0; u < node[j].size(); u++) {

			for (ll v = 0; v < node[j].size(); v++) {

				if (u == v) {
					continue;
				}

//				cout << ret[j][u] + ret[j][v] << "\n";
				dis[node[j][u]][node[j][v]] = min(dis[node[j][u]][node[j][v]], ret[j][u] + ret[j][v]);
				dis[node[j][v]][node[j][u]] = min(dis[node[j][v]][node[j][u]], ret[j][u] + ret[j][v]);
			}
		}
	}

	for (ll u = 1; u <= n; u++) {

		for (ll v = 1; v <= n; v++) {

			if (u == v) {
				continue;
			}

//			cout << u << " " << v << " " << dis[u][v] << "\n";

			if (dis[u][v] == INF)
				continue;
			e[u].push_back({v, dis[u][v]});
		}
	}

	for (ll st = 1; st <= n; st++) {

		priority_queue<pll, vector<pll>, greater<pll> > q;

		for (ll i = 1; i <= n; i++)

			vis[i] = 0, ds[i] = INF;
		q.push({0, st});
		ds[st] = 0;

		while (!q.empty()) {
			ll now = q.top().second;
			q.pop();

			if (vis[now])
				continue;
			vis[now] = 1;

			for (nd ND : e[now]) {
				if (ND.w + ds[now] < ds[ND.v]) {
					ds[ND.v] = ND.w + ds[now];
					q.push({ds[ND.v], ND.v});
				}
			}
		}

		for (ll i = 1; i <= n; i++)

			mn[st][i] = min(mn[st][i], ds[i]);
	}

	while (q--) {
		ll x, y;
		cin >> x >> y;
		ll ans = INF;

		for (ll u = 0; u < node[x].size(); u++) {

			for (ll v = 0; v < node[y].size(); v++) {

				ans = min(ans, ret[x][u] + ret[y][v] + mn[node[x][u]][node[y][v]]);
			}
		}

		ans += w[x] + w[y];
		cout << ans << "\n";
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T = 1;
	ll c;
	cin >> c;

//	cin>>T;
	while (T--)
		solve();
}