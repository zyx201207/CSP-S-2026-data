#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const int maxn = 2e5;
ll a[maxn];
ll dp[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		dp[i] = a[i];
	}

	sort(a + 1, a + 1 + n);
	sort(dp + 1, dp + 1 + n);

	for (int i = 2; i <= m; i++) {

		ll lasth = dp[i - 1];

		for (int j = i; j <= n; j++) {

			ll m = (lasth & a[j]);
			lasth = dp[j];

			if (0) {
				dp[j] = max(dp[j - 1], m);
			} else {
				dp[j] = m;
			}
		}
	}

	cout << dp[n];
	return 0;
}

