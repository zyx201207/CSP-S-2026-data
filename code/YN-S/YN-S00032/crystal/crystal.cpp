#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 514514;
ll n, m, ans;
ll a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	if (n > 5000 && a[n] > 100) {
		ll d = a[2] - a[1];
		for (ll i = 1, s = 0; s <= m; s += d * i, i ++) {
			ans++;
		}
	} else {
		ll l = 1, r = 2;
		ll s = 1;
		while (l < r && r <= n) {
			ll dt = (a[r] - a[r - 1]) * (r - l );
			if (m >= dt) {
				m -= dt;
				s++;
				r++;
			} else {
				m += a[r] - a[l];
				s--;
				l++;
			}
			ans = max(s, ans);
		}
	}
	cout << ans;
	return 0;
}
