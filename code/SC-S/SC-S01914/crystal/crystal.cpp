#include <bits/stdc++.h>
#define nmf(i, s, e) for (int i = s; i <= e; i++)
#define ref(i, s, e) for (int i = s; i >= e; i--)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
LL n, m;
LL a[500005], sum[500005];
void solve() {
	cin >> n >> m;
	nmf(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	nmf(i, 1, n) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	nmf(i, 1, n) {
		int l = 1, r = i - 1;
		int res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (sum[i] - sum[mid - 1] + m >= a[i] * (i - mid + 1)) {
				r = mid - 1;
				res = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << endl;

}
signed main() {
#ifndef LOCAL
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--)
		solve();
	cerr << "Time Used : " << clock() * (1000.0 / CLOCKS_PER_SEC) << " ms." << endl;
}