#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
long long n, m, c, ans;
long long a[N];
bool flag = 1;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> a[1];
	if (n == 1) {
		cout << 1;
		return 0;
	}
	cin >> a[2];
	c = a[2] - a[1];
	for (int i = 3; i <= n; ++i) {
		cin >> a[i];
		if (a[i] - a[i - 1] != c) {
			flag = 0;
		}
	}
	if (flag) {
		bool f = 1;
		long long ans;
		for (int i = 2; i <= n; ++i) {
			if (m >= c * (i - 1)) {
				m = m - c * (i - 1);
			} else {
				f = 0;
				ans = i - 1;
				break;
			}
		}
		if (!f) {
			cout << ans;
		} else {
			cout << n;
		}
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int len = 1; len <= n; ++len) {
		flag = 0;
		for (int i = 1; i <= n - len; ++i) {
			int j = i + len - 1;
			long long l = m;
			for (int k = i; k < j; ++k) {
				l = l - (a[j] - a[k]);
			}
			if (l >= 0) {
				ans = len;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	cout << ans;
	return 0;
}
