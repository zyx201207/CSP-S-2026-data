#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T, n, d;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int l = a[2] - a[1];
		if (d < (2 * l)) {
			cout << 0 << '\n';
			continue;
		}
		int t = l / d;
		int ans = 0;
		for (int i = 1; i <= n - 3; i++) {
			ans += (n - i - 1) / t;
		}
		cout << ans;
	}
	return 0;
}