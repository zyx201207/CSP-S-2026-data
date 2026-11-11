#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200005];
signed main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	if (m == n) {
		for (int i = 2; i <= n; i++) {
			a[i] = a[i] & a[i-1];
		}
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		int ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if (m == n - 1) {
		int b[200005], ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				b[i] = a[i];
			}
			b[i] = 2147483647;
			for (int j = 2; j <= n && j != i; j++) {
				b[i] = b[i] & b[i-1];
			}
			ans = max(ans, b[n]);
		}
		cout << ans;
		return 0;
	}
	return 0;
}
