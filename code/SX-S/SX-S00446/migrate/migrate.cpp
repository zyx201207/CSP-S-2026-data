#include <bits/stdc++.h>
using namespace std;
long long n, c, t, d, x[2000010], ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[i];
		}
		if (n <= 3) {
			cout << 0 << '\n';
			continue;
		}
		int s = x[2] - x[1];
		if (d >= 2 * s && d < 3 * s) {
			cout << n - 3 << '\n';
		} else
			cout << 0 << '\n';
	}
	return 0;
}
