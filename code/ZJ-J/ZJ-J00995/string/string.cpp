#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
ll a[N];
char c[N];
ll ans;
int main () {

	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	ll res = 0, tot = 0;
	while (l <= r) {
		res += a[l];
		tot += a[r];
		if (res == tot) {
			if (c[l] != c[r]) ans += a[l];
			l++;
			r--;
			continue;
		}
		bool f = 0;
		while (res > tot) {
			f = 1;
			if (c[l] != c[r]) ans += a[r];
			r--;
			ll t = a[r];
			a[r] -= (res - tot);
			if (a[r] < 0) {
				a[r] = 0;
			}
			if (c[l] != c[r]) ans += min (t, res - tot);
			tot += min (t, res - tot);
		}
		if (f) l++;
		f = 0;
		while (res < tot) {
			f = 1;
			if (c[l] != c[r]) ans += a[l];
			l++;
			ll t = a[l];
			a[l] -= (tot - res);
			if (a[l] < 0) a[l] = 0;
			if (c[l] != c[r]) ans += min (t, tot - res);
			res += min (t, tot - res);
		}
		if (f) r--;
	}
	cout << ans;
	return 0;
}
