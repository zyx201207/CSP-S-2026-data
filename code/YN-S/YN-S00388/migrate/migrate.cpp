#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, sum = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] < 2 * d && x[j] - x[i] > d && j - i > 2 && (i + j) % 2 != 0) {
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
