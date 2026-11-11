#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
const ll INF = 1e18 + 10;
ll n, m, ans = 0;
ll a[N], fs[N], zs[N], f[N];
ll l = INF, r = -INF, mid;
int get (int l, int r) {
	if (f[r] - f[l - 1] == 0) {
		return (r - l + 1) * a[r] - (zs[r] - zs[l - 1]);
	} else if (r - l + 1 == f[r] - f[l - 1]) {
		return (r - l + 1) * a[r] - (fs[r] - fs[l - 1]);
	} else {
		return (r - l + 1) * a[r] - (zs[r] - zs[l - 1]) + (fs[r] - fs[l - 1]);
	}
}
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	cin >> n >> m;
	bool flagA = true, flagB = true;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		l = min (l, a[i]);
		r = max (r, a[i]);
		if (a[i] != i) flagA = false;
		if (i != 1) {
			if (a[i] - a[i - 1] != a[2] - a[1]) flagB = false;
		}
	}
	if (flagA) {
		int sum = 0, i = 0;
		while (sum + i <= m) {
			sum += i;
			i++;
			ans++;
			if (ans >= n) {
				break;
			}
		}
		cout << ans;
	} else if (flagB) {
		sort (a + 1, a + 1 + n);
		int sum = 0, i = 0, c = a[2] - a[1];
		while (sum + i <= m) {
			sum += i;
			i += c;
			ans++;
			if (ans == n) {
				break;
			}
		}
		if (ans != n && a[1] == 0) ans++;
		cout << ans;
	} else {
		sort (a + 1, a + 1 + n);
		for (ll i = 1; i <= n; i++) {
			zs[i] = zs[i - 1] + (a[i] > 0 ? a[i] : 0);
			fs[i] = fs[i - 1] + (a[i] < 0 ? -a[i] : 0);
			f[i] = f[i - 1] + (a[i] < 0 ? 1 : 0);
		}
		for (ll i = 1; i <= n; i++) {
			int l = 1, r = i - 1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (get (mid, i) <= m) {
					ans = max (ans, i - mid + 1);
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
