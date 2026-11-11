#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[500005], dlt[500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	bool A = true;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1)
			dlt[i] = a[i] - a[i - 1];
		if (i > 2) {
			if (dlt[i] != dlt[i - 1])
				A = false;
		}
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (A) {
		ll d = a[2] - a[1];
		ll cnt = 0;
		for (ll i = 1; i <= n; i++) {
			cnt += i;
			if (cnt * d == m) {
				cout << i + 1;
				return 0;
			}
			if (cnt * d > m) {
				cout << i;
				return 0;
			}
		}
	}
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (ll i = n; i >= 1; i--) {
		ll x = 0;
		ll cnt = 1;
		for (ll j = i - 1; j >= 1; j--) {
			if (x + a[i] - a[j] <= m) {
				x += a[i] - a[j];
				cnt++;
			}
			if (x >= m)
				break;
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	/*
	1 2 4 8 9
	+1 +3 +7 +8
	   +2 +6 +7
	      +4 +5
	         +1
	1 1 4 8 9
	+0 +3 +7 +8
	   +3 +7 +8
	      +4 +5
	         +1
	1 10001 10002 10003
	+10000 +10001 +10002
	       +1     +2
	              +1
	5 8
	-3 -1 2 2 7
	*/
	return 0;
}