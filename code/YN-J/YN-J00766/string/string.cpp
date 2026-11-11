#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
char c[100005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	long long k = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		k += a[i];
	}
	int l = 1, r = n;
	long long ans = 0;
	while (l <= r) {
		if (c[l] != c[r]) {
			if (a[l] < a[r]) {
				ans += a[l];
				a[r] -= a[l];
				l++;
			} else {
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
		} else {
			if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else {
				a[l] -= a[r];
				r--;
			}
		}
	}
	cout << ans << '\n';


	return 0;
}