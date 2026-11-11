#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 5e5 + 10;
int a[N], w[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t, flag = 1;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i >= 2 && (a[i] - a[i - 1]) != a[i - 1] - a[i - 2]) {
				flag = 0;
			}
		}
		if (flag) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if ((d / a[2] - a[1]) - (i - 2) * (d / a[2] - a[1]) == 2) {
					ans += n - i + 1;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}