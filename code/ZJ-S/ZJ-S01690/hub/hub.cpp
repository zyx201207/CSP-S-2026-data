#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
vector<int> e[N];
int f[N],mx[N];
void dfs(int u,int fa){
	f[u]=0;
	mx[u]=1;
	for(int v:e[u]) if(v!=fa){
		dfs(v,u);
		f[u]=max(f[u],mx[u]+mx[v]);
		mx[u]=max(mx[u],mx[v]);
	}
}
bool vis[N],is[N];
int dis[N];
void dfs1(int u,int fa){
	dis[u]=min(dis[u],dis[fa]+1);
	for(int v:e[u]) if(v!=fa){
		dfs1(v,u);
	}
}
void dfs2(int u,int fa){
	if(!is[u]) return;
	vis[u]=1;
	for(int v:e[u]) if(v!=fa){
		dfs2(v,u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(k==2){
		int ans=n;
		for(int i=1;i<=n;i++){
			int mx=0;
			dfs(i,0);
			for(int v:e[i]) mx=max(mx,f[v]);
			ans=min(ans,mx/2);
		}
		cout<<ans<<"\n";
		return;
	}
	int ans=n;
	for(int s=0;s<(1<<n);s++){
		if(__builtin_popcount(s)!=k) continue;
		for(int i=1;i<=n;i++){
			if((s>>i-1)&1) dis[i]=0,is[i]=1;
			else dis[i]=n,is[i]=0;
			vis[i]=0;
		}
		int cnt=0;
		for(int i=1;i<=n;i++) if((s>>i-1)&1) if(!vis[i]) dfs2(i,0),cnt++;
		if(cnt>2) continue;
		for(int i=1;i<=n;i++){
			if((s>>i-1)&1) dfs1(i,0);
		}
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}