// 325 points? Seems high. But perhaps I win nobody.
// I have no chance solving tree problems like this.
// Surrender.
// Even if my guess that when k = 2, selected points should be on diameter is correct
// I can't pass subtask 11 & 12, which will leave me only 5 points on this one.
// Terrible.
// Not even a single idea of a polynomial complexity solution.
// I'd rather get back to Windows and waste time until contest ends.
#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;
int ecnt, nxt[2000005], hd[1000005], to[2000005];
void addedge(int u, int v) {
	to[++ecnt] = v;
	nxt[ecnt] = hd[u];
	hd[u] = ecnt;
}
namespace Solve123 {
	int dis[15][15];
	void solve() {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(i != j) {
					dis[i][j] = 100000;
				}
			}
		}
		for(int u = 1; u <= n; ++u) {
			for(int i = hd[u]; i; i = nxt[i]) {
				int v = to[i];
				dis[u][v] = 1;
			}
		}
		for(int k = 1; k <= n; ++k) {
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= n; ++j) {
					if(dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
		int ans = 100000;
		for(int i = 0; i < (1 << n); ++i) {
			int cnt = 0;
			for(int j = 1; j <= n; ++j) {
				if(i & (1 << (j - 1))) {
					++cnt;
				}
			}
			if(cnt == k) {
				int pwp = 0;
				for(int p = 1; p <= n; ++p) {
					if(i & (1 << (p - 1))) {
						for(int q = p + 1; q <= n; ++q) {
							if(i & (1 << (q - 1))) {
								if(dis[p][q] == 1) {
									++pwp;
								}
							}
						}
					}
				}
				if(pwp <= k - 3) {
					continue;
				}
				int maxx = 0;
				for(int p = 1; p <= n; ++p) {
					if((i & (1 << (p - 1))) == 0) {
						int minn = 100000;
						for(int j = 1; j <= n; ++j) {
							if(i & (1 << (j - 1))) {
								minn = min(minn, dis[p][j]);
							}
						}
						maxx = max(maxx, minn);
					}
				}
				ans = min(ans, maxx);
			}
		}
		cout << ans << '\n';
	}
}
namespace Solve1314 {
	void solve() {
		if(k == n) {
			cout << 0 << '\n';
			return;
		}
		n /= 2;
		int p = n - k;
		if(p >= 1) cout << p / 4 + 2 << '\n';
		else cout << 1 << '\n';
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		ecnt = 0;
		for(int i = 1; i <= n; ++i) {
			hd[i] = 0;
		}
		for(int i = 1, u, v; i <= n - 1; ++i) {
			cin >> u >> v;
			addedge(u, v);
			addedge(v, u);
		}
		if(c <= 3) {
			Solve123 :: solve();
		}
		if(c == 13 || c == 14) {
			Solve1314 :: solve();
		}
	}
	return 0;
}