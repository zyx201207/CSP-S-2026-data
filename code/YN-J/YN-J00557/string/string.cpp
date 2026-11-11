#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];

signed main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	int l = 1, r = n, ans = 0;
	while (l < r) {
		if (a[l] <= a[r]) {
			a[r] -= a[l];
			if (c[l] != c[r]) {
				ans += a[l];
			}
			a[l] = 0;
			l ++;
		} else {
			a[l] -= a[r];
			if (c[l] != c[r]) {
				ans += a[r];
			}
			a[r] = 0;
			r --;
		}
	}
	cout << ans;
	return 0;
}