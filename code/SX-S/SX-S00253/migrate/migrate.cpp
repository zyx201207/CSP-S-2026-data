#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005], ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		d = d / (a[2] - a[1]);
		for (int i = n; i >= d; i--) {
			if ((i - d) % d != 0) {
				ans = ans + (i - d) - (i - d) / d - 1;
			} else {
				ans = ans + (i - d) - (i - d) / d;
			}
		}
		cout << ans << endl;
	}
	return 0;
}