#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair <int, int> pi;
const int N = 2e6 + 5;
priority_queue <pi, vector <pi>, greater <pi> > q;
int cnt[N], ans, dis[N], a[N], c, T, n, d;
vector <pi> g[N];
bitset <N> vis;
void dijkstra (int s) {
	memset (dis, 0x3f, sizeof (dis));
	memset (cnt, 0, sizeof (cnt));
	vis.reset ();
	dis[s] = 0; q.push ({0, s});
	cnt[s] = 1;
	while (!q.empty ()) {
		int u = q.top ().second;
		q.pop ();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto p : g[u]) {
			int v = p.first;
			int w = p.second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w, cnt[v] = cnt[u];
				q.push ({dis[v], v});
			}
			else if (dis[u] + w == dis[v]) cnt[v] += cnt[u];
		}
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 2 && s != i) ans++;
}
signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> c >> T;
	while (T--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			g[i].clear ();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 1; j < i; j++) {
				if (a[i] - a[j] <= d) {
					g[i].push_back ({j, 1});
					g[j].push_back ({i, 1});
				}
			}
		}
		for (int i = 1; i <= n; i++)
			dijkstra (i);
		cout << ans / 2 << "\n";
	}
	return 0;
}
//初三了，分数 200pts+，预估，是不是完蛋了