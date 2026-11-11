#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], sum[N];

int check(int x) {
	int ans = 1e18;
	for (int i = x; i <= n; i++)
		ans = min(ans, x * a[i] - sum[i] + sum[i - x]);
	return ans <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}