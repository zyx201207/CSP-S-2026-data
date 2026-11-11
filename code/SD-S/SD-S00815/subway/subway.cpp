#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
struct Edge {
	int v, w;
};
int c, n, m, d, q;
int st, ed;
int pw[500050];
int k[550];
int a[550][20050], t[550][20050];
vector<Edge> edge[500050];
bool vis[500050];
ll ans;
void dfs(int u, ll dis) {
	if (u == ed) {
		ans = min(ans, dis);
		return;
	}
	for (int i = 0; i < edge[u].size(); ++i) {
		if (!vis[edge[u][i].v]) {
			vis[edge[u][i].v] = true;
			dfs(edge[u][i].v, dis + edge[u][i].w);
			vis[edge[u][i].v] = false;
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> pw[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j)
			cin >> a[i][j] >> t[i][j];
		for (int x = 1; x <= k[i]; ++x)
			for (int y = 1; y <= k[i]; ++y)
				if (x != y) edge[a[i][x]].push_back({a[i][y], t[i][y] + t[i][x]});
	}
	while (q--) {
		cin >> st >> ed;
		memset(vis, false, sizeof(vis));
		ans = LLONG_MAX;
		vis[st] = true;
		dfs(st, pw[st]);
		cout << ans + pw[ed] << '\n';
	}
	return 0;
}
