#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c, t, n;
long long d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		long long D = x[2] - x[1];
		int k = d / D;
		if (k <= 1) {
			cout << 0 << '\n';
		} else
			cout << n - 2 * k + 1 << '\n';
	}
	return 0;
}
