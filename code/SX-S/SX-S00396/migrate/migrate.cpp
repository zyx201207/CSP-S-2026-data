#include <bits/stdc++.h>
using namespace std;
const int N = 3000010;
long long c, t, n, d;
long long a[N], f[N];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long k = a[2] - a[1];
		if (k > d) {
			cout << '0' << "\n";
			continue;
		}
		long long b = floor(d * 1.0 / k);
		f[1] = 1;
		for (long long i = 2; i <= n; i++) {
			for (int j = 1; j <= b; j++) {
				if (i - j >= 1) {
					f[i] += f[i - j];
				}
			}
		}
		cout << floor(f[n] * 1.0 / 2) << "\n";
		for (int i = 1; i <= n; i++) {
			f[i] = 0;
		}
	}
	return 0;
}