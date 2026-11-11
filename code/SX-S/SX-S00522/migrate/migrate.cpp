#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 0; i < t; i++) {
		int ans = 0;
		int n, d;
		cin >> n >> d;
		int x[500100];
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (d <= 1 || n <= 3) {
			cout << 0 << endl;
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = i + d + 1; j <= n; j++) {
					if (d < x[j] - x[i] && (x[j] - x[i]) < (2 * d)) {
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
	}
}