#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, x[N];
typedef long long ll;
ll ans = 0;
int pre[N], suf[N], f[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0); 
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) {
		ans = 0;
		memset(f, 0, sizeof(f));
		memset(pre, 0, sizeof(pre));
		memset(suf, 0, sizeof(suf));
		cin >> n >> d;
		for(int i=1; i<=n; ++i) {
			cin >> x[i];
		}
		if(n < 4) {
			cout << 0 << '\n';
			continue;
		}
		for(int i=1; i<=n; ++i) {
			int tgt = x[i] + d;
			if(tgt > x[n]) pre[i] = n + 1;
			else if(tgt == x[n]) pre[i] = n;
			else pre[i] = upper_bound(x + 1, x + 1 + n, tgt) - x - 1;
		}
		for(int i=n; i>=1; --i) {
			int tgt = x[i] - d;
			if(tgt < x[1]) suf[i] = 0;
			else if(tgt == x[1]) suf[i] = 1;
			else suf[i] = lower_bound(x + 1, x + 1 + n, tgt) - x;
		}
        pre[n + 1] = n + 1;
		for(int i=1; i<=n-3; ++i) {
			int p1 = i, p3 = pre[i];
			int p2 = p3 - 1, p4 = pre[p2];
			if(p3 == n + 1 || p4 == n + 1) continue;
			if(p4 - p1 <= 2) continue;
			int lc = 1, rc = 1, pp = p1;
			while(1) {
				if(suf[pp] == 0 || suf[pp] == pp) break;
				else {
					pp = suf[pp];
					++lc;
				}
			}
			pp = p4;
			while(1) {
				if(pre[pp] == n + 1 || pre[pp] == pp) break;
				else {
					pp = pre[pp];
					++rc;
				}
			}
			f[p4] = lc;
//			cout << lc << ' ' << rc << '\n';
		}
		for(int i=1; i<=n; ++i) {
			int pp = i;
			while(1) {
				if(suf[pp] == 0 || suf[pp] == pp) break;
				else {
					pp = suf[pp];
//					ans++;
				}
			}
//			cout << i << ' ' << f[i] << '\n';
			pp = i;
			int tot = 1;
			while(1) {
				if(pre[pp] == n + 1 || pre[pp] == pp) break;
				else {
					pp = pre[pp];
					tot++;
				}
			}
			ans += f[i] * tot;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
7 2
4 2
1 2 3 4
5 2
1 2 3 4 5
7 1
5 3
1 2 3 4 5
*/
