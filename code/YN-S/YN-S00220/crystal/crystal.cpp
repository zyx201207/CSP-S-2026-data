#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[500005], d[500005], dp[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
		dp[i] = 1e18 + 10;
	}
	sort(a + 1, a + 1 + n);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] + d[i] * (i - 1) <= m) {
			dp[i] = min(dp[i], dp[i - 1] + d[i] * (i - 1));
		} else {
			ll k = m / d[i];
			dp[k + 1] = min(dp[k + 1], d[i] * k);
		}
	}
	for (int i = n; i >= 1; i--) {
		if (dp[i] <= m) {
			cout << i;
			return 0;
		}
	}

	return 0;
}