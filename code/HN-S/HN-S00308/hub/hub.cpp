#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,T,n,k,siz[N],dis[N][N],s,fa[N];
vector<int>g[N];
bool vis[N];
pair<int,bool>dfs(int x,int fa,int mid){
	vis[x]=1;
	int dep=0;
	bool fl=0;
	for(int y:g[x])
		if(!vis[y]){
			auto g=dfs(y,x,mid);
			dep=max(dep,g.first+1),fl|=g.second;
		}
	if(dep>=mid||!fa||fl) dep=-1,s++,fl=1;
	return make_pair(dep,fl);
}
bool check1(int x,int u,int v,int mid){
	if(min(dis[x][u],dis[x][v])>mid) return 0;
	vis[x]=1;
	for(int y:g[x]) if(!vis[y]&&y!=u&&y!=v&&!check1(y,u,v,mid)) return 0;
	return 1;
}
bool check(int u,int v,int mid){
	if(u==v) return 0;
	memset(vis,0,sizeof(bool)*(n+5));
	if(!check1(dis[1][u]>dis[1][v]?fa[u]:fa[v],u,v,mid)) return 0;
	s=0,dfs(u,0,mid),dfs(v,0,mid);
	return s<=k; 
}
bool check(int mid){
	for(int u=1;u<=n;u++)
		for(int v=1;v<=n;v++)
			if(check(u,v,mid)) return 1;
	return 0;
}
void init(int x,int f){
	fa[x]=f;
	for(int y:g[x]) if(y!=f) init(y,x);
}
void Gdis(int x,int f,int dis[]){
	dis[x]=dis[f]+(f?1:0);
	for(int y:g[x]) if(y!=f) Gdis(y,x,dis);
}
int solve(){
	int l=0,r=n,mid;
	while(l<=r) mid=(l+r)>>1,check(mid)?r=mid-1:l=mid+1;
	return l;
}
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);
	}
	init(1,0);
	for(int i=1;i<=n;i++) dis[i][0]=0,Gdis(i,0,dis[i]);
	cout<<solve()<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--) Solve();
	return 0;
}/*
*/

