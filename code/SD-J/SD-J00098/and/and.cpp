#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005], ans = 0;
int pc[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int k = 2147483647, mx = 0;
	int b = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		k &= a[i];
		mx = max(mx, a[i]);
		if (a[i] != i - 1) b = 0;
	}
	if (m == n) {
		cout << k;
		return 0;
	}
	if (m == 1) {
		cout << mx;
		return 0;
	}
	if (m == 2 && n <= 10000) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j != i) {
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
		cout << ans;
		return 0;
	}
	if (n <= 27) {

		for (int msk = 0; msk < 1 << n; msk++) {
			int res = 2147483647, cnt = 0;
			for (int i = 0; i < n; i++) {
				if ((msk >> i) & 1) {
					res &= a[i + 1];
					cnt++;
					//cout << 1;
				} else {
					//cout << 0;
				}
			}
			//cout << endl;
			if (cnt == m) {
				ans = max(ans, res);
				//cout << res << endl;
			}
		}
		cout << ans;
		return 0;
	}
	if (b) {
		sort(a + 1, a + n + 1, [](int x, int y) {
			int pcx = __builtin_popcount(x); int pcy = __builtin_popcount(y);
			return pcx == pcy? x >y : pcx > pcy;
		});
		int res = 2147483647;
		for (int i = 1; i <= m; i++) {
			res &= a[i];
		}
		cout << res;
		return 0;
	}
	sort(a + 1, a + n + 1, greater<int>());
	int res = 2147483647;
	for (int i = 1; i <= m; i++) {
		res &= a[i];
	}
	cout << res;
	return 0;
}
