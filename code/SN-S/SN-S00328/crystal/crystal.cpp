#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	i64 m;
	cin >> n >> m;
	vector<i64> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	i64 sum = 0;
	int ans = 1;
	for (int l = 0, i = 1; i < n; ++i) {
		if (l <= i - 1) sum += 1ll * (i - l) * (a[i] - a[i - 1]);
		while (sum > m) {
			sum -= a[i] - a[l];
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
