#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 5;
ll n, m, a[N];
ll dp[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	//dp[i][j] = 在前i个数中选j个数按位与的最大值 
	for (ll i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	dp[0] = 9223372036854775807; dp[1] = a[1];
	for (ll i = 1; i <= n; i++) {
		for (ll j = i; j >= 1; j--) {
			if (j <= m) dp[j] = max(dp[j], dp[j - 1] & a[i]);
		}
	}
	cout << dp[m] << "\n";
	return 0;
}

