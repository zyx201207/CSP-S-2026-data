#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int fa[N],dist[N][N],n,k,ans;
bool vis[N];
vector<int>g[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void dfs(int x,int fa){
	dist[x][x]=0;
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(v==fa) continue;
		dist[x][v]=dist[v][x]=1;
		dfs(v,x);
	}
}
int work(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		for(int j=0;j<g[i].size();j++){
			int v=g[i][j];
			if(!vis[v]) continue;
			int tu=find(i),tv=find(v);
			fa[tv]=tu;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		if(fa[i]==i) sum++;
		if(sum>2) return 2e9;
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int minn=2e9;
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			minn=min(minn,dist[i][j]);
		}
		maxx=max(maxx,minn);
	}
	return maxx;
}
void dfs1(int x,int sy){
	if(x>n){
		if(sy) return;
//		for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
//		cout<<":"<<work()<<"\n"; 
		ans=min(ans,work());
		return;
	}
	if((n-x+1)>sy) dfs1(x+1,sy);
	vis[x]=1;
	dfs1(x+1,sy-1);
	vis[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(dist,0x3f,sizeof(dist));
		dfs(1,-1);
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		ans=2e9;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++) cout<<dist[i][j]<<" ";
//			cout<<"\n";
//		}
		dfs1(1,k);
		cout<<ans<<"\n";
	}
	return 0;
}