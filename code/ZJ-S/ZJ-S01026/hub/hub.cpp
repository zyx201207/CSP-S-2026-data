#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
#define pb push_back
#define pii pair< int, int >
#define pll pair< ll, ll >

const int N = 1e6 + 10;

int n, k;

vec< int > g[N];

pii dis[N];

void bfs(int s1, int s2) {
	if (~s1) dis[s1] = make_pair(0, s1);
	if (~s2) dis[s2] = make_pair(0, s2);
	queue< int > q;
	if (~s1) q.push(s1);
	if (~s2) q.push(s2);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : g[u]) {
			if (dis[v].fi > dis[u].fi + 1) {
				dis[v] = make_pair(dis[u].fi + 1, u);
				q.push(v);
			}
		}
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) g[i].clear();
	for (int i = 1; i < n; i ++) {
		int u, v; cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	int res = 1e9;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			for (int l = 1; l <= n; l ++) dis[l] = make_pair(1e9, -1);
			bfs(i, j);
			for (int t = 3; t <= k; t ++) {
				pii mx = make_pair(-1, -1); int id = -1;
				for (int l = 1; l <= n; l ++) {
					if (dis[l] > mx) mx = dis[l], id = l;
				}
				int u = mx.se;
				while (dis[u].fi != 0) {
					id = u;
					u = dis[u].se;
				}
				bfs(id, -1);
			}
			int mx = 0;
			for (int l = 1; l <= n; l ++) mx = max(mx, dis[l].fi);
			res = min(res, mx);
		}
	}
	cout << res << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	clock_t st = clock();
	
	int c, T = 1;
	cin >> c >> T;
	while (T --) solve();
	
	clock_t ed = clock();
	cerr << "time:" << (double)(ed - st) / (double)CLOCKS_PER_SEC << "s" << '\n';
	return 0;
}