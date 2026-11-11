#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[501000], dp[301000], lst[301000];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		dp[a[i]] ++;
		lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i ++) if (i == lst[a[i]]) dp[a[i + 1]] += dp[a[i]];
	for (int i = 1; i <= m; i ++) cout << dp[i] << ' ';
	return 0;
}
