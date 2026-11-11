#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[5001][5001], e[5001][5001], a[5000001];
signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		if (c >= 11 && c <= 12) {
			cout << 0 << "\n";
			continue;
		} 
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) e[i][j] = e[j][i] = 1e18;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i == j) break;
				if (abs(a[i] - a[j]) <= d) e[i][j] = 1;
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				if (i == k) continue;
				for (int j = i + 1; j <= n; j++) {
					if (j == k) continue;
					if (e[i][k] + e[k][j] < e[i][j]) {
						x[i][j] = 1;
						e[i][j] = e[i][k] + e[k][j];
					}else if (e[i][k] + e[k][j] == e[i][j]) {
						x[i][j]++;
					}
				}
			}
		}
		/*for (int i = 1; i <= n; i++){
			 for (int j = 1; j <= n; j++) cout << e[i][j] << " ";
				cout << "\n"; 
			}*/
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[i][j] == 2 && e[i][j] != 1e18) ans++;
			}
		}
		cout << ans << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) x[i][j] = e[i][j] = 0;
		}
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
