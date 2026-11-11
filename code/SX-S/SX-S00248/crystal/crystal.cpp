/*
  Broken sun,
  Shedding light on every one.
  Broken sun,
  You are not the only one.
  They can't take out my spark,
  I won't let you go.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
typedef long long ll;
ll a[N], pre[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = a[i] - a[1] + pre[i - 1];
	}

	ll ans = 0;
	for (ll t = 1; t <= n; t ++) {
		ll l = 1, r = t;
		while (l < r) {
			ll mid = (l + r) >> 1;
			if (pre[mid] - (mid - 1) * (a[t] - a[1]) > m + pre[t] - t * (a[t] - a[1])) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		ans = max(ans, t - l + 1);
	}
	cerr << ans;
	cout << ans;
	return 0;
}
