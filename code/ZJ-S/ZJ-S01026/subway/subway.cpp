#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
#define pb push_back
#define pii pair< int, int >
#define pll pair< ll, ll >

const int N = 5e5 + 10;
const int M = 510;

int c, n, m, d, q;

int co[N], id[N], tot;
vec< pii > g[M + N];
ll dis[M + N], res[M][M];
bool vis[M + N];

struct node {
	int x; ll dist;
	bool operator < (const node k) const {
		return dist > k.dist;
	}
};

void dij(int s) {
	for (int i = 1; i <= tot; i ++) {
		dis[i] = 1e18; vis[i] = 0;
	}
	priority_queue< node > q;
	dis[s] = 0;
	q.push({s, 0});
	while (!q.empty()) {
		int u = q.top().x; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto o : g[u]) {
			int v = o.fi, w = o.se;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) q.push({v, dis[v]});
			}
		}
	}
}

void solve() {
	cin >> c >> m >> n >> d >> q; tot = m;
	for (int i = 1; i <= n; i ++) id[i] = ++ tot;
	for (int i = 1; i <= n; i ++) {
		cin >> co[i];
	}
	for (int i = 1; i <= m; i ++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j ++) {
			int x, w; cin >> x >> w;
			g[id[x]].pb({i, w});
			g[i].pb({id[x], w});
		}
	}
	for (int i = 1; i <= m; i ++) {
		dij(i);
		for (int j = 1; j <= m; j ++) {
			res[i][j] = dis[j];
		}
	}
	while (q --) {
		int u, v; cin >> u >> v;
		ll s = co[u] + co[v];
		ll mn = 1e18;
		for (auto x : g[id[u]]) {
			for (auto y : g[id[v]]) {
				int uu = x.fi, vv = y.fi;
				int w1 = x.se, w2 = y.se;
				mn = min(mn, res[uu][vv] + w1 + w2);
			}
		}
		cout << s + mn << '\n';
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	clock_t st = clock();
	
	int T = 1;
//	cin >> T;
	while (T --) solve();
	
	clock_t ed = clock();
	cerr << "time:" << (double)(ed - st) / (double)CLOCKS_PER_SEC << "s" << '\n';
	return 0;
}