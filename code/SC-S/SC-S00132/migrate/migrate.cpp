#include"bits/stdc++.h"
#define int long long
using namespace std;
const int N = 2e6 + 5, inf = 5e18;
int c, t, n, d;
int x[N], pre[N], suf[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	x[0] = -inf;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (c == 11 || c == 12) {
			int di = x[2] - x[1];
			if (di >= d) {
				cout << "0\n";
				continue;
			}
			int len = d / di * 2;
			cout << max(n - len + 1, 0ll) << '\n';
			continue;
		}
		x[n + 1] = inf;
		for (int i = 1; i < n; i++)
			pre[i] = (x[i + 1] - x[i] <= d && x[i + 2] - x[i + 1] <= d && x[i + 2] - x[i] > d ? pre[i - 1] + 1 : 0);
		suf[n + 1] = 0;
		for (int i = n; i > 1; i--)
			suf[i] = (x[i] - x[i - 1] <= d && x[i - 1] - x[i - 2] <= d && x[i] - x[i - 2] > d ? suf[i + 1] + 1 : 0);
		int ans = 0;
		for (int i = 1; i + 3 <= n; i++) {
//			if (x[n] - x[i] <= d)
//				break;
			int mid = upper_bound(x + i, x + 1 + n, x[i] + d) - x - 2;
//			if (x[n] - x[mid] <= d)
//				break;
			int r = upper_bound(x + mid, x + 1 + n, x[mid] + d + 1) - x - 1;
			int rr = lower_bound(x + mid, x + 1 + n, x[mid - 1] + d + 1) - x;
			if (x[r] - x[mid] > d)
				r--;
			if (x[r] - x[mid - 1] <= d || rr - i < 3)
				continue;
//			cout << i << ' ' << mid << ' ' << rr << ' ' << r << ',';
			ans += pre[i - 1] + suf[r + 1] + (r - rr + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}