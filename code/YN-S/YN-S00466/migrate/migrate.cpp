#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int c, t, n, d;
	cin >> c >> t;
	while (t--) {
		memset(x, 0, sizeof(x));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int cnt = 0, cnt2 = 0;
		for (int i = 1; i <= n - 3; i ++) {
			for (int j = i + 3; j <= n; j++) {
				cnt2 = 0;
				for (int q = i + 1; q <= j - 1; q++) {
					cout << x[i] << " " << x[q]  << " " << x[j] << endl;
					if (x[q] - x[i] <= d && x[j] - x[q] <= d) {
						cnt2++;
					}
				}
				if (cnt2 == 2) {
					cnt++;
				}
			}

		}
		cout << cnt << endl;
	}
	return 0;
}