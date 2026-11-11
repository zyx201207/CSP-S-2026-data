#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
#define int long long
int c, T, n, d, a[N], cnt, flag1 = 1, flag2 = 1, dd;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		//	cout << -1;
		for (int i = 2; i < n; i++) {
			dd = abs(a[i] - a[i - 1]);
			if ((a[i] - a[i - 1]) == (a[i + 1] - a[i])) {
				break;
			}
		}
		//	cout << flag1 << "%";
		if (flag1 == 1) {
			if (d < dd) {
				cout << 0 << "\n";
			} else {
				int x = d / dd;
				cout << n % d + 1 << "\n";
			}
		} else {
			cout << 0 << "\n";
		}
		flag1 = 1;
	}
	return 0;
}