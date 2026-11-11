#define ll long long
#define _up(i, a, b, c) for (ll i = a; i <= b; i += c)
#define up(i, a, b) _up(i, a, b, 1)
#define _dn(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define dn(i, a, b) _dn(i, a, b, 1)
#define N 100005
const ll INF = 1e15;
ll c, t, n, k, u, v, ans, fa[25][N], dep[N];
#include <bits/stdc++.h>
using namespace std;
vector <ll> g[N];

void dfs(ll x, ll f) {
	fa[0][x] = f;
	dep[x] = dep[f] + 1;

	for (ll i : g[x]) {
		if (i != f) {
			dfs(i, x);
		}
	}
}

ll lca(ll u, ll v) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	ll d = dep[u] - dep[v];
	up (i, 0, 20) {
		if (d & (1 << i)) {
			u = fa[i][u];
		}
	}
	if (u == v) {
		return u;
	}
	dn (i, 19, 0) {
		if (fa[i][u] != fa[i][v]) {
			u = fa[i][u];
			v = fa[i][v];
		}
	}
	return fa[0][u];
}

bool bf[N];

void init() {
	cin >> c >> t;

	while (t--) {
		cin >> n >> k;
		up (i, 1, n) {
			fa[0][i] = 0;
			dep[i] = 0;
			bf[i] = 0;
			g[i].clear();
		}

		up (i, 1, n - 1) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		dfs(1, 0);

		up (i, 1, 20) {
			up (j, 1, n) {
				fa[i][j] = fa[i - 1][fa[i - 1][j]];
			}
		}

		up (i, n - k + 1, n) {
			bf[i] = 1;
		}
		
		ans = INF;

		do {
			ll cnt = 0, tans = 0;
			up (i, 1, n) {
				if (bf[i]) {
					if (!bf[fa[0][i]]) {
						cnt++;
					}
				}
			}
			if (cnt == 2) {
				up (i, 1, n) {
					ll di = INF;
					up (j, 1, n) {
						if (bf[j]) {
							di = min(di, dep[i] + dep[j] - 2 * dep[lca(i, j)]);
						}
					}
					tans = max(tans, di);
				}
				ans = min(ans, tans);
			}
		} while (next_permutation(bf + 1, bf + n + 1));
		
		cout << ans << '\n';
	}
}

int main() {
	freopen("hub.in", "r", stdin);
//	freopen("hub2.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	return 0;
}