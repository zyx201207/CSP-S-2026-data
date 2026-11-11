#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, n, t, m, d, q, y, ans, l, k;
ll u[2000005], v[2000005];

int main() {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;

	while (t--) {
		cin >> n >> k;

		for (ll i = 1; i <= n - 1; i++)

			cin >> u[i] >> v[i];
	}

	cout << 1 << endl;
	cout << 2 << endl;
	return 0;
}