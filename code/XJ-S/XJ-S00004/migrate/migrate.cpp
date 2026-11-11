#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2000005;
int c, t, n, d, x[MAXN];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		if (n < 4) {
			cout << 0 << '\n';
			continue;
		}//?pts
		else if (c == 11 || c == 12) {
			int val = x[2] - x[1];
			if (val > d) {
				cout << 0 << '\n';
				continue; 
			}
			else {
				int val2 = n - 3, ans = 0;
				continue;
			}
		}//10pts
		else {
			int dis[n + 5][n + 5], cnt1, cnt2, vis[n + 5];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) dis[i][j] = abs(x[i] - x[j]);
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= n; k++) {
						if (dis[i][k] <= d && dis[k][j] <= d && vis[i] && vis[j] && vis[k] && i != j && i != k && j != k) cnt1++;
						vis[i] = 1;
						vis[j] = 1;
						vis[k] = 1;
					}
					if (cnt1 == 2) cnt2++;
					cnt1 = 0;
				}
			}
			cout << cnt2 << '\n';
		}//10pts
	}
	return 0;
}//树状数组统计
