#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int a[N], f[N], g[N];
int d[N];
bool flag[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T; cin >> c >> T;
	while (T --) {
		int n, t; cin >> n >> t;
		for (int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		int u = 1;
		for (int i = 1 ; i <= n ; i ++) {
			while (u <= n && a[u] - a[i] <= t) u ++;
			f[i] = u - 1;
			g[i] = 1;
		}
		int res = 0;
		for (int i = 1 ; i <= n ; i ++) {
			// fr i;
			fill(d + i, d + n + 1, 0);
			fill(g + i, g + n + 1, 0);
			g[i] = 1;
			for (int j = i ; j <= n ; j ++) {
				for (int k = j + 1 ; k <= f[j] ; k ++) {
					if (d[k] == d[j] + 1) 
						g[k] += g[j];
					if (d[k] == 0) {
						d[k] = d[j] + 1;
						g[k] += g[j];
					}
				}
			}
			for (int j = i + 1 ; j <= n ; j ++)
				if (g[j] == 2) 
					res ++;
//					cout << i << ' ' << j << '\n';
		}
		cout << res << '\n';
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17 


*/
