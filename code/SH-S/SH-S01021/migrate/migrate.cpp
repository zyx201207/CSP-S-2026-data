#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 7;
int C, T, n, k, ct[N], a[N], la[N], nx[N], is[N], red[N];
/*
0 1
5 3
-3 0 2 3 4
*/
int len[N], sub[N], fa[N], res[N], cc[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> C >> T;
	while (T--) {
		cin >> n >> k;
		int ans = 0;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 0; i <= n + 1; ++i)
			cc[i] = res[i] = fa[i] = red[i] = is[i] = ct[i] = la[i] = nx[i] = 0, sub[i] = len[i] = 1, fa[i] = i;
		sub[0] = len[0] = sub[n + 1] = len[n + 1] = 0; fa[n + 1] = 0;
		for (int i = 1; i <= n; ++i) {
			// Find max r a[r] <= k + a[i]
			int p = upper_bound(a + i, a + n + 1, a[i] + k) - a - 1;
			nx[i] = p;
			// cout << "Nxt[" << i << "] = " << p << endl;
			// Find min l a[l] >= a[i] - k
			int q = lower_bound(a + 1, a + i + 1, a[i] - k) - a;
			la[i] = q;
			// cout << "Lst[" << i << "] = " << q << endl;
			ct[nx[i]]++;
		}
		for (int i = 1; i <= n; ++i) {
			if (nx[i] == i) continue;
			if (la[nx[i]] == i) {
				// Edge i <-> nx[i]
				is[i] = 1;
				len[nx[i]] = len[i] + 1;
				fa[nx[i]] = fa[i];
				if (nx[i] == nx[i + 1] && nx[i + 1] != i + 1) {
					red[i] = 1;
					// cout << "Red point " << i << endl;
				} 
				// cout << "Edge: " << i << "  <---> " << nx[i] << endl;
			}
		}
		// cout << "=== " << ans << endl;
		for (int i = n; i; --i) 
			if (is[i]) {
				sub[i] = sub[nx[i]] + 1;
				// cout << "Sub: " << i << ' ' << sub[i] << ' ' << len[i] << endl;
				// if (red[i]) ans += ct[i + 1] * max(0ll, sub[i] - 2);//, cout << i + 1 << " ~~~ " << ct[i + 1] << endl;
			}
		// cout << "==== " << ans << endl;
		for (int i = 1; i <= n; ++i) {
			if (la[i] == i) continue;
			int nw = la[i], f = 0;
			if (nw + 1 != i) {
				ans += ct[nw + 1]; f= 1;
				// cout << i << "   " << ct[nw + 1] << endl;
			}
				//, cout << i << ' ' << nw << ' ' << ct[nw + 1] << endl;
				// cout << nw + 1 << endl;
			// cout << i << ' ' << nw << ' ' << fa[nw] << endl;
			++cc[nw];
			// cout << nw << " cc+1\n";
			if (!red[fa[nw]] && (fa[nw] != nw || f == 0)) continue;
			// cout << i << ' ' << fa[i] << ' ' << la[fa[i]] << ' ' << nx[la[fa[i]]] << endl;
			if (nx[la[fa[nw]]] == fa[nw] + 1) {
				// cout << i << "  !!! " << la[fa[i]] << endl;
				// cout << "!!!!!!!!!!!!!!!!!!\n";
				res[la[fa[nw]]]++;
				// fa[nw] ~ nw 中的所有红点 +1
				// cout << la[fa[nw]] << " res+1\n";
				
				// cout << la[fa[nw]] << endl;
			}

		}
		// cout << "==" << ans << endl;
		for (int i = n; i; --i) {
			if (is[i]) res[i] += res[nx[i]], cc[i] += cc[nx[i]];
			// cout << i << "   res = " << res[i] << ' ' << ct[i] << endl;
			ans += res[i] * ct[i] + red[i] * ct[i + 1] * cc[nx[i]];
		}
		cout << ans << endl;
	}
}