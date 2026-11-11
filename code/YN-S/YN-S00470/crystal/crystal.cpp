#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m, cnt = 0, minn = LLONG_MAX, maxn = LLONG_MIN;
	cin >> n >> m;
	bool f = true;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 3 && a[i] - a[i - 1] != a[2] - a[1]) {
			f = false;
		}
		cnt += a[i];
		minn = min(minn, a[i]);
		maxn = max(maxn, a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (f) {
		ll b = cnt / n;
		ll c = lower_bound(a + 1, a + 1 + n, b) - a;
		ll l = c - 1, r = c, sum = 0, ans = 0;
		while (1) {
			if (l >= 1) {
				sum += (b - a[l]);
				ans++;
			}
			if (r <= n) {
				sum += (a[r] - b);
				ans++;
			}
			if (sum > m) {
				if (sum - (b - a[l]) <= m) {
					ans--;
				} else {
					ans -= 2;
				}
				break;
			}
			if (l <= 0 && r > n) {
				break;
			}
			l--;
			r++;
		}
		cout << ans;
		return 0;
	}
	ll maxnn = 0;
	for (ll i = minn; i <= maxn; i++) {
		ll c = lower_bound(a + 1, a + 1 + n, i) - a;
		ll l = c - 1, r = c, sum = 0, ans = 0;
		while (1) {
			if ((l >= 1 && i - a[l] < a[r] - i) || r > n) {
				ans++;
				sum += i - a[l];
				l--;
			} else if ((r <= n && i - a[l] > a[r] - i) || l <= 0) {
				ans++;
				sum += a[r] - i;
				r++;
			} else {
				if (l - 1 >= n - r) {
					ans++;
					sum += i - a[l];
					l--;
				} else {
					ans++;
					sum += a[r] - i;
					r++;
				}
			}
			if (sum > m) {
				ans--;
				break;
			}
			if (l < 1 && r > n) {
				break;
			}
		}
		maxnn = max(maxnn, ans);
	}
	cout << maxnn;
	return 0;
}