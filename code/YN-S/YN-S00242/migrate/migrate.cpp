#include <bits/stdc++.h>
using namespace std;

int c, t, n, d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> c >> t;

	while (t--) {
		cin >> n >> d;

		for (int i = 1, j; i <= n; i++) {

			cin >> j;
		}

		if (n % d) {
			cout << n / d << '\n';
		} else {
			cout << n / d - 1 << '\n';
		}
	}

	return 0;
}
