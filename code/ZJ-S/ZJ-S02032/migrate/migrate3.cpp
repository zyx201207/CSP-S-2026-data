#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e6 + 5;
int a[N], v[N], v2[N], f[N], g[N], k[N];
int bl[N], pl[N], pr[N], tot;
int bl2[N], pl2[N], pr2[N], tot2;
signed main() {
	freopen("migrate3.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T; cin >> c >> T;
	while (T --) {
		int n, d; cin >> n >> d;
		for (int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		int u = 1, xx = n + 1;
		for (int i = 1 ; i <= n ; i ++) {
			while (u <= n && a[u] - a[i] <= d) u ++;
			v[i] = u - 1;
			if (v[i] == i) v[i] = xx ++;
		}
//		for (int i = 1 ; i <= n ; i ++)
//			cout << v[i] << ' ';
//		cout << '\n';
//		v[n] = n + 1;
		for (int i = 1 ; i <= n ; i ++) {
			if (v[i] != v[i - 1]) tot ++;
			bl[i] = tot;
			if (!pl[tot]) pl[tot] = i;
			pr[tot] = i;
		}
		for (int i = 1 ; i <= n ; i ++) {
//			v[i]
			f[i] ++, g[i] ++;
			if (v[i] != pl[bl[v[i]]]) g[v[i]] += f[i];
			else {
				g[v[i]] += f[i];
				f[v[i]] += f[i];
			}
		}
//		for (int i = 1 ; i <= n ; i ++)
//			cout << g[i] << ' ';
//		cout << '\n';
		int res = 0;
		// k
		for (int i = 1 ; i <= n ; i ++) {
			int u = i;
			while (u <= n) {
				if (pl[bl[u]] != u) break;
				k[i] ++;
				if (v[u] == u) break;
				u = v[u];
			}
		}
//		for (int i = 1 ; i <= n ; i ++)
//			cout << k[i] << ' ';
//		cout << '\n';
		for (int i = 1 ; i <= n ; i ++) {
			if (v[i] == pl[bl[v[i]]] + 1) {
//				v[v[i]]
//				cout << i << ' ' << v[v[i]] << '\n';
				res += g[i] * k[v[v[i]]];
			}
		}

//		cout << '\n';
		cout << res << '\n';
		fill(f + 1, f + n + 1, 0);
		fill(g + 1, g + n + 1, 0);
		fill(k + 1, k + n + 1, 0);
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17 


1 8
1 9
1 10
2 8
2 9
2 10
3 8
3 9
3 10
0


0 1

5 2
1 2 3 4 5
6 2
-4 -3 -2 -1 3 6
*/
