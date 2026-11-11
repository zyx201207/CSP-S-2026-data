#include<bits/stdc++.h>
#define N 5010
#define int long long
using namespace std;
int n,d,c,T,ans,k,i,xa,j,len,dis[N][N],dp[N][N],x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)dis[i][j]=1e18,dp[i][j]=0;
		for(i=1;i<=n;i++)cin>>x[i];
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n&&x[j]-x[i]<=d;j++)
				dis[i][j]=1,dp[i][j]=1;
		for(len=3;len<=n;len++)
			for(i=1;i<=n-len+1;i++){
				j=i+len-1;
				for(k=i+1;k<j&&x[k]-x[i]<=d;k++){
					xa=dis[i][k]+dis[k][j];
					if(xa<dis[i][j])dis[i][j]=xa,
					dp[i][j]=dp[i][k]*dp[k][j];
					else if(xa==dis[i][j])
						dp[i][j]+=dp[i][k]*dp[k][j];
				}
			}
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(dp[i][j]==2)ans++;
		cout<<ans<<"\n";
	}
}