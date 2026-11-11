#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E6+5;

int c, t, n;
long long d, x[MAXN];

int dp[MAXN], ll, rr;
bool lgl[MAXN];
long long ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		ans = 0;
		if (c <= 10) {
			for (int i = 1, lp, u; i < n; i++) {
				dp[i] = 0, lp = i, lgl[i] = false;
				for (int j = i + 1; j <= n; j++) {
					while (lp < j - 1 && x[j] - x[lp] > d) lp++;
					if (x[j] - x[lp] > d) break;
					dp[j] = dp[lp] + 1;
					u = lower_bound(dp + i, dp + j + 1, dp[j]) - dp;
					if ((u - lp == 2 && !lgl[lp] && !lgl[lp + 1]) 
						|| (u - lp == 1 && lgl[lp])) {
						ans++;
						lgl[j] = true;
					} else lgl[j] = false;
				}
			}
			cout << ans << '\n';
		} else if (c <= 12) {
			dp[1] = 0, lgl[1] = false;
			for (int j = 2, lp = 1, u = 1; j <= n; j++) {
				while (lp < j - 1 && x[j] - x[lp] > d) lp++;
				if (x[j] - x[lp] > d) break;
				dp[j] = dp[lp] + 1;
				while (u <= j && dp[u] <= dp[lp]) u++;
				lgl[j] = (u - lp == 2 && !lgl[lp] && !lgl[lp + 1]) || (u - lp == 1 && lgl[lp]);
			}
			lgl[n + 1] = false;
			ll = 1, rr = 0;
			for (int i = 1; i <= n; i++) {
				if (lgl[i] && !lgl[i - 1]) ll = i;
				if (lgl[i] && !lgl[i + 1]) {rr = i; break;}
			}
			for (int i = 1; i <= n; i++) {
				ans += rr - ll + 1;
				rr = min(n, rr + 1);
				ll = min(n + 1, ll + 1);
			}
			cout << ans << '\n';
		} else if (c <= 14) {
			ll = lower_bound(x + 1, x + n + 1, x[n] - d) - x;
			rr = lower_bound(x + 1, x + n + 1, x[1] + d + 1) - x - 1;
			ans = 0;
			if (rr - ll == 1) cout << 1ll * (ll - 1) * (n - rr) << '\n';
			else if (rr == ll) {
				int nl, nr;
				if (rr < n) {
					nr = rr + 1;
					nl = lower_bound(x + 1, x + n + 1, x[nr] - d) - x;
					if (lower_bound(x + 1, x + n + 1, x[nl] + d + 1) - x - 1 == nr)
						ans += 1ll * (ll - nl) * (n - nr);
				}
				if (ll > 1) {
					nl = ll - 1;
					nr = lower_bound(x + 1, x + n + 1, x[nl] + d + 1) - x - 1;
					if (lower_bound(x + 1, x + n + 1, x[nr] - d) - x == nl)
						ans += 1ll * (nl - 1) * (nr - rr);
				}
				cout << ans << '\n';
			} else cout << 0 << '\n';
		}
		
	}
	
	return 0;
}

