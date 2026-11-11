#include <iostream>
#include <climits>
#include <bitset>
#include <vector>
#include <queue> 
#include <map>
using namespace std;
const int MAXN = 505, MAXM = 5e5 + 5;
class Edge {
	public:
		int to, lst;
		long long value;
}e[MAXN * MAXN << 1];
class Point {
	public:
		int to;
		long long dis;
	inline bool operator < (const Point &y) const {
		return dis > y.dis;
	}
};
bitset<MAXM>vis[MAXN];
bitset<MAXN>arr;
map<pair<int, int>, long long>ma;
vector<int>v[MAXM];
priority_queue<Point>qu;
long long w[MAXM], dis[MAXN][MAXN];
int ehead[MAXN];
int c, n, m, d, q, ecnt;
inline void add(int u, int v, long long w) {
	e[++ecnt] = {v, ehead[u], w};
	ehead[u] = ecnt;
	e[++ecnt] = {u, ehead[v], w};
	ehead[v] = ecnt;
	return;
}
int main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t;
			cin >> a >> t;
			vis[i].set(a);
			ma[{a, i}] = t;
			v[a].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
				dis[i][j] = dis[j][i] = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			long long d = LLONG_MAX;
			for (int k = 1; k <= m; ++k)
				if (vis[i][k] && vis[j][k])
					d = min(d, ma[{k, i}] + ma[{k, j}]);
			if (d != LLONG_MAX)
				add(i, j, d);
		}
	for (int i = 1; i <= n; ++i) {
		qu.push({i, 0});
		for (int j = 1; j <= n; ++j)
			arr.reset(j);
		while (!qu.empty()) {
			Point now = qu.top();
			qu.pop();
			if (arr[now.to])
				continue;
			arr.set(now.to);
			for (int j = ehead[now.to]; j;j = e[j].lst)
				if (dis[i][e[j].to] > now.dis + e[j].value) {
					dis[i][e[j].to] = now.dis + e[j].value;
					qu.push({e[j].to, dis[i][e[j].to]});
				}
		}
	}
	while (q--) {
		int x, y;
		long long ans = LLONG_MAX;
		cin >> x >> y;
		for (auto i : v[x])
			for (auto j : v[y]) {
				if (dis[i][j] == LLONG_MAX)
					continue;
				ans = min(ans, ma[{x, i}] + ma[{y, j}] + dis[i][j]);
			}
		cout << w[x] + w[y] + ans << '\n';
	}
	return 0;
}
