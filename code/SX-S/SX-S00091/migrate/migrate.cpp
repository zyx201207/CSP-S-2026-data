//3.migrate
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, ans = 0;
		cin >> n >> d;
		vector<int> x(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i <= n; i++) {
			if (x[i + 4] - x[i] == 2 * d)
				ans++;
		}
		cout << ans << endl;
		cout << ans + 1 << endl;
	}
	return 0;
}
