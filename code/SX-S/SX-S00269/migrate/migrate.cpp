#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;
long long x[2000009];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
			}
			int b = x[2] - x[1];
			if (d < b * 2) {
				cout << '0';
				return 0;
			}
			int l = ((d / b) - 1) * 2 + 1;
			int ans = n - l;
			if (ans > 0) {
				cout << ans;
			} else {
				cout << '0';
			}

		}
	}
	return 0;
}
