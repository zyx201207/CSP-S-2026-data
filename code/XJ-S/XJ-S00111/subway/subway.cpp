#include <bits/stdc++.h>
using namespace std;

const int N = 511;
const int M = 500011;
int c, n, m, d, q;
int w[M], k[N];
vector<int> a[N], t[N], dt[M];
vector<pair<int, int>> edges[M];
long long dist[M];
bool vis[M];

inline void bfs(int x) {
	for (int i = 1; i <= m; i++)
		dist[i] = 1LL << 60LL, vis[i] = false;
	dist[x] = w[x];
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		vis[v] = true;
		for (auto p : dt[v]) {
			int pos = 0;
			for (int i = 1; i <= k[p]; i++) {
				if (a[p][i] == v) {
					pos = i;
					break;
				}
			}
			for (int i = 1; i <= k[p]; i++) {
				if (vis[a[p][i]] || a[p][i] == v) continue;
				if (dist[v] + t[p][pos] + t[p][i] < dist[a[p][i]]) {
					dist[a[p][i]] = dist[v] + t[p][pos] + t[p][i];
					q.push(a[p][i]);
				}
			}
		}
	}
	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]), dt[i].clear();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		a[i].clear(), t[i].clear();
		a[i].push_back(-1), t[i].push_back(-1);
		for (int j = 1; j <= k[i]; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i].push_back(x), t[i].push_back(y);
			dt[x].push_back(i);
		}
		for (int j = 2; j <= k[i]; j++) {
			edges[a[i][j - 1]].push_back({a[i][j], i});
			edges[a[i][j]].push_back({a[i][j - 1], i});
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		bfs(x);
		printf("%lld\n", dist[y] + w[y]);
	}
	return 0;
}
