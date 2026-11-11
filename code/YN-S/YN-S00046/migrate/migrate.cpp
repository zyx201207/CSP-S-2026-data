#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll C, T;
ll x[2000001];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> C >> T;
	while (T--) {
		ll n, d;
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (d == 1 || n <= 3) {
			cout << 0 << "\n";
			continue;
		}
		ll D = x[2] - x[1]; //公差
		int cnt = 0;
		for (ll i = 4; i <= n; i++) {
			//模拟从1到i
			int change = -1;
			int last = -1;
			for (ll j = 1; j <= i; j++) {
				ll k;
				if (j != i && x[j + 1] - x[j] > d) {
					change = 0;
					break;
				}
				for (k = d; k > 0; k--) {
					if (j + k <= i && (x[j + k] + x[1]) % D == 0) {
						break;
					}
				}
				if (last != -1) {
					change += (last != k);
				}
				last = k;
			}
			if (change == 1) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}