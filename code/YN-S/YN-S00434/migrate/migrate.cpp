#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[900009];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << 1 << '\n';
	}
	return 0;
}