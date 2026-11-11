#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N];

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		memset(a, 0, sizeof(a));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int d1 = a[2] - a[1];
		if (d >= 2 * d1 && d < 3 * d1)
			cout << d1 *n / d << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}