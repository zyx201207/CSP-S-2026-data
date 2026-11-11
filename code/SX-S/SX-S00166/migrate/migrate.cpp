#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6+10;
ll c, t, n, d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (ll i = 1; i <= n; i++)
			cin >> x[i];
		ll c = x[2] - x[1];
		ll j = (d / c - 1) * 2;
		ll ans = n - j - 1;
		cout << ans << endl;
	}
	return 0;
}
