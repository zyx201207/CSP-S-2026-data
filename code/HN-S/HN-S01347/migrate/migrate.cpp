#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+6;
long long c,t,n,d,x[maxn],dp[maxn],m[maxn],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int k=1;k<=n;k++){
			memset(dp,0,sizeof(dp));
			memset(m,-1,sizeof(m));
			dp[k]=1;
			for(int i=k;i<=n;i++){
				for(int j=i-1;j>=k&&x[i]-x[j]<=d;j--){
					if(m[i]<0||m[i]>m[j]+1){
						m[i]=m[j]+1;
						dp[i]=dp[j];
					}
					else if(m[i]==m[j]+1){
						dp[i]+=dp[j];
					}
				}
				if(dp[i]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
