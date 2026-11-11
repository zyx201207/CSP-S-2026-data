#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];

signed main() {
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int num = d / (a[2] - a[1]);
		if (num <= 1) {
			cout << 0 << '\n';
		} else {
			int ans = n - num * 2 + 1;
			if (ans <= 0) {
				cout << 0 << '\n';
			} else {
				cout << ans << '\n';
			}
		}
	}
	return 0;
}
