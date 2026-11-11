#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[2000005], mx, mmx, ans, yyy;


signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mmx = max(mmx, a[i]);
	if (m == 1) {
		cout << mmx;
		return 0;
	} else if (m == 2) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
//			cout << a[i] << ' ' << a[j] << ' ' << (a[i]&a[j]) << '\n';
				mx = max(mx, a[i] & a[j]);
			}
		cout << mx;
	} else if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++)
			ans &= a[i];
		cout << ans;
	} else if (m == n - 1) {
		for (int i = 1; i <= n; i++) {
			if (i != 1)
				ans = a[1];
			else if (i != 2)
				ans = a[2];
			for (int j = 2; j <= n; j++) {
				if (j != i)
					ans &= a[j];
			}
			yyy = max(yyy, ans);
		}
		cout << yyy;
	} else {
		cout << mmx - 1;
	}
	return 0;
}