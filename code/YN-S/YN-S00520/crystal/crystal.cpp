#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (n == 1) {
		cout << 1;
		return 0;
	}
	int ans = 1;
	int k = 0;
	for (int i = 1; i < n && k <= m; i++) {
		k += i * abs(a[i] - a[i - 1]);
		if (m - k >= 0) {
			ans = i + 1;
		}
	}
	cout << ans;
}