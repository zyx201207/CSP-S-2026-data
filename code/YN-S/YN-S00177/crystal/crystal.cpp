#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, ans;
int a[N];
int sum[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			int len = i - mid + 1;
			int p = len * a[i];
			int q = sum[i] - sum[mid - 1];
			if (p - q <= m) {
				ans = max(ans, len);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}
	cout << ans;
	return 0;
}
