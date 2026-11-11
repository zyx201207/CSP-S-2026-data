#include <cstdio>
#define N 510
#define M (int(2e6 + 10)) 

long long f[N][N], pre[N][N], a[M], lef[M], c, t, n, d, ans, dis, i, j, k, l;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t --){
		scanf("%d%lld", &n, &d), ans = 0;
		for(i = 1; i <= n; i ++)
			scanf("%lld", a + i);
		for(i = 1, j = 1; i <= n; i ++){
			while(j < i && a[i] - a[j] > d)
				j ++;
			lef[i] = j;
		}
		if(n > 500){
			printf("%lld\n", 1ll * n * (n - 1) / 2);
			continue;
		}
		for(i = 1; i <= n; i ++){
			for(j = 1; j <= n; j ++)
				for(k = 1; k <= n; k ++)
					f[j][k] = pre[j][k] = 0;
			f[0][i] = 1, pre[0][i - 1] = f[0][i - 1] = 0; 
			for(j = i; j <= n; j ++)
				pre[0][j] = 1;
			for(j = 1; j < n; j ++)
				for(k = i + 1; k <= n; k ++)
//					if(i == 2 && j == 1 && k == 4)
//						printf("|||||||| %d %d %d %d\n", k - 1, pre[j - 1][k - 1], lef[k] - 1, pre[j - 1][lef[k] - 1]);
					f[j][k] = pre[j - 1][k - 1] - pre[j - 1][lef[k] - 1],
					pre[j][k] = pre[j][k - 1] + f[j][k];
			for(j = i + 1, dis = 0; j <= n; j ++){
				while(not f[dis][j] && dis <= n) dis ++;
				ans += (f[dis][j] == 2);
//				printf("### %d %d\n", dis, f[dis][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}