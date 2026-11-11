#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
ll n, m, a[N], dp[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(ll i = 1;i <= n;i ++){
		cin >> a[i];
	}
	dp[1] = a[1];
	for(ll i = 2;i <= n;i ++) {
		for(ll j = min(i, m);j >= 2;j --) {
			dp[j] = max(dp[j], dp[j - 1] & a[i]);
		}
		dp[1] = max(dp[1], a[i]);
	}
	cout << dp[m];
	return 0;
}
