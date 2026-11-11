#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int inf=1e9;
int c,t,n,cnt[N],dp[N];
long long d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--){
		scanf("%d%lld",&n,&d);
		for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
		long long ans=0;
		for (int i=1;i<=n;i++){
			fill(dp+i,dp+n+1,inf);
			dp[i]=0,cnt[i]=1;
			for (int j=i;j<=n;j++){
				ans+=((j>i) && (cnt[j]==2));
				for (int k=j+1;k<=n;k++){
					if (x[k]-x[j]>d) break;
					if (dp[j]+1<dp[k]){
						dp[k]=dp[j]+1;
						cnt[k]=cnt[j];
					}else if (dp[j]+1==dp[k]) {
						if (cnt[k]+cnt[j]<=2) cnt[k]+=cnt[j];
						else cnt[k]=3;
					}
				}
			} 
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
