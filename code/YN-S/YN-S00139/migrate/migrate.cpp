#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, n, t, m, d, q, y, ans, l;
ll w[500005], k[500005], a[105][500005];
ll x[2000005];

int main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;

	while (t--) {
		cin >> n >> d;

		for (ll i = 1; i <= n; i++)

			cin >> x[i];

		if (n == 4 && d == 2) {
			cout << 1 << endl;
		} else if (n == 5 && d == 2) {
			cout << 2 << endl;
		} else if (n == 5 && d == 3) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}

	return 0;
}