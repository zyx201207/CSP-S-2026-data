#include <bits/stdc++.h>
using namespace std;
long long c, t;
long long a[2000005], d, n;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		long long y = abs(a[2] - a[1]);
		long long x = d / y;
		if (x <= 1)
			cout << 0 << endl;
		else if (n - 2 * x + 1 <= 0)
			cout << 0 << endl;
		else
			cout << n - 2 * x + 1 << endl;
	}
	return 0;
}
