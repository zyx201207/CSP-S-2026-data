#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 + 5e5 + 5;

int c, n, m, d, q;
int w[N], t[505][25], dis[N];
vector<vector<int> > real_ans;

struct node {
	int y, w;
	
	bool operator < (const node &b) const {
		return w > b.w;
	}
};

priority_queue<node> Q;
bool vis[N];
vector<node> e[N];

void dijkstra(int x) {
	while(!Q.empty()) Q.pop();
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	Q.push(node{x, 0});
	dis[x] = 0;
	while (!Q.empty()) {
		node x = Q.top();
		Q.pop();
		if (vis[x.y]) return ;
		vis[x.y] = 1;
		int len = e[x.y].size();
		for (int i = 0; i < len; i++) {
			node v = e[x.y][i];
			if (dis[v.y] > dis[x.y] + v.w) {
				dis[v.y] = dis[x.y] + v.w;
				Q.push(node{v.y, dis[v.y]});
			}
		}
	}
} 

int G[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		int last = 0;
		for (int j = 1, x; j <= k; j++) {
			cin >> x >> t[i][j];
			G[x] = i;
			e[x].push_back(node{m + i, t[i][j]});
			e[m + i].push_back(node{x, t[i][j]});
		}
	}
	if (m * m <= 1000000) {
		real_ans.resize(m + 1);
		for (int i = 1; i <= m; i++) {
			dijkstra(i);
			for (int j = 1; j <= m; j++) {
				real_ans[i].push_back(dis[j] + w[i] + w[j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x == y) {
			cout << 0 << '\n';
		} else {
			if (m * m <= 1000000) {
				cout << real_ans[x][y - 1] << '\n';
			} else {
				dijkstra(x);
				cout << dis[y] + w[x] + w[y] << '\n';
			}
		}
	}
	return 0;
}
/*
tai nan le.


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
