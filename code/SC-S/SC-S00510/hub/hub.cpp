#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define il inline
#define cstex constexpr
#define endl '\n'
#define frer(filename) assert(freopen(filename, "r", stdin))
#define frew(filename) assert(freopen(filename, "w", stdout))

cstex int N = 10, XN = N + 10, inf = 0x3f3f3f3f;
int kase, T, n, m; int g[XN][XN], ans; bool vis[XN];
vector<int> G[XN];

il void dfs(int u, int s) {
	vis[u] = true;
	for (int v : G[u]) if ((s >> (v - 1) & 1) && !vis[v]) dfs(v, s);
}

il bool check(int s) {
	for (int i = 1; i <= n; i++) vis[i] = false;
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; i++) sum += (s >> (i - 1) & 1);
	for (int i = 1; i <= n; i++) if (s >> (i - 1) & 1) cnt++, dfs(i, s);
	return cnt <= 2 && sum <= m;
}

int main() {
	frer("hub.in"), frew("hub.out");
	ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> kase >> T; T --> 0; ) {
		cin >> n >> m, ans = inf;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) g[i][j] = i == j ? 0 : inf;
		for (int i = 1, u, v; i < n; i++)
			cin >> u >> v, g[u][v] = g[v][u] = 1, G[u].push_back(v), G[v].push_back(u);
		for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		for (int s = 1; s < (1 << n); s++) if (check(s)) {
			int res = 0;
			for (int i = 1; i <= n; i++) if (!(s >> (i - 1) & 1)) {
				int cur = inf;
				for (int j = 1; j <= n; j++) if (s >> (j - 1) & 1)
					cur = min(cur, g[i][j]);
				res = max(res, cur);
			}
			ans = min(ans, res);
		}
		cout << ans << endl;
	}
	return 0;
}
