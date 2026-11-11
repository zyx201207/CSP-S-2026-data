#include <bits/stdc++.h>
using namespace std;
long long n, ti, c, t;
long long da[1000000];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> n >> ti;
		if (n < 4) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i <= n; i++) {
			cin >> da[i];
		}
		long long ss = 0;
		for (int i = 1; i <= n - 3; i++) {
			if ((da[i + 3] - da[i + 2]) == (da[i + 2] - da[i + 1]) == (da[i + 1] - da[i])) {
				if ((da[i + 2] - da[i]) == ti) {
					ss++;
				}
			}
		}
		cout << ss << endl;
	}

	return 0;
}