#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
ll id, t, a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> id >> t;
	while (t--) {
		ll n, m, flag = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 3; i <= n; i++) {
			if (a[i] - a[i - 1] != a[2] - a[1]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			if (a[n] - a[1] < 2 * m - 1)
				cout << 0 << '\n';
			if (a[n] - a[1] == 2 * m - 1)
				cout << 1 << '\n';
			if (a[n] - a[1] > 2 * m - 1)
				cout << 2 << '\n';
		} else if (n <= 200) {
			ll ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					ll cnt = 0;
					for (int k = i + 1; k <= j - 1; k++) {
						if (a[k] - a[i] <= m && a[j] - a[k] <= m)
							cnt++;
					}
					if (cnt == 2)
						ans++;
				}
			}
			cout << ans << '\n';
		} else
			cout << 0 << '\n';
	}
	return 0;
}