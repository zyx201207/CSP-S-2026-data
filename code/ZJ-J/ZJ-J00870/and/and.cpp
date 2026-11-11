#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005];
bool f = 1;
bool check(int x) {
	for (int i = 1; i <= 30; i++) {
		if (pow(2, i) == x) return true;
	}
	return false;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f &= (a[i] < 4);
	}
	sort(a + 1, a + 1 + n, greater<int>());
	if (m == 1) cout << a[1] << endl;
	else if (m == 2) {
		int ans = -1e9;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
		cout << ans << endl;
	} else if (m == n) {
		int ans = a[1];
		for (int i = 1; i <= m; i++) ans &= a[i];
		cout << ans << endl;
	} else if (check(n)) {
		int ans = a[1];
		for (int i = 1; i <= m; i++) {
			ans &= a[i];
		}
		cout << ans << endl;
	} else if (f) {
		int ans = a[1];
		for (int i = 1; i <= m; i++) {
			ans &= a[i];
		}
		cout << ans << endl;
	} else {
		int ans = a[1];
		for (int i = 1; i <= m; i++) {
			ans &= a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
