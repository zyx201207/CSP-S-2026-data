#include <bits/stdc++.h>
using namespace std;
long long a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t, ans;
	cin >> c >> t;
	while (t--) {
		ans = 0;
		long long n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + d + 1; j <= n; j++) {
				int ch = a[j] - a[i], f = 0;
				for (long long k = 1; k <= d; k++)
					if ((ch - k) <= d)
						f++;
				if (f == 2)
					ans++;
			}
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++)
			a[i] = 0;
	}
	return 0;
}
