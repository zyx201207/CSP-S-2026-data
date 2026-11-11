#include <bits/stdc++.h>

#define debug(x) (cout << #x << " " << x << "\n")

using namespace std;

using ll = long long;

const int N = 505, M = 5e5 + 5;

ll c, n, m, d, q, dp[N][N], w[M];

vector<pair<ll, ll>> dis[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) cin >> w[i];
	for (ll i = 1, k; i <= n; i++) {
		cin >> k;
		while (k --) {
			ll a, t; cin >> a >> t;
			dis[a].emplace_back(make_pair(i, t));
		}
	}
	memset(dp, 0x3f, sizeof dp);
	for (ll i = 1; i <= n; i++) dp[i][i] = 0;
	for (ll i = 1; i <= m; i++) {
		for (ll j = 0; j < dis[i].size(); j++) for (ll k = j + 1; k < dis[i].size(); k++) {
			dp[dis[i][j].first][dis[i][k].first] = dp[dis[i][k].first][dis[i][j].first] = 
			min(dp[dis[i][j].first][dis[i][k].first], dis[i][j].second + dis[i][k].second);
		}
	}
	for (ll k = 1; k <= n; k++)
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
//	for (ll i = 1; i <= n; i++) for (ll j = i + 1; j <= n; j++) {
//		cout << "from " << i << " to " << j << ", distance: " << dp[i][j] << "\n-----------------\n";
//	}
	while (q --) {
		ll x, y, ans = 1e18; cin >> x >> y;
		for (ll i = 0; i < dis[x].size(); i++) for (ll j = 0; j < dis[y].size(); j++) {
			ans = min(ans, dis[x][i].second + dis[y][j].second +
							dp[dis[x][i].first][dis[y][j].first]);
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}

