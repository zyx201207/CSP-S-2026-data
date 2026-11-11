#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int x[2000005];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		if (c == 11 || c == 12) {
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> x[i];
			int b = x[2] - x[1];
			int k = d / b;
			cout << n - k - 1 << "\n";
		} 
	}
	return 0;
}