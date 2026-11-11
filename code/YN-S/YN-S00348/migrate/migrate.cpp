#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, a[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (d == 1) {
			cout << "0\n";
			continue;
		}
		int c = a[2] - a[1];
		if (d == c) {
			cout << "0\n";
		}
		cout << n - d - c << "\n";
	}
	return 0;
}