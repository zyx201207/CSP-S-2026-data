#include<bits/stdc++.h>
using namespace std;
long long c, t, n, m, a[2000010], ans, l, r;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		memset(a, 0, sizeof a);
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c == 11 or c == 12 or c == 0) {
			if (m < 2 * (a[2] - a[1])) {
				cout << "0\n";
				continue;
			}
//			cout << max(n - (m + a[2] - a[1] - 1) / (a[2] - a[1]) - (m + a[2] - a[1] - 1)/ (2 * (a[2] - a[1])), (long long)(0)) << endl;
//			continue;
		}
		for (int i = 1; i <= n; i++) {
			l = upper_bound(a + 1, a + i + 1, a[i] - m - 1) - a;
			for (int j = i - 3; j >= 1; j--) {
				r = upper_bound(a + j + 1, a + i + 1, a[j] + m) - a - 1;
				if (r - l == 1) {
					ans++;
				}
				if (l > r) break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
