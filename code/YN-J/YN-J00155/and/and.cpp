#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, a[i]);
		}
		cout << ans << endl;
	} else if (m == n) {
		int ans = a[0];
		for (int i = 1; i < n; i++) {
			ans = ans & a[i];
		}
		cout << ans << endl;
	} else if (m == 2) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	} else if (m == (n - 1)) {
		int ans = 0, an = 0;
		for (int i = 0; i < n; i++) {
			an = 0;
			for (int j = 0; j < n; j++) {
				if (j == i) {
					continue;
				} else {
					an = an & a[j];
				}
			}
			ans = max(ans, an);
		}
		cout << ans;
	} else {
		cout << m << endl;
	}
	return 0;
}