#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 * 2 + 10;
using ll = long long;
ll n, m, a[N], dp[N];
ll continue_cnt = 0;
bool cmp(ll a, ll b) {
	return a > b;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n, cmp);
	dp[1] = a[1];
	for (ll i = 2; i <= m; i++) {
		dp[i] = max(dp[i-1]&a[i], a[i]);
	}
	cout << dp[m] << '\n';
	return 0;
}
