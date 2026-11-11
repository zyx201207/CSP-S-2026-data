#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,head[1000010],ver[1000010],tot,nxt[1000010],dep[1000010],siz[1000010],fa[1000010],son[1000010],top[1000010];
void dfs1(int u,int f){
	dep[u]=dep[f]+1,fa[u]=f,siz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(v==f)  continue;
		dfs1(v,u);
		if(siz[v]>siz[son[u]])  son[u]=v;
		siz[u]+=siz[v];
	}
}
void dfs2(int u,int p){
	top[u]=p;
	if(son[u])  dfs2(son[u],p);
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(v==fa[u]||v==son[u])  continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	while(dep[top[u]]!=dep[top[v]]){
		if(dep[fa[u]]<dep[fa[v]])  swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])  return v;
	return u;
}
void add(int u,int v){
	ver[++tot]=v,nxt[tot]=head[u],head[u]=tot;
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			add(u,v),add(v,u);
		}
	}
	dfs1(1,0);
	dfs2(1,1);
	while(1){}
	return 0;
}
