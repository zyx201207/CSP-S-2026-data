#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q, w[N], dis[510][510];
vector<pair<int, int> > E[N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k, a, t;
		cin >> k;
		while (k --) {
			cin >> a >> t;
			E[a].emplace_back(i, t);
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i ++) dis[i][i] = 0;
	for (int i = 1; i <= m; i ++) {
		for (auto p : E[i])
			for (auto q : E[i])
				dis[p.x][q.x] = min(dis[p.x][q.x], p.y + q.y);
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int k = 1; k <= n; k ++)
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
	while (q --) {
		int u, v, ans = 1e18;
		cin >> u >> v;
		for (auto p : E[u])
			for (auto q : E[v]) ans = min(ans, dis[p.x][q.x] + p.y + q.y);
//		cout << ans << '\n';
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}