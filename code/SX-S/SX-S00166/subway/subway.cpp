#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 510, M = 2e5;
ll c, n, m, d, q;
ll dp[N][N], pre[N], cnt, w[N], aa[M], t[M];

struct node {
	ll to, len, nex;
} a[M];

void add(ll x, ll y) {
	ll u = aa[x], v = aa[y];
	a[++cnt].to = v;
	a[cnt].len = t[x] + t[y];
	a[cnt].nex = pre[u];
	pre[u] = cnt;
	dp[u][v] = min(dp[u][v], t[x] + t[y]);
	dp[v][u] = min(dp[v][u], t[x] + t[y]);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		for (ll j = 1; j <= m; j++)
			dp[i][j] = 1e18;
		dp[i][i] = 0;
	}
	for (ll i = 1; i <= m; i++)
		cin >> w[i];
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; j++) {
			cin >> aa[j] >> t[j];
		}
		for (ll j = 1; j <= k; j++) {
			for (ll p = j + 1; p <= k; p++) {
				add(j, p);
			}
		}
	}

	for (ll i = 1; i <= m; i++) {
		for (ll k = 1; k <= m; k++) {
			for (ll j = 1; j <= m; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[k][i]);
			}
		}
	}
	while (q--) {
		ll x, y;
		cin >> x >> y;
		cout << dp[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
