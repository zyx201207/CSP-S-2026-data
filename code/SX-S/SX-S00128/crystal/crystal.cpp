#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int prev_dis[500010];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; x++) {
		cin >> a[x];

	}
	int ans = 1;
	sort(a, a + n);
	for (int x = 0; x < n; x++) {
		if (x != 0)
			prev_dis[x] = (x + 1) * (a[x] - a[x - 1]) + prev_dis[x - 1];
	}
	for (int x = 0; x < n; x++) {
		if (prev_dis[x] <= m) {
			ans = max(ans, x + 1);
			continue;
		}
		int delta = prev_dis[x] - m;
		int l, r;
		l = 0, r = x;
		int mid;
		while (l < r) {
			mid = (l >> 1) + (r >> 1);
			if (prev_dis[mid] + (mid + 1) * (a[x] - a[mid]) < delta) {
				l = mid + 1;
			} else
				r = mid;
		}
		ans = max(ans, x - l + 1);
	}
	cout << ans;
	return 0;
}
