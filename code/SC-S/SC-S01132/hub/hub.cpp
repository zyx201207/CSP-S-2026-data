#include <iostream>
#include <cstring>
using namespace std;
const int man=2e6+10;
int head[man],node,deep[man],siz[man],son[man],top[man],f[man],n,k,fa[man],vis[man],ans[man],res;
struct Edge{
	int v,pre;
}edge[man<<1];
void adge(int u,int v){
	edge[++node].v=v;
	edge[node].pre=head[u];
	head[u]=node;
}
void dfs(int u,int fa){
	siz[u]=1;
	deep[u]=deep[fa]+1;
	f[u]=fa;
	for(int i=head[u];i;i=edge[i].pre){
		int v=edge[i].v;
		if(v!=fa){
			dfs(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v])son[u]=v;
		}
	}
}
void dfd(int u,int t){
	top[u]=t;
	if(son[u])dfd(son[u],t);
	for(int i=head[u];i;i=edge[i].pre){
		int v=edge[i].v;
		if(v!=f[u]&&v!=son[u]){
			dfs(v,v);
		}
	}
}
int lca(int a,int b){
	while(top[a]!=top[b]){
		if(deep[top[a]]<deep[top[b]])swap(a,b);
		a=f[top[a]];
	}
	return deep[a]<deep[b]?a:b;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dff(int f,int got){
	if(got==k){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=k;i++){
			for(int j=head[ans[i]];j;j=edge[j].pre){
				int v=edge[j].v;
				if(vis[v]){
					fa[find(ans[i])]=find(v);
				}
			}
		}
		int a=0,b=0;
		for(int i=1;i<=k;i++){
			if(!a)a=find(ans[i]);
			else if(!b&&find(ans[i])!=a)b=find(ans[i]);
			else if(find(ans[i])!=a&&find(ans[i])!=b)return;
		}
		int dis=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			int trdis=0x3f3f3f3f;
			for(int j=1;j<=k;j++){
				trdis=min(trdis,deep[i]+deep[ans[j]]-2*deep[lca(i,ans[j])]);
			}
			dis=max(dis,trdis);
		}
		res=min(res,dis);
		return;
	}
	if(f==n+1)return;
	dff(f+1,got);
	ans[got+1]=f;
	vis[f]=1;
	dff(f+1,got+1);
	vis[f]=0;
}
void solve(){
	memset(head,0,sizeof head);
	node=0;
	int u,v;
	res=0x3f3f3f3f;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		adge(u,v);
		adge(v,u);
	}
	dfs(1,0);
	dfd(1,1);
	dff(1,0);
	cout<<res;
}
int main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}