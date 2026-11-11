#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, n, m, d, q;
ll w[1000005], stm[505][505];
vector<pair<ll, ll> > vt[1000005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++)
		cin >> w[i];
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; j++) {
			ll x, y;
			cin >> x >> y;
			vt[x].push_back(make_pair(i, y));
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i == j)
				continue;
			stm[i][j] = 1e18;
		}
	}
	for (ll i = 1; i <= m; i++) {
		for (ll x = 0; x < vt[i].size(); x++) {
			for (ll y = 0; y < vt[i].size(); y++) {
				ll f = vt[i][x].first, g = vt[i][y].first;
				ll u = vt[i][x].second, v = vt[i][y].second;
				if (f == g)
					continue;
				if (f > g)
					swap(f, g);
				stm[f][g] = min(stm[f][g], u + v);
			}
		}
	}
	for (ll k = 1; k <= n; k++) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				stm[i][j] = min(stm[i][j], stm[i][k] + stm[k][j]);
			}
		}
	}
	for (ll i = 1; i <= q; i++) {
		ll x, y;
		cin >> x >> y;
		ll ans = 1e18;
		for (ll j = 0; j < vt[x].size(); j++) {
			for (ll k = 0; k < vt[y].size(); k++) {
				ll u = vt[x][j].first, v = vt[y][k].first;
				ll uw = vt[x][j].second, vw = vt[y][k].second;
				if (u > v)
					swap(u, v);
				ans = min(ans, stm[u][v] + w[x] + w[y] + uw + vw);
			}
		}
		cout << ans << endl;
	}
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3