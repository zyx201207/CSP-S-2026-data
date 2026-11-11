#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	ll l = 0, r = 0;
	ll x = 0;
	while (x <= m) {
		if (r == n - 1)return cout << n, 0;
		ll y = a[r + 1] - a[r];
		ll z = r - l + 1;
		x += y*z;
		if (x > m) {
			x -= y * z;
			break;
		}
		r++;
	}
	ans = r - l + 1;
	r += 1;
	for (; r < n; r++) {
		ll y = r - l + 1;
		ll z = a[r] - a[r - 1];
		x += y*z;
		if (x > m)
			while (x > m) {
				x -= a[r] - a[l];
				l++;
			}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}