#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll c, n, m, d, q;
const ll N = 510, M = 5e5+10;
ll dp[N][M];
ll w[M];
ll a[N][M];
ll t[N][M];
ll x, y;
ll k[N];
ll l;
ll ans[M];
ll mid;
queue<pair<ll, ll>> qp;

ll val[N][M];

void bfs() {
	pair<ll, ll> j;
	qp.push({1, 1});
	while (!qp.empty()) {
		j = qp.front();
		qp.pop();
		qp.push({j.first, j.second + 1});
		val[j.second][j.second + 1] = min(val[j.second][j.second + 1], val[j.second][j.second]);
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= n; k++) {
				if (a[i][k] == j.second) {
					qp.push({i, j.second});
					val[i][j.second] = min(val[i][j.second], t[i][k]);
				}
			}
		}

	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	bfs();
	for (int i = 1; i <= m; i++) {
		mid = LONG_LONG_MAX;
		for (int j = 1; j <= n; j++) {
			mid = min(mid, val[i][j]);

		}
		ans[i] = mid;
	}
	while (q--) {
		cin >> x >> y;
		cout << ans[y] - ans[x];
	}
	return 0;
}
