// c - j - c 2026 10 31 csp T2
#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 105;
long long c, n, m;
long long d, q, w[N];
long long mp[5005][5005], f[N];

struct node {
	long long v, w;
};
vector<node>e[N];

long long dis[N], vis[N];

void dij(long long u, long long v) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[u] = 0;
	queue<long long>q;
	q.push(u);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (vis[tmp])
			continue;
		vis[tmp] = 0;
		for (int i = 0; i < e[tmp].size(); i++) {
			long long v = e[tmp][i].v, w = e[tmp][i].w;
			if (dis[v] > dis[tmp] + w) {
				dis[v] = dis[tmp] + w, q.push(v);
			}
		}
	}
}

int main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			long long v, W;
			cin >> v >> W;
			e[v].push_back({m + i, W});
			e[m + i].push_back({v, W});
		}
	}
	while (q--) {
		long long u, v;
		cin >> u >> v;
		dij(u, v);
		cout << w[u] + w[v] + dis[v] << "\n";
	}
	return 0;
}