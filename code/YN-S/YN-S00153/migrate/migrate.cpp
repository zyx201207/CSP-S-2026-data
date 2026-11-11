#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
const int NN = 1e4 + 10;
int c, t, n, d, a[N];
bool f[NN][NN];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (!f[i][j] && a[i] - a[1] <= d && a[i] + a[1] == a[j]) {
					ans++;
					f[i][j] = true;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
