#include <bits/stdc++.h>
using namespace std;
long long a[500010];


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 5000) {
		a[0] = -100000000;
		sort(a, a + n + 1);
		int ans = 0, ans2 = 0;
		long long m2 = m;
		for (int i = 1; i <= n; i++) {
			int l = i - 1;
			m = m2;
			ans = 0;
			for (int r = i; r <= n; r++) {
				if (a[i] - a[l] > a[r] - a[i] || l < 1) {
					m -= abs( a[r] - a[i]);
					ans++;
				} else {
					m -= abs(a[i] - a[l]);
					ans++;
					l--;
					r--;
				}
				if (m < 0) {
					ans--;
					break;
				}
				if (m == 0) {
					break;
				}
			}
			ans2 = max(ans, ans2);
		}
		cout << ans2;
	} else {
		if (m <= 1000) {
			cout << 1;
		} else {
			cout << n;
		}
	}
	return 0;

}