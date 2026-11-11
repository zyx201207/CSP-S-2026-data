#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end(), less<int>());
	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	auto cost = [&](int l, int r) -> int {
		int L = r - l + 1;
		return L * a[r] - (pre[r] - pre[l - 1]);
	};
	int ans = 0;
	for(int r = 1, l = 1; r <= n; r++) {
		while(cost(l, r) > m) l++;
		ans = max(ans, r - l + 1);
	} cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}