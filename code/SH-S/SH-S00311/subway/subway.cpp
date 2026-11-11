#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500010], k[20010];
struct edge {
	ll n, m, t;
};
ll e[510][20010], ee[3][500010], nxt[510][20010], pre[510][20010];
vector <ll> belong[500010];
bool vis[510][20010];
vector <ll> g[20010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	if (n <= 2) {
		memset(e, 0, sizeof(e));
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			ll prea = 0;
			for (int j = 1; j <= k[i]; j++) {
				ll a, t;
				cin >> a >> t;
				ee[i][a] = t;
				belong[a].push_back(i);
				nxt[i][prea] = a;
				if (j != 1) {
					pre[i][a] = prea;
				} else {
					pre[i][a] = -1;
				}
				prea = a;
			}
			nxt[i][prea] = -1;
		}
		ll minn = 1e18;
		for (int i = 1; i <= m; i++) {
			if (belong[i].size() == 2) {
				minn = min(minn, ee[1][i] + ee[2][i]);
			}
		}
		while (q--) {
			ll x, y;
			cin >> x >> y;
			if (belong[x].size() == 2) {
				cout << w[x] + ee[belong[y][0]][x] + ee[belong[y][0]][y] + w[y] << "\n";
			} else if (belong[y].size() == 2) {
				cout << w[x] + ee[belong[x][0]][x] + ee[belong[x][0]][y] + w[y] << "\n";
			} else if (belong[x][0] == belong[y][0]) {
				cout << w[x] + ee[belong[x][0]][x] + ee[belong[x][0]][y] + w[y] << "\n";
			} else {				
				cout << w[x] + ee[belong[x][0]][x] + minn + ee[belong[y][0]][y] + w[y] << "\n";
			}	
		}
	} else {
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			ll prea = 0;
			for (int j = 1; j <= k[i]; j++) {
				ll a, t;
				cin >> a >> t;
				e[i][a] = t;
				belong[a].push_back(i);
				nxt[i][prea] = a;
				if (j != 1) {
					pre[i][a] = prea;
				} else {
					pre[i][a] = -1;
				}
				prea = a;
			}
			nxt[i][prea] = -1;
		}
		while (q--) {
			ll x, y;
			cin >> x >> y;
			queue <edge> que;
			for (int i = 0; i < belong[x].size(); i++) {
				que.push({belong[x][i], x, w[x] + e[belong[x][i]][x]});
				vis[belong[x][i]][x] = 1;
			}
			ll ans = 1e18;
			while (!que.empty()) {
				edge l = que.front();
				que.pop();
				if (l.m == y) {
					ans = min(ans, l.t + e[l.n][y] + w[y]);
					continue;
				}
				if (l.m != x) {
					for (int i = 0; i < belong[l.m].size(); i++) {
						if (vis[belong[l.m][i]][l.m] == 0) {
							que.push({belong[l.m][i], l.m, l.t + e[l.n][l.m] + e[belong[l.m][i]][l.m]});
							vis[belong[l.m][i]][l.m] = 1;
						}
					}
				}
				if (nxt[l.n][l.m] != -1 && vis[l.n][nxt[l.n][l.m]] == 0) {
					que.push({l.n, nxt[l.n][l.m], l.t});
					vis[l.n][nxt[l.n][l.m]] = l.n;
				}
				if (pre[l.n][l.m] != -1 && vis[l.n][pre[l.n][l.m]] == 0) {
					que.push({l.n, pre[l.n][l.m], l.t});
					vis[l.n][pre[l.n][l.m]] = l.n;
				}
			}
			cout << ans << "\n";
			memset(vis, 0, sizeof(vis));
		}	
	}
	return 0;
}
