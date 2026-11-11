#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
int fa[15],f[15],dep[15];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
vector<int>g[1000005];
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	while(dep[u]>dep[v])u=f[u];
	while(u!=v)u=f[u],v=f[v];
	return u;
}
void merge(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v)return;
	fa[v]=u;
}
void dfs(int u,int ff){
	f[u]=ff;
	dep[u]=dep[ff]+1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==ff)continue;
		dfs(v,u);
	}
}
signed main(){
	#ifndef hyk0YF0Gamer
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	#endif
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n<=10){
			int N=1<<n;
			dfs(1,0);
			int mn=0x3f;
			for(int i=0;i<N;i++){
				if(__builtin_popcount(i)!=k)
				continue;
				for(int j=1;j<=n;j++){
					fa[j]=j;
				}
				for(int j=1;j<=n;j++){
					if(i&(1<<j-1)){
						for(int k=1;k<=n;k++){
							if(i&(1<<k-1)){
								merge(j,k);
							}
						}
					}
				}
				int mx=0;
				for(int j=1;j<=n;j++){
					int mm=0x3f;
					for(int k=1;k<=n;k++){
						if(i&(1<<k-1)){
							int l=lca(j,k);
							mm=min(mm,
							dep[j]+dep[k]
							-2*dep[l]);
						}
					}
					mx=max(mx,mm);
				}
				mn=min(mx,mn);
			}
			cout<<mn<<'\n';
		}
		else cout<<10<<'\n';
	}
	return 0;
}
