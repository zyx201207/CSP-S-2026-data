#include<bits/stdc++.h>
using namespace std;

int c,T;

int n,k;
vector<int> t[1005];

bool vis[1005];
vector<int> path;

bool markpath(int u,int tar){
	vis[u]=1;
	if(u==tar) return path.push_back(u),1;
	for(int v:t[u]){
		if(vis[v]) continue;
		if(markpath(v,tar)) return path.push_back(u),1;
	}
	return 0;
}

bool onpath[1005];

int dis[1005];

void dfs1(int u,int fa,int d){
	dis[u]=min(dis[u],d);
	for(int v:t[u]) if(v!=fa) dfs1(v,u,d+1);
}

int up[7][105];

void dfs2(int u,int fa){
	for(int v:t[u]){
		if(v==fa||onpath[v]) continue;
		up[0][v]=u,dfs2(v,u);
	}
}

int count(int a,int b,int mid){
	for(int u=1;u<=n;++u) vis[u]=0,onpath[u]=0;
	path.clear();
	markpath(a,b);
	for(int u:path) onpath[u]=1;
	for(int u=1;u<=n;++u) vis[u]=0,dis[u]=1e9;
	dfs1(a,0,0),dfs1(b,0,0);
	
	for(int u:path) up[0][u]=u,dfs2(u,0);
	
	for(int i=1;i<7;++i){
		for(int u=1;u<=n;++u){
			up[u][i]=up[up[u][i-1]][i-1];
		}
	} 
	
	for(int u=1;u<=n;++u){
		if(dis[u]<=mid) continue;
		if(onpath[u]) vis[u]=1;
		else{
			
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>T;
	
	while(T--){
		cin>>n>>k;
		for(int u=1;u<=n;++u) t[u].clear();
		
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			t[u].push_back(v),t[v].push_back(u);
		}
	}
	
	return 0;
}
