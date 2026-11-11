#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, m, b, num;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		cin >> n >> d;
		if (d == 1) {
			cout << 0;
			break;
		}
		long long x[n + 5], a[n + 5];
		x[0] = 0;
		for (long long i = 1; i <= n; i++) {
			cin >> x[i];
		}
		b = 1;
		for (long long i = 1; i < n; i++) {
			for (long long j = 2; j <= n; i++) {
				if (x[i] + d >= x[j]) {
					a[b] = x[j];
					b++;
					m++;
					if (m == 2) {
						if (a[b - 2] == a[b - 1])
							num++;
						break;
					}

				}


			}
		}
		cout << num;

	}
	cout << 1 << '/n' << 2;
	return 0;
}