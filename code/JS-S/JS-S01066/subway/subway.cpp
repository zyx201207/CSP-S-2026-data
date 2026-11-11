#include <bits/stdc++.h>
#define ll long long
const int C = 25;
const int N = 510;
const int M = 5e5 + 10;
const int D = 30;
const int Q = 1e5 + 10;
using namespace std;

int c, n, m, d, q;
ll w[M], dis[N][N];
vector <int> a[M];
vector <ll> t[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for(int i = 1; i <= n; i++) {
		int k, aa;
		ll tt;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++) {
			scanf("%d %lld", &aa, &tt);
			a[aa].push_back(i);
			t[aa].push_back(tt);
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i != j) dis[i][j] = 1e17;
			else dis[i][j] = 0; 
		}
	}

	for(int i = 1; i <= m; i++) {
		int len = a[i].size();
		for(int j = 0; j < len - 1; j++) {
			for(int k = j + 1; k < len; k++) {
				int u = a[i][j], v = a[i][k];
				ll co = t[i][j] + t[i][k];
				dis[u][v] = min(dis[u][v], co);
				dis[v][u] = min(dis[v][u], co);
			}
		}
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	while(q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		
		int alen = a[x].size(), blen = a[y].size();
		ll ans = 1e17;

		for(int i = 0; i < alen; i++) {
			for(int j = 0; j < blen; j++) {
				ans = min(ans, t[x][i] + t[y][j] + dis[a[x][i]][a[y][j]]);
			}
		}

		printf("%lld\n", ans + w[x] + w[y]);
	}

	return 0;
}
