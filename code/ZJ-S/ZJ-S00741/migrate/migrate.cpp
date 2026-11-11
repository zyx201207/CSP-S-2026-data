#include<bits/stdc++.h>
using namespace std;
int c,T,n,dp[5005][5005],g[5005][5005];
int hea;
long long d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++) dp[i][i]=1;
		for(int i=1;i<=n;i++) g[i][i]=0;
		for(int i=1;i<=n;i++){
			hea=i;
			for(int j=i+1;j<=n;j++){
				while(x[j]-x[hea]>d) hea++;
				g[i][j]=g[i][hea]+1;
			}
		}
		for(int i=1;i<=n;i++){
			int sum=dp[i][i],hea=i,tai=i+1;
			for(int j=i+1;j<=n;j++){
				while(tai<j&&g[i][j]==g[i][tai]+1){
					sum+=dp[i][tai];
					tai++;
				}
				while(hea<tai&&x[j]-x[hea]>d){
					sum-=dp[i][hea];
					hea++;
				}
				dp[i][j]=sum;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dp[i][j]==2) ans++;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dp[i][j]=g[i][j]=0;
	}
	return 0;
}