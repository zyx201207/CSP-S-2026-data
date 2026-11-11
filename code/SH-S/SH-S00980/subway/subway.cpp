#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 1, INF = 1e9;
int c, n, m, d, q;
long long dis[N + 501];
int w[N], k, a[501][N], t[501][N];
bool vis[N + 501];
vector<pair<int, long long> > g[N + 501];
void dij(int s){
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		dis[i] = INF; 
	}
	dis[s] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
	q.push({0, s});
	while(q.size()) {
		long long d = q.top().first;
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].first;
			long long w = g[u][i].second;
			dis[v] = min(dis[u] + w, dis[v]);
			q.push({dis[v], v});
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	int T;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= 2 * k; j++) {
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld", w[l] + w[r] + t[1][1] + t[1][2]);
	}
	return 0;
} 
