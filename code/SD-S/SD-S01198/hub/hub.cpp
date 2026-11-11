#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,t;
int n,k;
vector<int>g[N];
int dist[N];
int dep[N];
vector<int>v;
int fa[N];
bool flag[N][N];
bool f[N];
int st[4][N];
int ans=2e9;
void init(){
	for(int i=1;i<4;i++){
		for(int j=1;j<=n;j++){
			st[i][j]=st[i-1][st[i-1][j]];
		}
	}
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	st[0][u]=fa;
	for(auto t:g[u]){
		if(t==fa) continue;
		dist[t]=dist[u]+1;
		dfs(t,u);
	}
}
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int cnt=dep[u]-dep[v];
	for(int i=0;i<4;i++){
		if((cnt>>i)&1) u=st[i][u];
	}
	if(u==v) return u;
	for(int i=3;i>0;i--){
		if(st[i][u]!=st[i][v]){
			u=st[i][u];
			v=st[i][v];
		}
	}
	return st[0][u];
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		flag[u][v]=flag[v][u]=1;
	}
	dfs(1,0);
	init();
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i>>j)&1) v.push_back(j+1);
		}
		int s=v.size();
		if(s!=k){
			v.clear();
			continue;
		}
		for(auto tt:v){
			for(auto t2:v){
				if(tt==t2) continue;
				else if(flag[tt][t2]){
					if(tt<t2) fa[tt]=t2;
					else fa[t2]=tt;
				}
			}
		}
		set<int>sett;
		for(auto tt:v) sett.insert(find(tt));
		s=sett.size();
		if(s>2){
			v.clear();
			for(int j=1;j<=n;j++) fa[j]=j;
			continue;
		}
		for(auto tt:v) f[tt]=1;
		int mx=-2e9;
		for(int j=1;j<=n;j++){
			if(f[j]) continue;
			int mx2=2e9;
			for(auto tt:v){
				int d=dist[j]+dist[tt]-2*dist[lca(j,tt)];
				mx2=min(mx2,d);
			}
			mx=max(mx,mx2);
		}
		for(auto tt:v) f[tt]=0;
		ans=min(ans,mx);
		v.clear();
		for(int j=1;j<=n;j++) fa[j]=j;
	}
	cout<<ans<<'\n';
	ans=2e9;
	for(int i=0;i<4;i++){
		for(int j=1;j<=n;j++) st[i][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) flag[i][j]=0;
		g[i].clear();
		dep[i]=0;
		dist[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
