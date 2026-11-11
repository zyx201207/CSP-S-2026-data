#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int n, d, x[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		//memset(dp, 0, sizeof dp);
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		//if (c == 11 || c == 12) {
			d++;
			if (d % 2 == 1) {
				int p = lower_bound(x + 1, x + 1 + n, x[n] - d) - x;
				cout << p << endl;
			} else {
				cout << 0 << endl;
			}
		//}
	}
	return 0;
}