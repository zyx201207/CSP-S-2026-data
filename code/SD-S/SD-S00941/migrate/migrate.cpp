#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int c, t, n, d, x[N], f[N][N], cnt[N][N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> c >> t;
	while (t--) {
		memset(f, 0, sizeof(f));
		memset(cnt, 0, sizeof(cnt));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				int minn = 1e18;
				if (x[i] - x[j] <= d) {
					minn = 1;
					f[j][i]++;
					cnt[j][i] = 1;
				}
				for (int k = j; k < i; k++) {
					if (x[i] - x[k] <= d && cnt[j][k] + 1 < minn) {
						f[j][i] = f[j][k];
						cnt[j][i] = cnt[j][k] + 1;
						minn = cnt[j][k] + 1;
					} else if (x[i] - x[k] <= d && cnt[j][k] + 1 == minn) {
						f[j][i] += f[j][k];
					}
				} 
			} 
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
//				cout << f[i][j] << ' ';
				if (f[i][j] == 2) ans++;
			}
//			cout << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
