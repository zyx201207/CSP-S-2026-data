#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t;
signed main() {
	freopen("migrate.in" , "r", stdin );
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int n, x[2000200];
		cin >> n;
		bool wj = true;
		bool dc = true;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			if (x[i] - x[i - 1] <= d) wj = false;
			if (x[i] - x[i - 1] != x[1] - x[0]) dc = false;
		}
		if (wj == true) {
			cout << 0;
			continue;
		}
		cout << 1;
	}
	return 0;
} 
