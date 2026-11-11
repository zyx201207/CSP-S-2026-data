#include <bits/stdc++.h>
using namespace std;
long long n, c, t;
long long x[2000006];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		memset(x, 0, sizeof(x));
		long long n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (c == 13 || c == 14) {
			int tag;
			for (int i = 1; i <= n; i++) {
				if (x[i] - x[1] <= d && x[n] - x[i] <= d) {
					tag = i;
					break;
				}
			}
			long long ans = 0;
			for (int i = 1; i <= n; i++) {
				if (i >= tag + 1 && x[n] - x[i] <= d) {
					break;
				}
				for (int j = max(tag + 1, i + 1); j <= n; j++) {

					if (x[j] - x[i] <= d)
						continue;
					ans++;
				}
			}
			cout << ans << '\n';
		} else if (c == 11 || c == 12) {
			long long di = x[2] - x[1];
			if (d < 2 * di) {
				cout << 0 << '\n';
				continue;
			}
			if (d > x[n] - x[1]) {
				cout << 0 << '\n';
				continue;
			}
			d = (d / di);
			if (n < 2 * d) {
				cout << 0 << '\n';
				continue;
			}
			long long ans = 0;
			ans += (n - 2 * d + 1);
			cout << ans << '\n';
		} else
			cout << 0 << '\n';
	}
}