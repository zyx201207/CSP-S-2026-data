#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,m;
	cin>>n>>m;
	int a[n+100]={};
	vector<int> v[n+100];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=m)v[i].push_back(j);
		}
	}
	int dp[n+100]={};
	dp[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			dp[v[i][j]]+=dp[i];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[j]-dp[i]==2)ans++;
			
		}
	}
	cout<<ans-1<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
}
