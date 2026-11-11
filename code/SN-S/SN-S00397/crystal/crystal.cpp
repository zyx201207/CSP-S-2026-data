#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

const ll maxn = 5e5 + 5;
ll n , m;
ll a[maxn];
bool mark = true;
ll s;
ll gs = 0;

ll cheak (ll x) {
	ll d = upper_bound(a + 1 , a + n + 1 , x) - a;
	ll cnt = 0;
	for (ll i = d - 1; i >= 1; i--) {
		if ((cnt + (x - a[i])) > m) break;
		cnt += (x - a[i]);
		gs++;
	}
	ll ls = gs;
	gs = 0;
	return ls;
}

int main () {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> a[1] >> a[2];
	s = a[1];
	d = a[2] - a[1];
	ll amx = -inf , amn = inf;
	for (ll i = 3; i <= n; i++) {
		cin >> a[i];
		if ((s + d * (i - 1)) != a[i]) mark = false;
		amx = max(amx , a[i]);
		amn = min(amn , a[i]);
	}
	sort(a + 1 , a + n + 1);
	if (mark) {
		ll c = m / (d);
		cout << c + 1 << "\n";
		return 0;
	}
	ll l = amn , r = amx;
	ll ans = -inf;
//	cout << "Debug: 1 " << "\n";
//	ll tot = 10;
//	while (l <= r) {
//		ll mid = (l + r) / 2;
//		cout << "Debug: " << mid << "\n";
//		if (cheak(mid) >= ans) {
//			ans = cheak(mid);
//			l = mid + 1;
//		} else {
//			r = mid - 1;
//		}
//	}
//	cout << ans << "\n";
	for (ll i = 1; i <= n; i++) {
		ans = max(ans , cheak(a[i]));
	}
	cout << ans << "\n";
	return 0;
}
