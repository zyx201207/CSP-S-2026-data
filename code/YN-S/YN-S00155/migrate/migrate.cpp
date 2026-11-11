#include <bits/stdc++.h>
using namespace std;


signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, x[(int)2e6 + 10];
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		cout << d << '\n';
	}


	return 0;
}
