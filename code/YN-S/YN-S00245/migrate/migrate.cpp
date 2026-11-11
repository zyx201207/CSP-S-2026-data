#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c, t;
	cin >> c >> t;
	int ans[t];
	for (long long i = 0; i <= t; i++)
		ans[i] = 0;

	for (long long i = 1; i <= t; i++) {

		long long n, d;
		cin >> n >> d;
		long long a[n], b[n];
		for (long long j = 1; j <= n; j++)
			cin >> a[j];
		sort(a + 1, a + n + 1);
		long long h = 0;
		b[1] = h;
		for (long long j = 2; j <= n; j++) {
			if (a[j] - a[j - 1] > d ) {
				h++;
				b[j] = h;
			} else {
				b[j] = h;
			}

		}

		for (long long f = 0; f <= h; f++) {
			for (long long j = 1; j <= n; j++) {
				if (j + 3 > n)
					break;
				if (b[j] != f || b[j + 3] != f)
					continue;
				if (a[j + 2] - a[j] >= d)
					ans[i]++;

			}

		}

	}

	for (long long i = 1; i <= t; i++) {

		cout << ans[i] << endl;
	}

	return 0;
}