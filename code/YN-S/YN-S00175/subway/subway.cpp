//hy
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e5 + 10;
const int N = 510;
int C, n, m, d, q;
int w[M];

struct node {
	int v, w;
	friend bool operator <(node x, node y) {
		return x.w > y.w;
	}
};
vector<node>e[M], g[N];
int f[N][N];
bool bk[N][N];

void djst(int x) {
	priority_queue<node>q;
	q.push({x, 0});
	while (q.size()) {
		auto tmp = q.top();
		q.pop();
		int u = tmp.v;
		if (bk[x][u])
			continue;
		bk[x][u] = 1;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			int w = g[u][i].w;
			if (f[x][v] > f[x][u] + w) {
				f[x][v] = f[x][u] + w;
				q.push({v, f[x][v]});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			e[a].push_back({i, t});
		}
	}
	memset(f, 0x3f3f3f3f, sizeof(f));
	for (int i = 1; i <= m; i++) {
		for (int x = 0; x < e[i].size(); x++) {
			for (int y = x + 1; y < e[i].size(); y++) {
				int t = e[i][x].w + e[i][y].w;
				g[e[i][x].v].push_back({e[i][y].v, t});
				g[e[i][y].v].push_back({e[i][x].v, t});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = 0;
		djst(i);
	}
	while (q--) {
		int x, y, ans = 1e18;
		cin >> x >> y;
		for (int i = 0; i < e[x].size(); i++) {
			for (int j = 0; j < e[y].size(); j++) {
				int t = e[x][i].w + e[y][j].w + w[x] + w[y] + f[e[x][i].v][e[y][j].v];
				ans = min(ans, t);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
