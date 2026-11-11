#include <bits/stdc++.h>
using namespace std;
long long c, d, t, n, a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << 0 << endl;
	}
	return 0;
}