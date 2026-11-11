#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
long long a[N];

int main() {
	long long c, t, n, d, f;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		f = a[n] - a[n - 1];
		for (int i = n; i >= 2; i--) {
			if (a[i] - a[i - 1] != f) {
				f = -1;
				break;
			}
		}
		if (f != -1) {
			if (d < f * 2) {
				cout << 0 << "\n";
				continue;
			}
			f = d / f * 2;
			printf("%lld\n", max(n - f + 1, 0 * 1ll));
		} else {
			cout << 0 << "\n";
		}
	}
	return 0;
}
