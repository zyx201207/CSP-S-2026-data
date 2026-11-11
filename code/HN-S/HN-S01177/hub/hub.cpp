#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int c,t,n,k,mi,vis[N],dis[N],mii;
vector<int> g[N];

void dfs2(int u,int fa,int suu){
	if(vis[u]) mii=min(mii,suu);
	for(auto v:g[u]){
		if(v==fa) continue;
		dfs2(v,u,suu+1);
	}
}

void dfs1(int u,int fa){
	dis[u]=1;
	for(auto v:g[u]){
		if(v==fa || !vis[v]) continue;
		dfs1(v,u);
	}
}

void dfs(int x,int su){
	if(n-x+1+su<k) return ;
	if(su>k) return ;
	if(x==n+1){
		if(su!=k) return ;
		int sum=0;
		for(int i=1;i<=n;i++) dis[i]=0;
		for(int i=1;i<=n;i++){
			if(vis[i] && !dis[i]){
				sum++;
				if(sum>2) return ;
				dfs1(i,0);
			} 
		}
		int ma=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				mii=n-1;
				dfs2(i,0,0);
				ma=max(mii,ma);
			} 
		}
		mi=min(mi,ma);
		return ;
	}
	dfs(x+1,su);
	vis[x]=1;
	dfs(x+1,su+1);
	vis[x]=0;
}

void work(){
	cin>>n>>k;
	mi=n-1;
	for(int i=1;i<=n;i++){
		g[i].clear();
		vis[i]=0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<mi<<"\n";
	
	return ;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		work();
	}

	return 0;
}

