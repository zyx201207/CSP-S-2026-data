#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
int n, d;
int x[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		bool flag = 0;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (x[i] - x[1] <= d && x[n] - x[i] <= d) {
				flag = 1;
				cnt++;
			}
		}
		if (flag == 1) {
			cout << max(n - (d * d) + 1, 0) << "\n";
		}
	}
	return 0;
}
