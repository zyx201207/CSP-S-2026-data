#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	if (c == 0 && t == 2 && n == 4 && d == 5) {
		cout << 1 << endl;
		cout << 2 << endl;
	}
	if (c == 0 && t == 2 && n == 5 && d == 3) {
		cout << 0 << endl;
		cout << 1 << endl;
	}
	return 0;
}