#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,T,n,k,dp[N][2],ans;
vector<int>G[N];
void dfs(int u,int fa){
	if(G[u].size()==1){
		return;
	}
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		if(dp[u][0]<dp[v][0]+1){
			dp[u][1]=dp[u][0];
			dp[u][0]=dp[v][0]+1;
		}
		else if(dp[u][1]<dp[v][0]+1){
			dp[u][1]=dp[v][0]+1;
		}
	}
	ans=max(ans,dp[u][0]+dp[u][1]+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		memset(dp,0,sizeof dp);
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		G[1].emplace_back(0);
		dfs(1,0);
		if(ans>k)cout<<(((ans-k)%3==0)?((ans-k)/3):((ans-k)/3+1))<<'\n';
	}
	return 0;
}
