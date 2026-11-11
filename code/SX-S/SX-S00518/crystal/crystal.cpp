#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500005];
int c[500005];
bool l = 1;
int ans = 1;
int dp[500005];
int k[500005];
int last = 1;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[1] = 0;
	k[1] = 1;
	for (int i = 2; i <= n; i++) {
		int p = m - dp[i - 1];
		int q = a[i] - a[i - 1];
		if (q > m) {
			dp[i] = 0;
			k[i] = i;
			last = i;
		} else if (q == 0) {
			dp[i] = dp[i - 1];
			k[i] = k[i - 1];
		} else if ((p / q) > (i - last)) {
			dp[i] = dp[i - 1] + q * (i - last);
			k[i] = k[i - 1];
		} else {
			while ((p / q) < (i - last)) {
				p = p + a[i] - a[last];
				last++;
			}
			dp[i] =  m - p + q * (i - last);
			k[i] = last;
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, i - k[i] + 1);
	}
	cout << ans;
	return 0;
}