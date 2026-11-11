#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, t;
	cin >> c >> t;
	while (t--) {
		ll n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c == 11 || c == 12) {
			int len = d / (a[2] - a[1]) * 2;
			if (len >= 4) {
				cout << max(0LL, n - len + 1) << "\n";
			} else {
				cout << "0\n";
			}
		}
	}
	return 0;
}
