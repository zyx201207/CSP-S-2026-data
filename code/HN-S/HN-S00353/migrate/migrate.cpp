#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N  = 2e6 + 20;
int c, t, n, d, a, b;
int p[N], cnt, lim;
bool stop;
void dfs (int u, int t, int step) {
	if (u == t) {
		if (step <= lim) cnt ++;
		if (cnt > 2) stop = true;
		return ;
	}
//	cout << "Explore u = " << u << " t = " << t << " step = " << step << '\n'; 
	if (step >= lim || stop) return ;
	for (int i = u + 1; p[i] - p[u] <= d && i <= t; i ++)
		dfs (i, t, step + 1);
}
signed main () {
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> t;
	if (11 <= c && c <= 12) {
		while (t --) {
			int k;
			cin >> n >> d >> a >> b;
			for (int i = 1; i <= n - 2; i ++) cin >> k;
			int f = b - a;
			d = d / f * f;
			if (d < 2 * f) cout << 0 << '\n';
			else cout << max (0ll, n - d / f * 2 + 1) << '\n';  
		}
	}
	else {
		for (int T = 1; T <= t; T ++) {
			cin >> n >> d;
//			cout << "No. " << T << " task begins. n = " << n << ", d = " << d << '\n';
			for (int i = 1; i <= n; i ++)
				cin >> p[i];
			int ans = 0;
			for (int i = 1; i <= n; i ++)
				for (int j = i + 1; j <= n; j ++) {
					if (p[j] - p[j - 1] > d) {
//						cout << "The loop was breaked at " << i << " " << j << '\n';
						break;
					}
					lim = ceil ((double)(p[j] - p[i]) / (double)d);
					stop = false;
					cnt = 0;
					dfs (i, j, 0);
//					cout << i << " " << j << " " << "has done the dfs! Function returns cnt = " << cnt << " lim = " << lim << '\n'; 
					if (cnt == 2) ans ++;
				}
			cout << ans << '\n';
		}
	}
	return 0;
}
/*
1 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
