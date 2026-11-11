#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, l = LLONG_MAX, r = LLONG_MIN;
ll a[500010];

ll check(ll k) {
	ll w = m, u = upper_bound(a + 1, a + n + 1, k) - a, low = lower_bound(a + 1, a + n + 1, k - m) - a, cnt = 0;
	if (u == n + 1)
		return 0;
	for (int i = u - 1; i >= low ; i--) {
		if (a[i] == k)
			cnt++;
		else if (a[i] < k) {
			if (abs(a[i] - k) <= w) {
				cnt++;
				w -= abs(a[i] - k);
			} else
				break;
		}
	}
	return cnt;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], l = min(l, a[i]), r = max(r, a[i]);
	sort(a + 1, a + n + 1);
	if (a[2] - a[1] == a[4] - a[3]) {
		ll s = 0;
		for (int i = 1; i <= n; i++) {
			if (m >= a[i]) {
				s++;
				m -= a[i];
			} else
				break;
		}
		cout << s;
		return 0;
	}
	ll mid = 0, ans = LLONG_MIN;
	while (l <= r) {
		mid = (l + r) / 2;
		ll x = check(mid);
		if (x > 0) {
			ans = max(ans, x);
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
