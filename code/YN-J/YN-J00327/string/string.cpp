#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200005];
char c[200005];
int l, r;
int ans;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	l = 1, r = n;
	while (l < r) {
		if (c[l] == c[r]) {
			if (a[l] < a[r]) {
				a[r] -= a[l];
				a[l] = 0;
				l++;
			} else if (a[l] > a[r]) {
				a[l] -= a[r];
				a[r] = 0;
				r--;
			} else {
				a[l] = 0;
				a[r] = 0;
				l++, r--;
			}
		} else {
			if (a[l] < a[r]) {
				ans += a[l];
				a[r] -= a[l];
				a[l] = 0;
				l++;
			} else if (a[l] > a[r]) {
				ans += a[r];
				a[l] -= a[r];
				a[r] = 0;
				r--;
			} else {
				ans += a[l];
				a[l] = 0;
				a[r] = 0;
				l++, r--;
			}
		}
		//cout << a[l] << " " << a[r] << "   ";
	}
	cout << ans;
	return 0;
}