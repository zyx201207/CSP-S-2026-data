#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200005],ans;
long long dp[1005][1005],v1[1005][1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		memset(v1,0,sizeof(v1));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		dp[i][j]=1e9;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		dp[i][i]=0;
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(dp[i][j+1]>dp[i][j]+1){
				dp[i][j+1]=dp[i][j]+1;
				v1[i][j+1]=0;
			}
			else if(dp[i][j+1]==dp[i][j]+1)
			v1[i][j+1]++;
			for(int v=j+2;v<=n && a[j]+d>=a[v];v++){
				if(dp[i][v]<dp[i][j]+1)
				continue;
				else if(dp[i][v]>dp[i][j]+1){
					dp[i][v]=dp[i][j]+1;
					v1[i][v]=0;
				}
				else
				v1[i][v]++;
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(v1[i][j]==1)
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}
