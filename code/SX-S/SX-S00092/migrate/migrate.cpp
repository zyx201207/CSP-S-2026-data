#include <bits/stdc++.h>
using namespace std;
long long C, T, n, d, a[2000006];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			//cout << a[i];
		}
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		if (d <= abs(a[1] - a[2])) {
			cout << "0\n";
			continue;
		}
		cout << max((long long)0, n - 2 * d / abs(a[1] - a[2]) + 1 ) << "\n";
	}
	return 0;
}
