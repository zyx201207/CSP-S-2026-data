#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n, m, a[N], d[N], s[N], ans = 0;

bool check(ll x, ll y) {
	ll t = s[x] - s[y] - (y - x) * d[y];
	return (t <= m);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++) {
		d[i] = a[n] - a[i];
	}
	s[n] = d[n];
	for(ll i = n - 1; i >= 1; i--) {
		s[i] = s[i + 1] + d[i];
	}
//	for(int i = 1; i <= n; i++) {
//		cout << d[i] << " ";
//	}
//	cout << endl;
//	for(int i = 1; i <= n; i++) {
//		cout << s[i] << " ";
//	}
//	cout << endl;
	for(ll i = 1; i <= n; i++) {
		ll l = 1, r = i;
		while(l <= r) {
			ll mid = (l + r) / 2;
			if(check(i - mid + 1, i)) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		ans = max(ans, r);
	}
	cout << ans;
	return 0;
}
