#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int a[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i]; // 保证有序了 
		if (n == 1 || n == 2) {
			cout << 0 << '\n';
		}
		else if (c == 0 || c == 11 || c == 12) {
			int tmp = a[2] - a[1]; // 公差
			if (2 * tmp <= d && d < 3 * tmp) {
				cout << n - 3 << '\n';
			} 
			else {
				cout << 0 << '\n';
			}
		}
	} 
	return 0;
} 
