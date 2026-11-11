#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t;
ll n, d, ans;

bool w(ll a, ll b) {
	if (a >= b || a < 2 * b) {
		return true;
	} else
		return false;
}

ll qwq(ll aa, ll cc) {
	if (w(aa, cc)) {
		ans = (aa % cc) * cc;
		return ans;
	} else {
		ans = 0;
		return ans;
	}
}

int main() {
	ll x[n];
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t > 0) {
		t--;
		cin >> n >> d;
		for (ll i = 0; i < n; i++) {
			cin >> x[i];
		}
		ll daoju = x[n - 1] - x[0];
		ans = qwq(daoju, d);
	}
	cout << ans;
	return 0;
}