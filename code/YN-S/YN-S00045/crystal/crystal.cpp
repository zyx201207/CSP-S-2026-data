#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll maxn = 2e6 + 5;
const ll INF = 1e18;

ll n, m;
ll a[maxn];
ll pre[maxn];

ll check(ll l, ll r) {
	ll len = r - l + 1;
	ll sum = pre[r] - pre[l - 1];
	ll nd = a[r] * len - sum;
	return nd <= m;
}

void solve() {

	cin >> n >> m;
	map<ll, ll> mp, cnt;

	for (ll i = 1; i <= n; i++)

		cin >> a[i];
	sort(a + 1, a + 1 + n);

	for (ll i = 1; i <= n; i++)

		pre[i] = pre[i - 1] + a[i], cnt[a[i]]++;//cout << a[i] << " ";
	ll ans = 0;

	for (ll i = 1; i <= n; i++) {

		ll l = 1, r = i;

		while (l + 1 < r) {
			ll mid = (l + r) / 2;

			if (check(mid, i))
				r = mid;
			else
				l = mid;
		}

		if (check(l, i))
			ans = max(ans, i - l + 1);
		else if (check(r, i - 1))
			ans = max(ans, i - r + 1);
	}

	cout << ans << "\n";
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T = 1;

//	cin>>T;
	while (T--)
		solve();
}
