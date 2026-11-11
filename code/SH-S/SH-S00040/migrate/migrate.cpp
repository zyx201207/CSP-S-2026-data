#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000001],k[2000001],dp[5001][5001],anss;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		anss=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			k[i]=i;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) k[i]=max(k[i],j); 
				dp[i][j]=0;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				int ans=1e18,mx=0;
				for(int l=i+1;l<=k[i];l++){
					if(l>j) break;
					if(dp[l][j]==ans) mx++;
					else if(dp[l][j]<ans) mx=1;
					ans=min(ans,dp[l][j]);
				}
				if(ans>=1e18){
					dp[i][j]=1e18;
					continue;
				}
				dp[i][j]=ans+1;
				if(mx==2) anss++;
			}
		}
		cout<<anss<<"\n";
	}
	return 0;
}
