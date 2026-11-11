#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[5010],sum[5010],dp[5010],ans = 0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		ans = 0;
		scanf("%lld %lld",&n,&d);
		for(int i = 1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i = 1;i<n;i++){
			for(int j = i+1;j<=n;j++) dp[j] = 1e18,sum[j] = 0;
			sum[i] = 1,dp[i] = 0;
			for(int j = i+1;j<=n;j++){
				for(int k = j-1;k>=i;k--){
					if(a[j]-a[k]>d) break;
					if(dp[k]+1<dp[j]) dp[j] = dp[k]+1,sum[j] = sum[k];
					else{
						if(dp[k]+1==dp[j]) sum[j]+=sum[k];
					}
				}
				if(sum[j]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
