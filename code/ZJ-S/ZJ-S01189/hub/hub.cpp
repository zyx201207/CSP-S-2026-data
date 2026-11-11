#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 2000001
int c,t,n,k,u,v;
int vis[maxn];
int ans=LLONG_MAX;
int fa[maxn];
int dis[maxn];
int cnt;
vector<int>e[maxn];
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
int anss;
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	fa[xx]=yy;
	cnt++;
	return;
}
void bfs(int x,int fa,int d){
	dis[x]=d;
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]==fa)continue;
		bfs(e[x][i],x,d+1);
	}
	return;
}
void checkans(){
	anss=0;
	for(int i=1;i<=n;i++){
		bfs(i,i,0);
		int yy=LLONG_MAX;
		for(int j=1;j<=n;j++){
			if(vis[j])yy=min(yy,dis[j]);
		}
		anss=max(anss,yy);
	}
	ans=min(ans,anss);
	return;
}
void check(){
	cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			for(int j=0;j<e[i].size();j++){
				if(vis[e[i][j]]&&find(i)!=find(e[i][j]))merge(e[i][j],i);
			}
		}
	}
	if(cnt==k-1||cnt==k-2){
		checkans();
	}
	return;
}
void dfs(int step,int kk){
	if(step==n+1){
		check();
	}
	else{
		vis[step]=1; dfs(step+1,kk+1);
		vis[step]=0; dfs(step+1,kk);
	}
}
void solve(){
	scanf("%lld%lld",&n,&k);
	ans=LLONG_MAX;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<=n-1;i++){
		scanf("%lld%lld",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)solve();	
	return 0;
}