#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6;
long long x[MAXN + 5];

signed main() {
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t, n, d;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		long long cnt = 1, sum = 0, cz;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		cz = x[2] - x[1];
		bool flag = 0;
		for (int i = 3; i <= n; i++) {
			if (x[i] == 0)
				x[i] = x[i - 1] + cz;
			if (x[i] - x[i - 1] != cz) {
				cout << "0" << endl;
				flag = 1;
				break;
			}
		}
		if (flag)
			continue;
		if (cz > d) {
			cout << "0" << endl;
			continue;
		}
		for (int i = 2; i <= n; i++) {
			sum += x[i] - x[i - 1];
			if (sum >= d) {
				cnt = i - (sum > d) - 1;
//				cout << cnt << endl;
				if (2 * cnt - 1 <= n && cnt != 1)
					cout << n - 2 * cnt + 1 << endl;
				else
					cout << "0" << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "0" << endl;
	}
	return 0;
}
