#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 10;
ll c, t;
ll n, m;
ll a[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll d = a[2] - a[1];
	ll x = m / d;
	if (x <= 1) {
		cout << 0 << endl;
		return ;
	}
	ll ans = 0, cnt = 1;
	for (int i = x + 1; i <= n; i++) {
		ans += cnt;
		cnt++;
		if (cnt > x)
			cnt = x;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	while (t--)
		solve();



	return 0;
}