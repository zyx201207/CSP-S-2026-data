#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k,ans,dep[N];vector<int>g[N];bool is[N],vis[N];
void dfs1(int u){
	if(vis[u]||!is[u])return;
	vis[u]=1;
	for(int v:g[u])dfs1(v);
}
bool ch(){
	for(int i=1;i<=n;i++)vis[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++)if(!vis[i]&&is[i])cnt++,dfs1(i);
	if(cnt>2)return 0;
	return 1;
}
void dfs2(int u,int fa,int d){
	dep[u]=min(dep[u],d);
	for(int v:g[u])if(v!=fa)dfs2(v,u,d+1);
}
int getans(){
	for(int i=1;i<=n;i++)dep[i]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)if(is[i])dfs2(i,0,0);
	int res=0;
	for(int i=1;i<=n;i++)res=max(res,dep[i]);
	return res;
}
void dfs(int x,int cnt){
	if(cnt>k)return;
	if(x==n+1){
		if(cnt==k&&ch())ans=min(ans,getans());
		return;
	}
	dfs(x+1,cnt),is[x]=1,dfs(x+1,cnt+1),is[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,_;scanf("%d %d",&c,&_);
	while(_--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=0x3f3f3f3f;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}