#include <bits/stdc++.h>
using namespace std;
long long a[1000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, sum = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long m = a[2] - a[1];
		if (m >= d || n <= 3 || (n - 1) * m - d <= 1 || d % m != 0 && 2 * m > d) {
			cout << 0;
		} else {
			for (int i = 1; i <= d - 1; i++) {
				if ((d + i) % m == 0 && n - d - i > 0) {
					sum += n - d - i;
				}

			}
			cout  << sum;
		}
	}
	return 0;
}
