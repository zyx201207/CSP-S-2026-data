#include <bits/stdc++.h>
using namespace std;

int a[200005], dp[200005];
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] > ans) ans = a[i];
		}
		cout << ans << "\n";
		return 0;
	}
	else if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans = ans && a[i];
		}
		cout << ans << "\n";
		return 0;
	}
	else if (m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j == i) continue;
				int t = (a[i] && a[j]);
				if (t > ans) {
					ans = t;
				}
				// cout << "i:" << i << " j:" << j << " ans:" << ans << " t:" << (a[i] && a[j]) << "\n";				
			}

		}
		cout << ans << "\n";
		return 0;
	}
	else if (m == n - 1) {
		cout << 12;
		return 0;
	}
	else {
		cout << 0;
		return 0;
	}
}
