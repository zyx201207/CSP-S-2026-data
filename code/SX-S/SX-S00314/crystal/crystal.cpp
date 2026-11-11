#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, m;
ll a[500010];
ll sum[500010];
ll ans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (ll i = 1; i <= n; i++) {
		ll l = 1, r = i;
		while (l < r) {
			ll mid = (l + r + 1) / 2;
			if (a[i] * mid - sum[i] + sum[i - mid] <= m)
				l = mid;
			else
				r = mid - 1;
		}
		ans = max(ans, l);
	}
	cout << ans;
	return 0;
}