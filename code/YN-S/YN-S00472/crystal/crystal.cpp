#include <bits/stdc++.h>
using namespace std;
long long a[500050];
long long dp[500050];
long long c[1001010];

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("crystal,in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		dp[i] = a[i + 1] - a[i];
	}
	int ans = 0;
	while (m > 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i + 1] == a[i + 2]) {
				if (m - dp[i] >= 0) {
					m -= dp[i];
					a[i] = a[i + 1];
					dp[i] = 0;
					dp[i - 1] = a[i] - a[i - 1];
					ans++;
				}
			} else if (a[i] == a[i + 1]) {
				continue;
			} else if (a[i + 1] != a[i + 2]) {
				if (dp[i] > dp[i + 1]) {
					if (m - dp[i + 1] >= 0) {
						m -= dp[i + 1];
						dp[i + 1] = 0;
						dp[i] = a[i + 1] - a[i];
						ans++;
					}
				} else {
					if (m - dp[i] >= 0) {
						m -= dp[i];
						dp[i] = 0;
						dp[i - 1] = a[i] - a[i - 1];
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
}