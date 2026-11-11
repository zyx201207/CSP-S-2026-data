// Wow.
// This code is impressing.
// No one can understand what the code did and neither can I after a few days.
#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[2000005], nxt[2000005], bifur[2000005], nxtt[2000005], nnx[2000005], nxc[2000005], nxttc[2000005];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) {
			cin >> x[i];
			nxt[i] = i;
			nxc[i] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			nxt[i] = max(nxt[i], nxt[i - 1]);
			while(nxt[i] < n && x[nxt[i] + 1] - x[i] <= d) {
				++nxt[i];
			}
		}
		int ans = 0;
		for(int i = n; i >= 1; --i) {
			++nxc[nxt[i]];
			if(nxt[i - 1] != nxt[i] && nxt[i] > i && i < n) {
				bifur[i] = nxt[i] - nxt[i - 1] + bifur[nxt[i]];
			}
			else {
				bifur[i] = 0;
			}
		}
		for(int i = n; i >= 1; --i) {
			if(nxt[i - 1] == nxt[i] - 1) {
				nxtt[i] = nxtt[nxt[i]];
			}
			else {
				nxtt[i] = i;
			}
		}
		for(int p = 1; p <= n; ++p) {
			if(nxt[p] <= p || p == n) {
				nnx[p] = -1;
				continue;
			}
			int np = nxt[p], npred = nxt[p - 1];
			if(npred == p) {
				nnx[p] = np;
				continue;
			}
			if(npred == np - 1 && nxt[nxtt[p] - 1] == nxt[nxtt[p]]) {
				nnx[p] = -1;
				continue;
			}
			if(npred == np) {
				nnx[p] = -1;
				continue;
			}
			nnx[p] = nxt[nxtt[p]];
		}
		for(int i = 1; i <= n; ++i) {
			nxttc[i] = 0;
			bifur[i] = 0;
			if(nxt[i] > i && i < n) {
				if(nxt[i - 1] != i) {
					bifur[i] += nxt[i - 1] - nxt[i - 2];
				}
				if(nxt[i - 1] == nxt[i] && nxt[i - 2] != nxt[i]) {
					bifur[i] += bifur[nxt[i]];
				}
			}
		}
		for(int i = 1; i <= n; ++i) {
			nxttc[i] += nxc[i];
			if(nxtt[i] != -1) {
				nxttc[nnx[i]] += nxttc[i];
			}
		}
		for(int i = 1; i <= n; ++i) {
			ans += nxttc[i] * bifur[i];
		}
		cout << ans << '\n';
	}
	return 0;
}