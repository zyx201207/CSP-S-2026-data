#include <bits/stdc++.h>
using namespace std;
int c, t, n, ans, dis;
long long d, a[2000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i], dis = a[i] - a[i - 1];
		if (d < 2 * dis || n == 1) {
			cout << "0\n";
			continue;
		}
		int x = d / dis;
		cout << max(n - 2 * x + 1, 0) << '\n';
	}
	return 0;
}