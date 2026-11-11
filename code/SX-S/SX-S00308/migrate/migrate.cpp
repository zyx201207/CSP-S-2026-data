#include <bits/stdc++.h>
using namespace std;
int c, t;
long long n, d;
int x[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
			if (i >= 1) {
				x[i] = abs(x[i - 1] - x[i]);
			}

		}
		if (c == 11 || c == 12) {
			int res = 0;
			if (d >= 2 * x[1]) {
				res += n - 3;
			}
			cout << res << endl;
		}
	}
	return 0;
}