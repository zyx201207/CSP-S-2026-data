#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 205, M = 2005;
struct node {
	int v, w;
};
int c, n, m, k, d, Q, w[N], cnt, dis[N][M];
vector<node>edge[M];
priority_queue < pii, vector<pii>, greater<pii > >q;
void init() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= cnt; j++)dis[i][j] = 1e9;
		dis[i][i] = 0;
		q.push({0, i});
		while (q.size()) {
			auto h = q.top();
			q.pop();
			int x = h.second;
			if (h.first != dis[i][x])continue;
			for (auto y : edge[x]) {
				if (dis[i][y.v] > dis[i][x] + y.w) {
					dis[i][y.v] = dis[i][x] + y.w;
					q.push({dis[i][y.v], y.v});
				}
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	cnt = m;
	for (int i = 1; i <= m; i++)cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k, l = -1;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			edge[a].push_back({++cnt, t});
			edge[cnt].push_back({a, t});
			if (l != -1){
				edge[l].push_back({cnt, 0});
				edge[cnt].push_back({l, 0});
			}
			l = cnt;
		}
	}
	init();
	while (Q--) {
		int u, v;
		cin >> u >> v;
		if(u==v){cout<<"0\n";continue;}
		cout << dis[u][v] + w[u] + w[v] << "\n";
	}
	return 0;
}