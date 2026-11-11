#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], sum[500005], ans = 1, n, m;

bool check(int l, int r) {
	return (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = a[i] + sum[i - 1];
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i, res = -1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid, i))
				res = mid, r = mid - 1;
			else
				l = mid + 1;
		}
//		cout << res << " " << i << '\n';
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}
//315275