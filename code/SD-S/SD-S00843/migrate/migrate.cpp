#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t,a[1000010],dp[1000010];
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld",&n,&m);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
		}
		dp[1]=0;long long ans=0;
		for(int j=1;j<=n;j++){
			cout<<dp[j]<<"\n";
		}
		for(int o=1;o<=n;o++){
			for(int k=o+3;k<=n;k++){
				long long p=0;
				memset(dp,0x3f3f3f3f,sizeof(dp));
				for(int j=o;j<=k;j++){
					int p=1;
					while(a[j]-a[j-p]<=m&&j-p>0){
						p++;
					}p--;
					dp[j]=dp[j-p]+1;
				}
				for(int j=k;j>=o;j--){
					if(dp[j]==dp[k]-1&&a[k]-a[j]<=m){
						p++;
					}
				}
				if(p==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
