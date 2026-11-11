#include <bits/stdc++.h>
using namespace std;
long long bh, t, n, m;
const int N = 2e6+10;
int x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> bh >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
		}
		if (m <= 3 * (x[2] - x[1])) {
			cout << n - 3 << endl;
		} else {
			cout << 0;
		}
	}
	return 0;
}