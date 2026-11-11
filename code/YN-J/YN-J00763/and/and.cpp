#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans, a[200005];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (m == 1) {
		cout << a[n];
	} else if (m == n) {
		ans = a[1];
		for (int i = 1; i <= n; i++) {
			ans = ans & a[i];
		}
		cout << ans;
	} else {
		for (int i = n; i >= 1; i--) {
			if ((a[i] & (a[i] - 1)) != 0) {
				ans = a[i];
				break;
			}
		}
		for (int i = 1; i <= m; i++) {
			ans = ans & a[n - i + 1];
		}
		cout << ans;
	}
	return 0;
}