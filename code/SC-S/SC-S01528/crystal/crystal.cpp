#include<bits/stdc++.h>
#define int long long
using namespace std;
#define N 500005
int n, m, ans, a[N], s[N];
signed main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> m, ans = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 2; i <= n; i++) {
		int p = 0;
		for (int l = 1, r = i - 1; l <= r;) {
			int mid = l + r >> 1;
			if (s[i - 1] - s[mid - 1] + m < (i - mid) * a[i]) l = mid + 1;
			else r = mid - 1, p = mid;
		}
		ans = max (ans, i - p + 1);
	}
	cout << ans << '\n';
	return 0;
}