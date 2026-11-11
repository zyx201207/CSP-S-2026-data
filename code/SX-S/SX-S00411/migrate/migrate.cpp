#include <bits/stdc++.h>
using namespace std;
const int M = 2e6+10;
long long x[M];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c;
	long long t, n, d;
	cin >> c >> t;
	while (t--) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		long long k = x[2] - x[1];
		long long f = k;
		if (k >= d) {
			cout << "0" << "\n";
		} else {
			if (2 * k > d) {
				cout << "0" << "\n";
			} else {
				k = 0;
				long long p = 0;
				while (k < d) {
					k += f;
					p++;
					if (k > d) {
						p--;
						break;
					}
				}
				p *= 2;
				p -= 1;
				long long sum = 0;
				for (int i = 1; i <= n; i++) {
					if (i + p <= n)
						sum++;
					else
						break;
				}
				cout << sum << "\n";
			}
		}
	}
	return 0;
}