#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m, a[500005], sum[500005], ans = 1;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if ((i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m) {
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			} else l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}