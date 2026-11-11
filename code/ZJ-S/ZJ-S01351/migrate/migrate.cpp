#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[5020], f[5020][5020];
vector<int> v[5020];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t --) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i];
		}
		if (n <= 2) {
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		for (int l = 1; l <= n; ++ l) {
			for (int i = 1; i + l <= n; ++ i) {
				int j = i + l;
				if (a[j] - a[i] <= m) {
					f[i][j] = 1;
				} else {
					int minn = 1e18, leu = 0;
					for (int k = i + 1; k < j; ++ k) {
						if (f[i][k] + f[k][j] < minn) {
							minn = f[i][k] + f[k][j];
							leu = 1;
						} else if (f[i][k] + f[k][j] == minn) {
							leu ++;
						}
					}
					if (leu == 2 && minn != l) {
						ans ++;
					}
					f[i][j] = minn;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}