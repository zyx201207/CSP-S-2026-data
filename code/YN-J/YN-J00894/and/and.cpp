#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 2000) {
		if (m == 1) {
			sort(a + 1, a + 1 + n);
			cout << a[n];
		} else if (m == n) {
			long long ans = a[1];
			for (int i = 2; i <= n; i++)
				ans &= a[1];
			cout << ans;
		} else if (m == 2) {
			long long ans = -1e9;
			for (int i = 1; i < n; i++)
				for (int j = i + 1; j <= n; j++)
					ans = max(ans, a[i] & a[j]);
			cout << ans;
		}
	} else if (m == n - 1) {
		long long ans = -1e9;
		for (int i = 1; i <= n; i++) {
			long long t = -1;
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				if (t == -1)
					t = a[j];
				t &= a[j];
			}
			ans = max(ans, t);
		}
		cout << ans;
	} else {
		sort(a + 1, a + 1 + n);
		cout << a[n - m + 1];
	}
	return 0;
}