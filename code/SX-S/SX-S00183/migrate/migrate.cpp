#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		long long n, d;
		long long x, y;
		scanf("%lld%lld", &n, &d);
		scanf("%lld%lld", &x, &y);
		int xx = y - x;
		bool b = 1;
		for (long long i = 3; i <= n; i++) {
			scanf("%lld", &x);
			if (x - y != xx) {
				b = 0;
			}
			y = x;
		}
		if (b == 1) {
			if (xx * 3 <= 2 * d && xx * 3 > d) {
				cout << n - 3 << endl;
				continue;
			} else {
				cout << 0 << endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}