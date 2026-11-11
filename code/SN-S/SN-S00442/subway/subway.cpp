//齐君豪 西安市含光中学 SN-S00442
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n, m, d, Q;
int w[500010];
int vis[25000000];
ll dist[25000000];
vector<pair<int, int>> edge[25000000];

void dij(int s) {
	for(int i = 1; i <= m * n + m; i++)
		dist[i] = 1e18, vis[i] = 0;
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(auto &it : edge[x]) {
			int y = it.first, z = it.second;
			if(vis[y]) continue;
			if(dist[x] + z < dist[y]) {
				dist[y] = dist[x] + z;
				q.push({dist[y], y});
			}
		}
	}
}

void solve() {
	scanf("%d%d%d%d", &n, &m, &d, &Q);
	for(int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for(int i = 1, k; i <= n; i++) {
		scanf("%d", &k);
		int lst_a = 0;
		for(int j = 1, a, t; j <= k; j++) {
			scanf("%d%d", &a, &t);
			edge[a].push_back({a + i * m, t});
			edge[a + i * m].push_back({a, t});
			if(j > 1) {
				edge[a + i * m].push_back({lst_a + i * m, 0});
				edge[lst_a + i * m].push_back({a + i * m, 0});
			}
			lst_a = a;
		}
	}
	while(Q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		dij(u);
		printf("%lld\n", dist[v] + (ll)w[u] + (ll)w[v]);
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d", &T);
	return 0;
} 
