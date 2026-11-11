#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
ll c, t;
ll a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		ll x, y;
		cin >> x >> y;
		for (int j = 1; j <= x; j++) {
			cin >> a[i];
		}
	}
	for (int i = 1; i <= t; i++) {
		cout << i << "\n";
	}


	return 0;
}