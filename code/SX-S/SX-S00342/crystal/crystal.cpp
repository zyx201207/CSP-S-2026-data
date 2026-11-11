#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long s[500005];
long long dp[500010];

bool cmp(long long a, long long b) {
	return a < b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	sort(s + 1, s + n + 1, cmp);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + ((s[i] - s[i - 1]) * (i - 1));
	}
	long long l = 1, r = n;
	while (l <= r ) {
		int mid = (l + r) / 2;
		if (dp[mid] <= m) {
			ans = mid;
			l = mid + 1 ;
		} else
			r = mid - 1 ;
	}
	cout << ans;
	return 0;
}
