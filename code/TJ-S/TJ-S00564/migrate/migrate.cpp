#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],dp[3001][301],d,sum[301][301];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				sum[i][j] = 0;
				dp[i][j] = 0;
			}
		}
		for(int i = 1;i <= n;i++){
			dp[i][i] = 1;
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = i;k <= j;k++){
					if(a[k]+d >= a[j]){
						sum[i][j] = sum[i][k]+1;
						if(sum[i][j] == 1){
							dp[i][j] = 1;
						}
						break;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <=n-i;j++){
				int st = j,ed = j+i;
				for(int k = st+1;k < ed;k++){
					if(sum[st][k] + sum[k][ed] == sum[st][ed]){
						dp[st][ed] += dp[st][k]*dp[k][ed];
					}
				}if(dp[st][ed] == 2){
					ans++;
				}
			}
		}printf("%lld\n",ans);
	}
}
