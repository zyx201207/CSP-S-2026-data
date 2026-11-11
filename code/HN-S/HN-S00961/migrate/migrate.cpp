#include<bits/stdc++.h>
using namespace std;
long long d,a[2000005],b[2000005],dp[2000005];
int c,t,n,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=n;i>=2;i--)b[i]=a[i]-a[i-1];
		for(int i=1;i<n;i++){
			memset(dp,0,sizeof(dp));
			int k=i+1;b[i]=0;
			while(d+a[i]-a[k]>=0&&k+1<=n)k++;
			int l=k;
			for(;l<=n;l++){
				for(int j=i+1;j<k;j++){
					if(dp[l-1]==0){
						dp[l]+=b[j];
					}else{
						dp[l]+=dp[l-1];
					}
				}
			}
			if(dp[n]==1)break;
			for(int j=k;j<=n;j++)if(dp[j]==2)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
