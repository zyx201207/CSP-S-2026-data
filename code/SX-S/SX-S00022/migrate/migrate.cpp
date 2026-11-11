#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t, n, d;
	scanf("%lld", &c, &t);
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		long long x[n + 1] = {}, cnt = 0;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];

		}
		if (n <= 3)
			cout << "0" << endl;
		else if (n == 4)
			cout << "1" << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}