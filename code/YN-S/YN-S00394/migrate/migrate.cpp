#include <bits/stdc++.h>
using namespace std;

int c, t, n, d, x[2000060], sum;

int main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			int frt = x[i];
			int rx = x[n] - x[i];
			if (rx <= d || rx % d == 0) {
				sum += 0;
			} else {
				if (rx >= 2 * d - 1) {
					sum += d - 1;
				} else {
					sum += rx - d;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}