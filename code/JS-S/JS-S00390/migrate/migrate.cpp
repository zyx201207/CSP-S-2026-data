//miao miao miao
#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10,INF=0x3f3f3f3f;
int c,T,n,dp[N][N],cnt[N][N],ans,nd[N];
long long d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dp[i][j]=INF;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)dp[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++)dp[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					if(k<i||k>j)continue;
					if(dp[i][k]+dp[k][j]<dp[i][j])dp[i][j]=dp[i][k]+dp[k][j],cnt[i][j]=0;
					else if(dp[i][k]+dp[k][j]==dp[i][j]){
						cnt[i][j]++;
						if(cnt[i][j]==2)ans++;
						if(cnt[i][j]==3)ans--;
					}
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=cnt[i][j]=0;
			}
		}
		ans=0;
	}
	return 0;
}
