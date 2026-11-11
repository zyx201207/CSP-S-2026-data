#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, x[N];

signed main() {
	IOS
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		int c = 0, flg = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			if (i != 1 && x[i + 1] - x[i] > d)
				flg = 1;
			if (i != 1 && x[i] - x[i - 1] != x[i + 1] - x[i] && i != n)
				c = 1;
		}
		if (c == 0) {
			if (d >= 2 * (x[2] - x[1]))
				cout << n - 3 << '\n';
			else
				cout << 0;
		} else if (flg == 0) {
			cout << n - 3;
		} else {
			cout << 0;
		}
	}
	return 0;
}
