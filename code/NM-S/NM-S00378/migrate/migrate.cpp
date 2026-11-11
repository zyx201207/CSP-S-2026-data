#include<bits/stdc++.h>
using namespace std;
long long a[2000100];
int dis[2000100],dp[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,i,j,k;
		long long ans=0,d;
		cin>>n>>d;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) dis[j]=0x3f3f3f3f,dp[j]=0;
			dp[i]=1;dis[i]=0;
			for(j=i;j<=n;j++){
				for(k=j-1;k>=i&&a[j]-a[k]<=d;k--){
					if(dp[k]&&dis[k]+1<dis[j]) dis[j]=dis[k]+1,dp[j]=dp[k];
					else if(dp[k]&&dis[k]+1==dis[j]) dp[j]=min(3,dp[k]+dp[j]);
				}
				if(dp[j]==2) ans++;
			}
//			for(j=1;j<=n;j++) cout<<dp[j]<<' ';
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
