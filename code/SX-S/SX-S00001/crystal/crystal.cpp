#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005];

bool check(ll mid) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= mid)
			break;
		sum += mid - a[i];
	}
	return sum > m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ll mx = -1e18, mn = 1e18;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	sort(a + 1, a + n + 1);
	ll l = mn, r = mx, ans;
	while (l <= r) {
		ll mid = (l - r) / 2 + r;
		if (check(mid)) {
			r = mid - 1;
		} else {
			ans = mid;
			l = mid + 1;
		}
	}
	ans = upper_bound(a + 1, a + n + 1, ans) - a - 1;
	cout << ans;
	return 0;
}