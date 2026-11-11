#include <bits/stdc++.h>
using namespace std;
const long long N = 5e3+5;
long long c, t, n, d, x[N], a[N], res;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		res = 0;
		for (long long i = 1; i <= n; i++)
			cin >> x[i];
		for (long long i = 1; i <= n; i++) {
			if (x[i] + d >= x[n])
				a[i] = n;
			else {
				long long tt = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
				if (x[i] + d >= x[tt])
					a[i] = tt;
				else
					a[i] = tt - 1;
			}
		}
		for (long long i = 1; i <= n; i++) {
			for (long long j = i + 3; j <= n; j++) {
				long long k = i, sum = 0, tot = 1;
				while (k < j) {
					if (k == a[k]) {
						sum = 1e18;
						break;
					}
					k = a[k];
					sum++;
				}
				k = a[i] - 1;
				while (k < j) {
					if (k == a[k])
						break;
					k = a[k];
					tot++;
				}
				if (tot != sum)
					break;
				k = a[i] - 2;
				tot = 1;
				while (k < j) {
					if (k == a[k])
						break;
					k = a[k];
					tot++;
				}
				if (tot == sum)
					continue;
				res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}
