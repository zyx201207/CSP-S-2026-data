#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int c, n, m, d, q;
int w[N];
int k[N];
int a[505][N];
int t[505][N];
vector<int> in[N];
int x, y;
int pos[N][505];
int dis[N];
int vis[N];
int dp[1005][1005];
map<pair<int, int>, vector<int> >f;


struct node {
	int v, w;
	friend bool operator<(node a, node b) {
		return a.w > b.w;
	}
};
vector<node> e[N];

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}
}

void dijkstra(int s) {
	priority_queue<node> q;
	q.push({s, 0});
	dis[s] = 0;
	while (!q.empty()) {
		node u = q.top();
		q.pop();
		int x = u.v;
		int cnt = u.w;
		if (vis[x])
			continue;
		vis[x] = 1;
		for (auto tmp : e[x]) {
			int v = tmp.v;
			int w = tmp.w;
			if (dis[v] > dis[x] + w) {
				dis[v] = dis[x] + w;
				q.push({v, dis[v]});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		sum += k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			pos[a[i][j]][i] = j;
			in[a[i][j]].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto x : in[i]) {
			for (auto v : in[i]) {
				if (x == v)
					continue;
				f[ {x, v}].push_back(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			for (auto v : f[ {i, j}]) {
				e[i].push_back({j, t[i][pos[v][i]] + t[j][pos[v][j]]});
				e[j].push_back({i, t[i][pos[v][i]] + t[j][pos[v][j]]});
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[j] = 1e18;
			vis[j] = 0;
		}
		dijkstra(i);
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[j][i] = dis[j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		vector<int> Y;
		for (auto v : in[y]) {
			Y.push_back(v);
		}
		for (auto v : in[x]) {
			int minn = 1e18;
			for (auto z : Y) {
				minn = min(minn, dp[z][v] + t[z][pos[y][z]]);
			}
			minn += w[x] + w[y];
			minn += t[v][pos[x][v]];
			ans = min(ans, minn);
		}
		cout << ans << endl;
	}
	return 0;
}
/*
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