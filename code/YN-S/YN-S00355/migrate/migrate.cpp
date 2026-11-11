#include <bits/stdc++.h>
using namespace std;

long long c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	while (t--) {
		long long n, d;
		int t, s;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> t;
			if (i == 1)
				s = t;
		}
		if (d < s * 2) {
			cout << 0 << endl;
		} else {
			if (t < 2 * d) {
				cout << 0 << endl;
			} else {
				cout << t - 2 * d + 1 << endl;
			}
		}
	}




	return 0;
}