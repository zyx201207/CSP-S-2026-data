#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t, n, d;
	cin >> c >> t ;
	for (int j = 1; j <= t; j++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		int ans = 0;
		for (int i = 1; i <= n - 3; i++) {
			if (x[i + 2] - x[i] <= d && x[i + 3] - x[i + 1] <= d)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}