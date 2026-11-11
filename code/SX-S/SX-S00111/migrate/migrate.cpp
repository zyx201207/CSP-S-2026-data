#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
typedef long long ll;
ll c, t, cz;
ll n, d, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cz = a[n] - a[n - 1];
		cout << 2 * ( floor(d * 1.0 / cz) + 1) << "\n";
	}
	return 0;
}
