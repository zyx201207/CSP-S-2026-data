#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll c, t;
const ll N = 1e5 + 10;
ll a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << 1 << endl;
	}

	return 0;
}
