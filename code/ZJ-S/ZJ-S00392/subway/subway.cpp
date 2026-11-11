#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 505, M = 500;
int c, n, m, d, q;
int w[M], a[N][M], t[N][M];
LL mp[500][500];
/*
int idx = 0, h[N], ne[2100], e[2100], we[2100], vis[1005];
void add(int u, int v, int cost) {
	e[++idx] = v, we[idx] = cost, ne[idx] = h[u], h[u] = idx;
}

void dij(int st) {
	for(int i = 1; i <= m; i++) mp[st][i] = LONG_LONG_MAX, vis[i] = 0;
	mp[st][st] = 0;
	priority_queue<pair<LL, int>> q;
	q.push({0, st});
	while(!q.empty()) {
		int u = q.top().second;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u]; i; i = ne[i]) {
			int v = e[i];
			if(mp[st][v] > mp[st][u] + we[i]) {
				mp[st][v] = mp[st][u] + we[i];
				q.push({-mp[st][v], v});
			}
		}
	}
	return;
}
*/
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	if(c <= 8) {
			
		for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i][0]);
			for(int j = 1; j <= a[i][0]; j++) {
				scanf("%d %d", &a[i][j], &t[i][j]);
				for(int k = 1; k < j; k++) {
					if(mp[a[i][k]][a[i][j]] == 0) mp[a[i][k]][a[i][j]] = t[i][k] + t[i][j], mp[a[i][j]][a[i][k]] = t[i][k] + t[i][j];
					else {
						mp[a[i][k]][a[i][j]] = min(mp[a[i][k]][a[i][j]], 1LL * t[i][k] + t[i][j]);
						mp[a[i][j]][a[i][k]] = min(mp[a[i][j]][a[i][k]], 1LL * t[i][k] + t[i][j]);
					}
				}
			}
		}
		
		// Floyd: which one goes first? i, j, k?
		for(int k = 1; k <= m; k++) {
			for(int i = 1; i <= m; i++) {
				for(int j = i + 1; j <= m; j++) {
					if(j == k || i == k || mp[i][k] == 0 || mp[k][j] == 0) continue;
					if(mp[i][j] == 0) mp[i][j] = mp[i][k] + mp[k][j], mp[j][i] = mp[i][k] + mp[k][j];
					else {
						mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
						mp[j][i] = min(mp[j][i], mp[i][k] + mp[k][j]);
					}
				}
			}
		}
		
		while(q--) {
			int u, v;
			scanf("%d %d", &u, &v);
			printf("%lld\n", mp[u][v] + w[u] + w[v]);
		}
		
	}
	/*else {
		
		for(int i = 1; i <= n; i++) {
			cout << i <<":" << endl;
			scanf("%d", &a[i][0]);
			for(int j = 1; j <= a[i][0]; j++) {
				scanf("%d %d", &a[i][j], &t[i][j]);
				for(int k = 1; k < j; k++) {
					add(a[i][k], a[i][j], t[i][k] + t[i][j]);
					add(a[i][j], a[i][k], t[i][k] + t[i][j]);
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			cout << i << endl;
			dij(i);
		}
		while(q--) {
			int u, v;
			scanf("%d %d", &u, &v);
			printf("%lld\n", mp[u][v] + w[u] + w[v]);
		}
	}
	*/
 	return 0;
}
