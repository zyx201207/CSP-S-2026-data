#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], dp[200005];

long long solve() {
	long long ans = -1;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (i > 1) {
			if (dp[i - 1]&a[i] > a[i] && k < m) {
				dp[i] = dp[i - 1] & a[i];
				k++;
			} else if (k == m) {
				dp[i] = a[i];
				ans = max(ans, dp[i - 1]);
				k = 0;
			} else if (a[i] >= dp[i - 1]&a[i] && n - i + 1 >= m) {
				dp[i] = a[i];
				k = 0;
			} else if (k < m) {
				dp[i] = dp[i - 1] & a[i];
				k++;
			}
		} else {
			dp[i] = a[i];
		}
	}
	ans = max(ans, dp[n]);
	return ans;
}

int main() {
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << solve();

	return 0;
}