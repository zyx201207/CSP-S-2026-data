#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 5e5 + 5;
const ll N = 505;
const ll INF = 1e17;
ll c, n, m, d, q;
ll w[M];
ll dis[N][N];
vector<pair<ll, ll>> vec[M];

ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -f;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			dis[i][j] = INF;
		}
	}
	for (ll i = 1; i <= m; i++) {
		w[i] = read();
	}
	for (ll i = 1; i <= n; i++) {
		ll k;
		k = read();
		for (ll j = 1; j <= k; j++) {
			ll x, y;
			x = read();
			y = read();
			vec[x].push_back({i, y});
		}
	}
	for (ll i = 1; i <= m; i++) {
		for (ll pos1 = 0; pos1 < vec[i].size(); pos1++) {
			for (ll pos2 = 0; pos2 < vec[i].size(); pos2++) {
				if (pos1 == pos2) {
					continue;
				}
				ll val = vec[i][pos1].second + vec[i][pos2].second;
				dis[vec[i][pos1].first][vec[i][pos2].first] = min(dis[vec[i][pos1].first][vec[i][pos2].first], val);
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll x = 1; x <= n; x++) {
			for (ll y = 1; y <= n; y++) {
				dis[x][y] = min(dis[x][y], dis[x][i] + dis[i][y]);
			}
		}
	}
	for (ll i = 1; i <= q; i++) {
		ll x, y;
		x = read();
		y = read();
		ll ans = INF;
		for (ll pos1 = 0; pos1 < vec[x].size(); pos1++) {
			for (ll pos2 = 0; pos2 < vec[y].size(); pos2++) {
				ll val = vec[x][pos1].second + dis[vec[x][pos1].first][vec[y][pos2].first] + vec[y][pos2].second;
				ans = min(ans, val);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
