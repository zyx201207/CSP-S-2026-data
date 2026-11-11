#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define PII pair<int, int>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, vis[M + N], w[M], k, dis[M + N];
struct node {
	int to, len;
};
priority_queue<PII, vector<PII>, greater<PII> >q;
vector<node>e[N + M];
void dij() {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	while (!q.empty()) q.pop();
	dis[1] = 0;
	q.push({0, 1});
	while (!q.empty()) {
		int u = q.top().second;
		int len = q.top().first;
		q.pop();
		vis[u] = 1;
		for (auto t : e[u]) {
			if (vis[t.to]) continue;
			if (dis[t.to] > dis[u] + t.len) {
				dis[t.to] = dis[u] + t.len;
				q.push({dis[t.to], t.to});
				vis[t.to] = 1;
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int Q;
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1 ; i <= m ; ++i) cin >> w[i];
	for (int i = 1 ; i <= n ; ++i) {
		cin >> k;
		for (int j = 1 ; j <= k ; ++j) {
			int x, y;
			cin >> x >> y;
			e[x].push_back({i + m, y});
			e[i + m].push_back({x, y});			
		}
	}
	dij();
	while (Q--) {
		int l, r;
		cin >> l >> r;
		int x = max(r, l);
		int y = min(r, l);
		cout << dis[x] - dis[y]  + w[x] + w[y] << "\n";
	}
	return 0;
}
