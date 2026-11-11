#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		long long n, d;
		long long a[n + 10];
		cin >> n >> d;
		for (long long i = 0; i < n; i++) {
			cin >> a[i];
		}
		if ((a[n - 1] - a[0]) / (a[1] - a[0]) == n - 1 && (a[1] - a[0]) == (a[n - 1] - a[n - 2])
		        && (a[1] - a[0]) == (a[2] - a[1]) ) {
			long long cz = a[1] - a[0];
			if (d < 2 * cz)
				cout << 0 << endl;
			else {
				cout << n - 2 * d / cz + 1 << endl;
			}
		}
	}
	return 0;
}
