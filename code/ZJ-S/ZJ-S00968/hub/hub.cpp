#include <bits/stdc++.h>

using namespace std;

const int maxn = 11;
#define LL long long

int c, T;
int n, k;
vector <int> g[maxn];
bool use[maxn];
bool vis[maxn];
LL ans = 1e18;
LL dis[maxn][maxn];

void check(int u, int fa) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (v == fa || !use[v]) continue;
		check(v, u);
	}
}

void dfs(int i, int cnt) {
	if (cnt > k) return ;
	if (i > n) {
		if (cnt < k) return ;
		int block = 0;
		memset(vis, 0, sizeof vis);
		for (int u = 1; u <= n; u ++) {
			if (use[u] && !vis[u]) {
				block ++;
				check(u, 0);
			}
		}
		if (block <= 2) {
			LL res = 0;
			for (int u = 1; u <= n; u ++) {
				if (!use[u]) {
					LL min_d = 1e18;
					for (int v = 1; v <= n; v ++) {
						if (!use[v]) continue;
						min_d = min(min_d, dis[u][v]);
					}
					res = max(res, min_d);
				}
			}
			ans = min(ans, res);
		}
		return ;
	}
	use[i] = 1;
	dfs(i + 1, cnt + 1);
	use[i] = 0;
	dfs(i + 1, cnt);
}

void dist(int s, int u, int fa, int d) {
	dis[s][u] = d;
	for (int v : g[u]) {
		if (v != fa) {
			dist(s, v, u, d + 1);
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (cin >> c >> T; T; T --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) g[i].clear();
		for (int i = 1, u, v; i < n; i ++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		if (n <= 10) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= n; j ++) dis[i][j] = 0;
			}
			for (int s = 1; s <= n; s ++) {
				dist(s, s, 0, 0);
			}
			ans = 1e18;
			dfs(1, 0);
			cout << ans << '\n';
			continue;
		}
		
		if (k == 2) {
			LL min1 = 0, min2 = 0, min1i, min2i;
			for (int i = 1; i <= n; i ++) {
				LL res = 1e18;
				for (int j = 1; j <= n; j ++) {
					if (i != j) {
						res = min(res, dis[i][j]);
					}
				}
				if (res > min1) {
					min2i = min1i;
					min2 = min1;
					min1 = res;
					min1i = i;
				}
				else if (res > min2) {
					min2i = i;
					min2 = res;
				}
			}
			
			LL ans = 1e18;
			for (int i = 1; i <= n; i ++) {
				if (i == min1i || i == min2i) continue;
				LL res = 1e18;
				for (int j = 1; j <= n; j ++) {
					if (i != j) {
						res = min(res, dis[i][j]);
					}
				}
				ans = min(ans, res);
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
