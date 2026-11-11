#include <bits/stdc++.h>//Plaese fly !
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c, n, m, q, a[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> q;
	while (q--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		if (a[2] - a[1] == 0) {
			cout << "0\n";
			continue;
		}
//		cout << n << " " << m << " " << a[2] - a[1] << "\n";
		int hh = m * 2 / (a[2] - a[1]) - 1;
		if (n - hh < 0 || m <= (a[2] - a[1])) {
			cout << 0 << "\n";
		} else {
			cout << n - hh << "\n";
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/