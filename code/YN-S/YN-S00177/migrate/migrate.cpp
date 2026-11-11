#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c, t;
int n, m;
int a[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			cin >> n >> m;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (i + 2 * m - 1 <= n) {
					ans++;
				}
			}
			cout << ans << endl;
		}
	} else {
		while (t--) {
			cin >> n >> m;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + m + 1; j <= n; j++) {
					int cnt = 0;
					for (int k = i + 1; k < j; k++) {

						if (a[k] <= a[i] + m && a[k] >= a[j] - m) {
							cnt++;
						}
					}
					if (cnt == 2) {
						ans++;
					}
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/