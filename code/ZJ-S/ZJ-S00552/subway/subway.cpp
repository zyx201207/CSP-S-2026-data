#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair <int, int> pi;
const int N = 505, M = 5e5 + 5;
int dp[N][N], c, n, m, d, T, w[M], g[M][25][2];
priority_queue <pi, vector <pi>, greater <pi> > q;
vector <pi> e[N]; 
bitset <M> vis;
void dijkstra (int s) {
	vis.reset ();
	dp[s][s] = 0;
	q.push ({0, s});
	while (!q.empty ()) {
		int u = q.top ().second;
		q.pop ();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto p : e[u]) {
			int v = p.first;
			int w = p.second;
			if (dp[s][u] + w < dp[s][v]) {
				dp[s][v] = dp[s][u] + w;
				q.push ({dp[s][v], v});
			}
		}
	}
}
signed main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> c >> n >> m >> d >> T;
	memset (dp, 0x3f, sizeof (dp));
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, x, y; j <= k; j++) {
			cin >> x >> y;
			g[x][0][0]++;
			g[x][g[x][0][0]][0] = i;
			g[x][g[x][0][0]][1] = y;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= g[i][0][0]; j++) {
			for (int k = j + 1; k <= g[i][0][0]; k++) {
				int u = g[i][j][0], v = g[i][k][0];
				int w1 = g[i][j][1], w2 = g[i][k][1];
				dp[u][v] = min (dp[u][v], w1 + w2);
				dp[v][u] = min (dp[v][u], w1 + w2);
			}
		}
	}
	for (int u = 1; u <= n; u++) {
		for (int v = u + 1; v <= n; v++) {
			e[u].push_back ({v, dp[u][v]});
			e[v].push_back ({u, dp[v][u]});
		}
	}
	memset (dp, 0x3f, sizeof (dp));
	for (int s = 1; s <= n; s++) dijkstra (s);
	while (T--) {
		int s, t, ans = 1e18;
		cin >> s >> t;
		for (int i = 1; i <= g[s][0][0]; i++) {
			for (int j = 1; j <= g[t][0][0]; j++) {
				int u = g[s][i][0], v = g[t][j][0];
				int w1 = g[s][i][1], w2 = g[t][j][1];
				ans = min (dp[u][v] + w[s] + w[t] + w1 + w2, ans);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
//硬控 2h 祭