#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n, m, a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = 1;
	int u = 0;
	int ans = 0;
	while (l <= r && r <= n) {
		if (u <= m) {
//			cerr << l << " " << r << "\n";
			ans = max(ans, r - l + 1);
			r ++;
			u = u + (r - l) * (a[r] - a[r - 1]);
		} else {
			u = u - (a[r] - a[l]);
			l ++;
		}
	}
	cout << ans;
	return 0;
}
