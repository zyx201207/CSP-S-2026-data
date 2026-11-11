#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], dp[500005], ans, cz[500005], d[500005];

int l_bd(int x) {
	int l = x + 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (dp[mid] - a[mid] * (x - 1) + d[x - 1] <= m) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int r = l_bd(i);
		ans = max(ans, r - i + 1);
	}
	cout << ans;
	return 0;
}