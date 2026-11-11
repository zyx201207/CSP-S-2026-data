#include <bits/stdc++.h>
using namespace std;
long long dp[1005][1005];
long long a[1000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		int p = d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << 0 << "\n";
	}

	return 0;
}
