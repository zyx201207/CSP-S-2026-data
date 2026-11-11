#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int d,n;
	cin>>n>>d;
	vector<int>a(n+2);
	vector<vector<int>>jl(n+1,vector<int>(n+1,1e18));
	vector<vector<int>>dp(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int u=i;
		for(int j=i-1;j>=1;j--)
			if(a[i]-a[j]<=d)jl[j][i]=1,u=j,dp[j][i]=1;
		else jl[j][i]=min(jl[j][i],jl[j][u]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			for(int k=i+1;k<=j-1;k++){
				if(a[j]-a[k]<=d&&jl[i][k]+1==jl[i][j]){
					dp[i][j]+=dp[i][k];
				}
			}
		}
	}int ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=(dp[i][j]==2);
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--)solve();
	return 0;
	return 0;
}





