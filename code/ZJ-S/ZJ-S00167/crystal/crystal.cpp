#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], b[200005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
	int ans = 0, l = 1, r = n;
	while (l <= r) {
		int mid = l + r >> 1, f = 0;
		for (int i = 1; i <= n - mid + 1; i++) {
			if (a[i + mid - 1] * mid - b[i + mid - 1] + b[i - 1] <= m) {
				f = 1;
				break;
			}
		}
		if (f) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}