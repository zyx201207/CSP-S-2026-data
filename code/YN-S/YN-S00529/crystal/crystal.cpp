#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans, k, a[500005], s[500005];

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		ll l = a[1] - 1, r = a[n] + 1;
		while (l <= r) {
			ll mid = (l + r) / 2;
			ll t = upper_bound(a + 1, a + 1 + n, mid) - a - 1;
			if (mid > k * 1.0 / (t - i + 1) + (s[t] - s[i - 1]) * 1.0 / (t - i + 1)) {
				r = mid - 1;
			} else {
				l = mid + 1, ans = max(ans, t - i + 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
