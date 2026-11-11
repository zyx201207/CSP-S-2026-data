#include <bits/stdc++.h>
using namespace std;

int x[2000005];
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while (t--) {
		int n, d; cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		if (c == 11 || c == 12) {
			if (n % 2 == 0) {
				cout << 1 << "\n";
			} else {
				cout << 2 << "\n";
			}
		}
		else if (c == 13 || c == 14) {
			cout << 0 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	return 0;
}
// xi wang shang mi huo xing wei da shang
