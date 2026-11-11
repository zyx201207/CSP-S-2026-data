// Fairly easy.
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = 1, ans = 1, cost = 0;
	while(r < n) {
		while(r < n && cost + (r - l + 1) * (a[r + 1] - a[r]) <= m) {
			cost += (r - l + 1) * (a[r + 1] - a[r]);
			++r;
		}
		ans = max(ans, r - l + 1);
		cost -= a[r] - a[l];
		++l;
	}
	cout << ans;
	return 0;
}