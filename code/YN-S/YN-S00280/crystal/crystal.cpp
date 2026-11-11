#include <bits/stdc++.h>
using namespace std;
int n;
long long m, ans, l = 1, r = 1;
long long a[500010], dp[500010], ma = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	while (r <= n) {
		if (r == 1) {
			dp[r] = 0;
		} else {
			dp[r] = (a[r] - a[r - 1]) * (r - l) + dp[r - 1];
		}
		if (dp[r] > m) {
			ans = max(ans, r - l );
			l = r - 1;
			dp[r] = 0;
			a[l] = 0;
		}
		if (r == n) {
			ans = max(ans, r - l);
		}
		r++;
	}
	cout << ans;




	return 0;
}