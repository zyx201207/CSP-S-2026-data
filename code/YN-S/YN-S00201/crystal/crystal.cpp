#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define int long long
int n, m, a[N], res, b[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		int ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if ((a[i] * mid) - (b[i] - b[i - mid]) <= m) {
				l = mid + 1;
				ans = mid;
			} else {
				r = mid - 1;
			}
		}
		res = max(res, ans);
	}
	cout << res;
	return 0;
}
