#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int k[510], a[510][500010], t[510][500010], x[100010], y[100010];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	int w[n];
	int G[500010][2000];
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%d %d", &a[i][j], &t[i][j]);
		}
		for(int j = 1; j <= k[i] - 1; j++){
			G[a[i][j]][a[i][j - 1]] = 1;
			G[a[i][j - 1]][a[i][j]] = 1;
		}
	}
	for(int i = 1; i <= q; i++){
		scanf("%d %d", &x[i], &y[i]);
		int ans = 0;
		bool f = 0;
		for(int j = 1; j <= n; j++){
			if(G[x[i]][j] == 1){
				f = 1;
				ans += t[x[i]][j];
				ans += w[a[x[i]][j]];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
