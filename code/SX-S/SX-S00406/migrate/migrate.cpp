#include <bits/stdc++.h>
using namespace std;
long long a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int T = 1; T <= t; T++) {
		long long n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if ((a[n] - a[1]) <= d)
			cout << "0" << endl;
		else if ((c == 11) || (c == 12)) {
			long long ui, ans = 0;
			ui = (d / (a[2] - a[1]));
			if (d < (2 * (a[2] - a[1])))
				cout << "0" << endl;
			else if ((ui * 2) > n)
				cout << "0" << endl;
			else {
				ans = (n - (ui * 2) + 1);
				cout << ans << endl;
			}
		} else {
			long long ans = 0;
			for (int i = 1; i < n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = i + 1; k < j; k++) {
						if ((k + 2 <= j) && ((a[k + 1] - a[i]) <= d) && ((a[k + 2] - a[i]) > d)) {
							if (((a[j] - a[k - 1]) > d) && ((k - 1) >= i) && ((a[j] - a[k]) <= d)) {
								ans++;
							}
						}
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
