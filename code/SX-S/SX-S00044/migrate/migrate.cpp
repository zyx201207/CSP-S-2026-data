#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d;
long long x[2000006];
int cz;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
		}
		cz = x[2] - x[1];
		if (d < cz * 2)
			cout << 0 << "\n";
	}

	return 0;
}
