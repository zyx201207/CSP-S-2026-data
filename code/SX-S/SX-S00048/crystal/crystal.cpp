//AKCSP-S
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[500005];
int dp[1005][1005], _and[1005], _isnum[1005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		ll _ = 0;
		for (int j = i; j <= n; j++) {
			//if(a[j]-a[i]>m)continue;
			dp[i][j] = a[j] - a[i];
			_ += dp[i][j];
		}
		_and[i] = _;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (_and[i] <= m) {
			ans = max(n - i + 1, ans);
		}
	}
	cout << ans + 1;
	return 0;
}
