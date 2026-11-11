#include <bits/stdc++.h>
using namespace std;
long long x[2000006];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (d == 2) {
			cout << n - 4;
		} else if (d >= 3 && n >= d + 2) {
			cout << 0;
		} else if (n < d + 2 && d >= 3) {
			cout << 0;
		} else {
			cout << 2;
		}
	}
	return 0;
}
