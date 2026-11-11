#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n+1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a.begin() + 1, a.end());
	int s = 0, ans = 0;
	for (int i = 1, j = 0; i <= n; ++i) {
		s += a[i];
		while ((i-j+1) * a[i] - s > m) s -= a[j++];
		ans = max(ans, i-j+1);
	}
	cout << ans << endl;
	return 0;
}
