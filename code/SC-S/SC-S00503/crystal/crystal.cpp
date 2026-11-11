#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> a(n + 1), sum(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; i++)
		sum[i] = a[i] + sum[i - 1];
	auto check = [&](int len) {
		ll d = LLONG_MAX;
		for (int i = len; i <= n; i++) {
			ll s = sum[i] - sum[i - len];
			d = min(d, a[i] * len - s);
		}
		return d <= m;
	};
	int low = 2, high = n, ans = 0;
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (check(mid))
			low = mid + 1, ans = mid;
		else
			high = mid - 1;
	}
	cout << ans  << '\n';
	return 0;
}