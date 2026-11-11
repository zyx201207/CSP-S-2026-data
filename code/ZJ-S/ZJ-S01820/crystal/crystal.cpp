#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;
long long m, a[500010], minn = 1e18, maxn = -1e18;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
	sort(a + 1, a + n + 1);
	if ((maxn - minn) * n > 1e9) {
		long long t = a[2] - a[1];
		int l = 1, r = n;
		while (l <= r) {
			long long mid = ((l + r) >> 1);
			if ((double)mid * (mid - 1) * t < 2e18 + 1 && mid * (mid - 1) * t <= (m << 1ll)) {
				l = mid + 1;
				ans = mid;
			} else r = mid - 1;
		}
		cout << ans;
		return 0;
	}
	for (int i = minn; i <= maxn; i++) {
		int x = upper_bound(a + 1, a + n + 1, i) - a, cnt = 0;
		long long cur = m;
		for (int j = x - 1; j >= 1; j--) {
			if (cur - (i - a[j]) >= 0) {
				cur -= (i - a[j]);
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}