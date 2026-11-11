#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10000005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		int f = 0, k = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans = a[2] - a[1];
		for (int i = 2; i <= n; i++) {
			if (a[i] - a[i - 1] == ans) {
				f = 1;
			} else {
				f = 0;
				break;
			}
		}
		if (f == 1) {

			int tiao = d / ans;
			cout << n - tiao - 1;
		} else if (n <= 3) {
			cout << 0;
		} else {
			cout << n - d + 1;
		}

	}
	return 0;
}
