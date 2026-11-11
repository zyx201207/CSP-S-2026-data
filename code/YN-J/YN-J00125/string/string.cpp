#include <bits/stdc++.h>
using namespace std;
char c[200005], xl, xr;
long long cnt, ans, lk, rk, kl, kr, n, a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	lk = 1;
	rk = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	while (lk < rk) {
		if (kl) {
			if (a[rk] < kl) {
				if (xl != c[rk])
					ans += a[rk];
				kl -= a[rk];
				rk--;
				continue;
			}
			a[rk] -= kl;
			if (xl != c[rk])
				ans += kl;
			kl = 0;
		} else if (kr) {
			if (a[lk] < kr) {
				if (xr != c[lk])
					ans += a[lk];
				kr -= a[lk];
				lk++;
				continue;
			}
			a[lk] -= kr;
			if (xr != c[lk])
				ans += kr;
			kr = 0;
		}
		if (a[lk] == a[rk]) {
			if (c[lk] != c[rk])
				ans += a[lk];
		} else if (a[lk] < a[rk]) {
			if (c[lk] != c[rk])
				ans += a[lk];
			kr = a[rk] - a[lk];
			xr = c[rk];
		} else {
			if (c[lk] != c[rk])
				ans += a[rk];
			kl = a[lk] - a[rk];
			xl = c[lk];
		}
		lk++, rk--;
	}
	if (kl) {
		a[rk] -= kl;
		if (xl != c[rk])
			ans += kl;
	} else if (kr) {
		a[lk] -= kr;
		if (xr != c[lk])
			ans += kr;
	}
	cout << ans;
	return 0;
}