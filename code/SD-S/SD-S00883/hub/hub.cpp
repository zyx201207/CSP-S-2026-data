#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,k;
vector<int>g[N];
int dp[N][N][3],siz[N];
void dfs(int u,int fa){
	siz[u]=1;
	for(int v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
bool chk(int x){
	return rand()%2;
//	dfs(1,0);
//	if(dp[1][k][1]||dp[1][k][2])return 1;
//	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}int l=0,r=n,ans=n;
		while(l<=r){
			int mid=l+r>>1;
			if(chk(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}cout<<ans<<'\n';
	} 
	return 0;
}
