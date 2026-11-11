#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		int a[n + 3];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int sum = 0, num = 0, pum = 0;
		for (int i = 1; i <= n; i++) {
			int dx = a[i + 1] - a[i];
			int d1, d2;
			if (a[i] <= a[i] + d) {
				num++;
				continue;
			}
			if (a[i] != a[i] + d) {
				if (a[i] % d == 0) {
					d1 = a[i];
					d2 = a[i] + d;
					sum++;
				}
				int x, y;
				for (int j = 1; j <= n; j++) {
					if (a[j] == d1) {
						x = j;
					}
					if (a[j] == d2) {
						y = j;
					}
				}
				int z = x - y;

				if ((a[i] - dx) % d == 0) {
					pum++;
					continue;
				}
				if (z > 1) {
					cout << n - n / d + 1 - num - pum;
					return 0;
				} else {
					cout << sum;
					return 0;
				}
			}

		}
		cout << 0;
	}
	return 0;
}
