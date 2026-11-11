#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], diff[N], ans;

signed main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		diff[i] = a[i] - a[i - 1];
	}
	int l = 1, r = 0, sum = 0;
	while (r <= n) {
		while (r <= n && sum <= m) {
			ans = max (ans, r - l + 1);
			r++;
			sum += (r - l) * diff[r];
		}
		while (l <= r && sum > m) {
			sum -= a[r] - a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}
/*
2026.10.31 14:55
100 pts?
*/
