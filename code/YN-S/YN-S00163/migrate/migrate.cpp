#include <bits/stdc++.h>
using namespace std;
int c, n, t, d;
int x[510000], ge[510000], de, p;
long long qian[510000], ans;
bool f1, f2;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			if (i > 1) {
				ge[i - 1] = x[i] - x[i - 1];
				if (i == 2) {
					de = ge[i - 1];
				} else if (de != ge[i - 1]) {
					f1 = 1;
				}
				qian[i - 1] = qian[i - 2] + ge[i - 1];
			}
		}
		for (int i = 1; i <= n - 1; i++) {
			if (qian[i] <= d && qian[n - 1] - qian[i] <= d) {
				f2 == 1;
				p = i + 1;
				break;
			}
		}
		if (f1 == 0) {
			int cnt = 1;
			while (de * (cnt + 1) <= d && de * (2 * cnt + 1) <= n - 1) {
				ans += n - 2 * cnt - 1;
				cnt++;
			}
			cout << ans << endl;
		} else if (f2 == 1) {
			if (qian[n - 1] <= d)
				cout << 0 << endl;
			else {
				for (int i = 1; i <= n / 2; i++) {
					if (p + i - 1 > n - 1)
						break;
					if (p - i - 1 < 1)
						break;
					if (qian[p - 1] - qian[p - i - 1] <= d && qian[p + i] - qian[p - 1] <= d && p + i < n - 1)
						ans++;
					if (qian[p - 1] - qian[p - i - 2] <= d && qian[p + i - 1] - qian[p - 1] <= d && p - i - 2 > 1)
						ans++;
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}