#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m, d;
int a[N];
int b[N];
bool f = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2)
			d = a[2] - a[1];
		if (i > 3) {
			if (a[i] - a[i - 1] != d)
				f = 0;
		}
	}
	if (!f) {
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for (int i = n; i >= 1; i--) {
			int j = i - 1;
			int sum = 0, cnt = 1;
			while (j >= 1) {
				if (sum + a[i] - a[j] <= m) {
					sum += a[i] - a[j];
					cnt++;
					j--;
				} else
					break;
			}
			ans = max(ans, cnt);
		}
		cout << ans;
		return 0;
	} else {
		double delta = (double)(sqrt(d *d + 8.0 * d *m));
		int res = (int)((d + delta) / (2.0 * d));
		cout << res;
		return 0;
	}
	return 0;
}
