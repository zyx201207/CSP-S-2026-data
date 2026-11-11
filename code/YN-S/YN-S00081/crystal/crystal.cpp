#include <bits/stdc++.h>
using namespace std;
long long dp[500015];
long long a[500015];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, ans = 0;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	for (int i = 1; i <= n; i++) {
		if (m >= dp[i]) {
			ans = i;
		} else {
			break;
		}
	}
	cout << ans;
	return 0;
}
