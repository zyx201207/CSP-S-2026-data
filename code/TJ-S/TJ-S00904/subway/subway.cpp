//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

#define N 805
#define inf 1e16

ll w[N], t[N][N], dis[N];
int T, n, m, d, q, k[N], a[N][N], x, y;
bool flag[N];

struct node {
	int v;
	ll w;
	friend bool operator< (const node& a, const node& b) {
		return a.w > b.w;
	}
};

vector<node> g[N];

void Dijkstra(int st) {
	priority_queue<node> q;
	q.push({st, 0});
	dis[st] = 0;
	while (!q.empty()) {
		int u = q.top().v;
		q.pop();
		if (!flag[u]) {
			flag[u] = true;
			for (auto x : g[u]) {
				if (!flag[x.v] && dis[x.v] > dis[u] + x.w) {
					dis[x.v] = dis[u] + x.w;
					q.push({x.v, dis[x.v]});
				}
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> T >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	int cnt = m;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			g[++cnt].push_back(node {a[i][j], t[i][j]});
			g[a[i][j]].push_back(node {cnt, t[i][j]});
		}
		for (int j = cnt - k[i] + 2; j <= cnt; j++) {
			g[j - 1].push_back({j, 0});
			g[j].push_back({j - 1, 0});
		}
	}
	while (q--) {
		for (int i = 1; i <= N - 5; i++) dis[i] = inf;
		memset(flag, false, sizeof(flag));
		cin >> x >> y;
		Dijkstra(x);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}

/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
