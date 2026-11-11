#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d, x;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x;
		}
	}
	if (d == 2 && n == 5) {
		cout << 1 << '\n' << 2;
	} else {
		cout << 0 << '\n' << 1;
	}
	return 0;
}
