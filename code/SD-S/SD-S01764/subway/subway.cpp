#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int N = 503;
const int M = 5e5 + 3;
int c, n, m, d, q, w[M], k[N], dp[N][N], x, y;
struct Node {
	int v, w;
	bool operator < (const Node &t) const {
		return w > t.w;
	}
	friend istream &operator >> (istream &is, Node &t) {
		is >> t.v >> t.w;
		return is;
	}
} node;
priority_queue<Node> que;
vector<Node> a[N], lu[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> node;
			a[i].push_back(node);
			lu[node.v].push_back({i, node.w});
		}
	}
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 1; i <= m; i++) {
		dp[i][i] = 0;
		que.push({i, 0});
		while (!que.empty()) {
			Node w = que.top();
			que.pop();
			if (w.w > dp[i][w.v]) continue;
			for (int u = 0; u < (int)(lu[w.v].size()); u++) {
				for (int v = 0; v < (int)(a[lu[w.v][u].v].size()); v++) {
					if (a[lu[w.v][u].v][v].v != w.v) {
						if (dp[i][a[lu[w.v][u].v][v].v] > dp[i][w.v] + lu[w.v][u].w + a[lu[w.v][u].v][v].w) {
							dp[i][a[lu[w.v][u].v][v].v] = dp[i][w.v] + lu[w.v][u].w + a[lu[w.v][u].v][v].w;
							que.push({a[lu[w.v][u].v][v].v, dp[i][a[lu[w.v][u].v][v].v]});
						}
					}
				}
			}
		}
	}
	while (q--) {
		cin >> x >> y;
		cout << dp[x][y] + w[x] + w[y] << endl;
	}
	
	return 0;
} 
