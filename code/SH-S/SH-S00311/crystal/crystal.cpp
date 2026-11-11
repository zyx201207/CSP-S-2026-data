#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010], d[500010];
ll n, m;
bool check(int mid) {
	ll minn = 1e18;
	for (int i = 1; i <= n; i++) {
		if (i - mid + 1 < 1) {
			continue;
		}
		minn = min(minn, a[i] * mid - (d[i] - d[i - mid]));
	}
	return minn <= m;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ll minn = 1e18, maxn = -1e18;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(minn, a[i]);
		maxn = max(maxn, a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + a[i];
	}
	ll l = 1, r = n, ans = 1;
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		if (check(mid) == 1) {
			ans = mid;
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
