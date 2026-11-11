#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int n,k,dep[N],fa[N][27],a[N],ans=(int)4e18;
bool vis[N];
vector<int> g[N];
void dfs(int x,int p){
	dep[x]=dep[p]+1,fa[x][0]=p;
	for(int i=1;i<=26;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int y:g[x]){
		if(y!=p) dfs(y,x);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=26;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	}
	if(u==v) return u;
	for(int i=26;i>=0;i--){
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
int len(int u,int v){
	return dep[u]+dep[v]-dep[lca(u,v)];
}
void dfs2(int step){
	if(step>k){
		int maxn=0;
		for(int p=1;p<=n;p++){
			int minn=4e18;
			for(int i=1;i<=k;i++){
				minn=min(minn,len(p,a[i]));
			}
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[step]=i;
		vis[i]=true;
		dfs2(step+1);
		vis[i]=false;
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(dep,0,sizeof(dep));
	memset(fa,0,sizeof(fa));
	dfs(1,0);
	ans=4e18;
	memset(vis,false,sizeof(vis));
	dfs2(1);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}
