#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5+10;
ll n, m, a[N], s[N];

bool cmp(ll x, ll y) {
	return x < y;
}

bool check(ll x, ll y) {
	ll len = x - y + 1;
	return a[x] * len - s[x] + s[y - 1] <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (ll i = 1; i <= n; i++) {
		s[i] = a[i] + s[i - 1];
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll l = 1, r = i;
		while (l <= r) {
			ll mid = (l + r) / 2;
			if (check(i, mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}
