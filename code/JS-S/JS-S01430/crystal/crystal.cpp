#include <bits/stdc++.h>
using namespace std;
using uns = unsigned;
using ll = long long;
#define S 500005
ll a[S], q[S];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	uns n, ans = 1; ll m;
	cin >> n >> m;
	for (uns i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1); q[1] = a[1];
	for (uns i = 2; i <= n; ++i) {
		q[i] = q[i - 1] + a[i];
		uns l = 1, r = i, mid;
		while (l < r) {
			mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (q[i] - q[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	
	return 0;
}
