#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const ll N = 2000009;
ll dp[N], sm[N], cnt[N], a[N], c, t, n, d;
void BF() {
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		dp[i] = 0;
		cnt[0]++;
		for (ll j = i + 1, k = i; j <= n; j++) {
			while (a[j] - a[k] > d) cnt[dp[k]] -= sm[k], k++;
			if (k == j) break;
			dp[j] = dp[k] + 1, sm[j] = min(3LL, cnt[dp[k]]), cnt[dp[j]] += sm[j];
			if (sm[j] == 2) ans++;
		}
		fill(cnt, cnt + n + 1, 0);
	}
	cout << ans << endl;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) cin >> a[i];
		if (c > 10) {
			ll k = d / (a[2] - a[1]);
			if (n == 1) cout << 0 << endl;
			else if (k <= 1) cout << 0 << endl;
			else cout << max(0LL, n - 2 * k + 1) << endl;
		} else BF();
	}
	return 0;
}
/*
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
*/
