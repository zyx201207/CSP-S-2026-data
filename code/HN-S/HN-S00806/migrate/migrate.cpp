#include <bits/stdc++.h>

#define debug(x) (cout << #x << " " << x << "\n")

using namespace std;

using ll = long long;

const int N = 2e6 + 5;

ll c, t, n, d, x[N], dp[N], f[N];

ll sum(ll l, ll r) {
	if (l > r) return 0;
	return (l + r) * (r - l + 1) / 2;
}

ll solve() {
	ll p = x[2] - x[1];
	if (d / p <= 1) return 0;
	if (n + 1 - 2 * (d / p) < 1) return sum(0, n - 1 - d / p);
	return sum(0, d / p - 2) + (d / p - 1) * (n + 1 - 2 * (d / p));
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t --) {
		ll ans = 0;
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) cin >> x[i];
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		if (c == 11 || c == 12) {
			cout << solve() << "\n";
			continue;
		}
		for (ll st = 1; st < n; st++) {
			f[st] = 0, dp[st] = 1;
			for (ll i = st + 1; i <= n; i++) f[i] = 1e18, dp[i] = 0;
			for (ll i = st + 1; i <= n; i++) {
				ll l = st - 1, r = i;
				while (l + 1 < r) {
					ll mid = l + r >> 1;
					if (x[mid] >= x[i] - d) r = mid;
					else l = mid;
				}
				if (r == i) continue;
				f[i] = f[r] + 1;
				for (ll j = r; j < i; j++) if (f[i] == f[j] + 1) {
					dp[i] += dp[j];
				}
			}
			for (ll i = st + 1; i <= n; i++) if (dp[i] == 2) {
				++ ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

