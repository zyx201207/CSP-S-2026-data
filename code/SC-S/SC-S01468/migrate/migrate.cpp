#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,t,mod=1e9+7;
	cin>>c>>t;
	for(ll tt=1,n,d,ans=0;tt<=t&&cin>>n>>d;tt++,ans=0){
		vector<ll> x(n+3);
		for(int i=1;i<=n;i++) cin>>x[i];
		vector<vector<ll>> dp(n+3,vector<ll>(n+3,1e18)),cnt(n+3,vector<ll>(n+3,0));
		vector<vector<unordered_set<ll>>> ways(n+3,vector<unordered_set<ll>>(n+3));
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n-l+1;i++){
				int j=i+l-1;
				if(x[j]-x[i]<=d){
					dp[i][j]=1,ways[i][j].insert(j);
					continue;
				}
				for(int k=i+1;k<j;k++){
					if(ways[i][k].size()==0||ways[i][k].size()>2
						||ways[k][j].size()==0||ways[k][j].size()>2)
						continue;
					int sum=dp[i][k]+dp[k][j];
					if(sum<dp[i][j])
						dp[i][j]=sum,ways[i][j].clear();
					if(sum==dp[i][j])
						for(ll u:ways[i][k]) for(ll v:ways[k][j])
							ways[i][j].insert(u*v%mod);
				}
				if(ways[i][j].size()==2) ans++;
				//cout<<"<"<<i<<" "<<j<<" "<<dp[i][j]<<" "<<cnt[i][j]<<">";
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}