#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
ll int a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		ll int n, d, cnt = 0;
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		ll int x = a[2] - a[1];
		ll int dd = a[n] - a[1];
		ll int dch = (dd) / d;
		if (dd % d == 0) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = d - 1; i > 1; i--) {
			if (dd / i == dch) {
				cout << 0 << '\n';
				continue;
			}
		}
		cout << '1';
	}
	return 0;
}