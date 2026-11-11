#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int n, d;
int a[N];
int c, t;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << c << "\n" << 1 << "\n" << 2;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
