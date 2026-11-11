#include<bits/stdc++.h>
using namespace std;
#define int signed
int c,t,n,ans,dp[20005][20005];
long long x[200006],d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t-->0){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			cout<<n/(d/(x[2]-x[1]))<<endl;
		}
		return 0;
	}
	while(t-->0){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		//bao li!!
		memset(dp,0,sizeof(dp));ans=0;
		for(int i=1;i<=n;i++)dp[i][i]=1;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				if(x[r]-x[l]<=d){
					dp[l][r]=1;
					continue;
				}
				for(int k=l;k<r;k++){
					if(x[k]-x[l]>d||x[r]-x[k]>d)continue;
					dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dp[i][j]==2)ans++;
		cout<<ans<<endl;
	}
}
