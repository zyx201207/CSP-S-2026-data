#include<bits/stdc++.h>
using namespace std;
int c, t, n, dis[10][10], sdis[10][10], now, ji, sum[2000001], xl, xr, lst[2000001], l, r;
long long d, x[2000001], ans;
bool vis[10], f;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
//	c = 11;
	while(t--){
		ans = 0;
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++)scanf("%lld", &x[i]);
		if(n <= 3)printf("0\n");
		else if(0 <= c && c <= 2){
			memset(dis, 0x3f, sizeof(dis));
			memset(vis, false, sizeof(vis));
			for(int k = 1; k < 1 << n; k++){
				now = 1, ji = k;
				while(ji % 2 == 0)now++, ji /= 2;
				vis[now] = !vis[now];
				l = r = ji = 0, f = true;
				for(int i = 1; i <= n; i++){
					if(vis[i]){
						ji++;
						if(l == 0)l = i;
						else if(x[i] - x[r] > d){
							f = false;
							break;
						}
						r = i;
					}
				}
				if(f && l < r){
					if(ji < dis[l][r])dis[l][r] = ji, sdis[l][r] = 1;
					else if(ji == dis[l][r])sdis[l][r]++;
				}
			}
			for(int i = 1; i < n; i++)for(int j = i + 1; j <= n; j++)if(sdis[i][j] == 2)ans++;
			printf("%lld\n", ans);
		}
		else if(11 <= c && c <= 12){
			fill(sum + 1, sum + n, 0);
			if(x[3] - x[1] > d){
				printf("0\n");
				continue;
			}
			for(int i = 3; i < n; i += 2)if((i + 1) / 2 * (x[2] - x[1]) <= d && (i + 3) / 2 * (x[2] - x[1]) > d)sum[i]++;
			for(int i = 3; i < n - 1; i++)ans += sum[i], sum[i + 1] += sum[i];
			printf("%lld\n", ans + sum[n - 1]);
		}
		else if(13 <= c && c <= 14){
			for(xl = 1; xl <= n; xl++)if(x[n] - x[xl] <= d)break;
			for(xr = n; xr >= 1; xr--)if(x[xr] - x[1] <= d)break;
			if(xl > xr)printf("The data is wrong!!!\n");
			else if(xr - xl >= 2)printf("0\n");
			else{
				r = n + 1;
				for(int i = n; i >= 1; i--){
					while(r > 1 && x[r - 1] - x[i] > d)r--;
					lst[i] = r;
				}
				if(xr - xl == 1){
					for(int i = 1; i < xl; i++){
						if(lst[i] == xr){
							ans += n - lst[xl - 1];
						}
					}
				}
				else{
					for(int i = 1; i < xl; i++){
						ji = lst[i] - 1;
						if(ji <= xr)while(ji >= xl)ji--;
						ans += lst[lst[i]] - lst[ji];
					}
				}
				printf("%lld\n", ans);
			}
		}
		else printf("0\n");
	}
	return 0;
}
