#include <bits/stdc++.h>
using namespace std;
struct node {
	int x, l, t;
};
struct line {
	int x, t;
};
int c, n, m, d, q, k, l, r;
int w[500005], a, t;
bool vis[500005];
vector<line> g[505];
vector<int> sub[505];
void bfs(int l, int line, int r) {
	queue<node> q;
	q.push(node{l, line, w[l] + w[r]});
	vis[l] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.l == r) {
			cout << now.t;
			return;
		}
		for (int i = 1; i < g[now.l].size(); i++) {
			if (vis[i]) {
				continue;
			}
			vis[i] = 1;
			q.push(node{g[now.l][i].x, now.l, now.t + g[now.l][i].t});
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i]; 
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			g[i].push_back(line{a, t});
			sub[a].push_back(i);
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		for (int j = 1; j <= n; j++) {
			if (g[j][1].x == l) {
				bfs(l, j, r);
			}
		}
	}
	return 0; 
}
