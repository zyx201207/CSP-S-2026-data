#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 10;

ll c, t, n, d;
ll x[N], dp[310][310], mi[310][310];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	if (c>=0 && c<=6) {
		while (t--) {
			for (ll i = 1; i <= 310; i++)
				for (ll j = 1; j <= 310; j++) {
					mi[i][j] = 1e18;
					dp[i][j] = 0;
				}
			ll ans = 0;
			scanf("%lld %lld", &n, &d);
			for (ll i = 1; i <= n; i++) {
				scanf("%lld", &x[i]);
				mi[i][i] = 0;
				dp[i][i] = 1;
			}
			for (ll i = 1; i <= n; i++)
				for (ll j = i+1; j <= n; j++) {
					for (ll k = j-1; k >= i; k--) {
						if (x[j] - x[k] > d)
							break;
						if (mi[i][k] + 1 < mi[i][j]) {
							mi[i][j] = mi[i][k] + 1;
							dp[i][j] = dp[i][k];
						}
						else if (mi[i][k] + 1 == mi[i][j])
							dp[i][j]++;
					}
					if (dp[i][j] == 2)
						ans++;
				}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
