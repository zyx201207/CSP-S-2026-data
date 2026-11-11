#include <bits/stdc++.h>
using namespace std;

const int M = 5e5+10, N = 510;
int cc, n, m, d, q, k[N], a[M], t[M];
long long c[N][N], w[M];
vector<int> g[M];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &cc, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	if (12 <= cc && cc <= 19){
		long long tt;
		for (int i = 1; i <= n; i++){
			scanf("%d", &k[i]);
			for (int j = 1; j <= k[i]; j++){
				scanf("%d%d", &a[j], &t[j]);
				tt = t[j];
				g[a[j]].push_back(i);
			}
		}
		memset(c, 0x3f, sizeof c);
		for (int i = 1; i <= m; i++){
			for (auto u: g[i]){
				for (auto v: g[i]){
					if (u == v) continue;
					c[u][v] = c[v][u] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			c[i][i] = 0;
		for (int u = 1; u <= n; u++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					c[i][j] = min(c[i][u]+c[u][j], c[i][j]);
				}
			}
		}
		while (q--){
			int l, r;
			scanf("%d%d", &l, &r);
			long long ans = 9e18;
			for (auto u: g[l]){
				for (auto v: g[r]){
					ans = min(ans, 1ll*(2+2*c[u][v])*tt);
				}
			}
			printf("%lld\n", ans+w[l]+w[r]);
		}
		return 0;
	}
	memset(c, 0x3f, sizeof c);
	for (int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++){
			scanf("%d%d", &a[j], &t[j]);
		}
		for (int j = 1; j <= k[i]; j++){
			for (int u = j+1; u <= k[i]; u++){
				c[a[j]][a[u]] = c[a[u]][a[j]] = 1ll*t[j]+t[u];
			}
		}
	}
	for (int i = 1; i <= m; i++){
		c[i][i] = 0;
	}
	for (int u = 1; u <= m; u++){
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= m; j++){
				c[i][j] = min(c[i][u]+c[u][j], c[i][j]);
			}
		}
	}
	while (q--){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", 1ll*w[l]+c[l][r]+w[r]);
	}
	return 0;
}
