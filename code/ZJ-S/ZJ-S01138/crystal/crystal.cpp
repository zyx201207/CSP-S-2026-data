#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], sum[N];
int ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = 1;
	while (r <= n) {
		int s = sum[r] - sum[l - 1];
		int mx = a[r] * (r - l + 1);
		if (mx - s <= m) {
			ans = max(ans, r - l + 1);
			r++;
		} else {
			l++;
		}
	}
	cout << ans << endl;
	return 0;
}