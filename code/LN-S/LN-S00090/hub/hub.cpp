#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,siz[300005],wei[300005],dis[300005];
vector<int> g[300005];int cen,ans;
void dfs(int u,int fa){
	dis[u]=dis[fa]+1;
	ans=max(ans,dis[u]);
	siz[u]=1;wei[u]=0;
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		wei[u]=max(wei[u],siz[v]);
	}
	wei[u]=max(wei[u],n-siz[u]);
	if(wei[u]<wei[cen])cen=u;
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		wei[cen=0]=INT_MAX;
		dfs(1,0);ans=0;
		dis[0]=-1;
		dfs(cen,0);
		cout<<ans<<'\n';
	}
	return 0;
}
