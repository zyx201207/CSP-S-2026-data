#include <bits/stdc++.h>
using namespace std;

#define int long long

int c, t, n, d, x[2000010];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;

	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];

		cout << (x[n] - x[1] - 2) / (d - 1) << endl;
	}

	return 0;
}
