#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5 * 1e5 + 5;
int c, n, m, d, q, w[maxn], vis[maxn], dis[maxn];
vector <int> a[maxn], bel[maxn];
vector <pair <int, int> > G[maxn];
map <int, int> t[maxn];
int spfa(int s, int t, int ls) {
	queue <pair <int, int> > q;
	memset(vis, 0, (m + 1) * 8);
	memset(dis, 0x3f, (m + 1) * 8);
	vis[s] = 1, dis[s] = 0;
	q.push(make_pair(s, ls));
	while (!q.empty()) {
		int u = q.front().first, l = q.front().second; q.pop();
		vis[u] = 0;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].first, lin = G[u][i].second;
			int w = 0;
			if (l != lin)
				w = ::t[u][l] + ::t[u][lin];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (vis[v] <= n) {
					vis[v]++;
					q.push(make_pair(v, lin));
				}
			}
		}
	}
	return dis[t];
}
signed main() {
	freopen("subway4.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			bel[x].push_back(i);
			a[i].push_back(x);
			t[x][i] = y;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j + 1 < a[i].size(); j++) {
			G[a[i][j]].push_back(make_pair(a[i][j + 1], i));
			G[a[i][j + 1]].push_back(make_pair(a[i][j], i));
		}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = LLONG_MAX;
		for (int i = 0; i < bel[x].size(); i++) {
			for (int j = 0; j < bel[y].size(); j++) {
				int l1 = bel[x][i], l2 = bel[y][j];
				ans = min(ans, w[x] + t[x][l1] + spfa(x, y, l1) + t[y][l2] + w[y]);
			}
		}
		cout << ans << "\n";
	}
} 
