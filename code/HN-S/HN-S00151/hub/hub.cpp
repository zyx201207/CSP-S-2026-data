#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

int const N=1e6+10;
int n,k,f[N],dp[N],ans;
bool vis[N]; 
vector<int> g[N];

struct Edge{
	int u,v;
}e[N];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void unionn(int x,int y){
	x=find(x),y=find(y);
	if(x!=y) f[x]=y;
	return ;
}

int DFS(int u,int fa){
	if(vis[u]) return 0;
	if(dp[u]!=1000000000000000000) return dp[u];
	for(int v:g[u]){
		if(v==fa) continue;
		dp[u]=min(dp[u],DFS(v,u)+1);
	}
	return dp[u];
}

void dfs(int cnt){
	if(cnt==k){
		for(int i=1;i<=n;i++) f[i]=i,dp[i]=1000000000000000000;
		for(int i=1;i<n;i++){
			if(!vis[e[i].u] || !vis[e[i].v]) continue;
			unionn(e[i].u,e[i].v);
		}
		int s=0;
		for(int i=1;i<=n;i++) s+=(vis[i] && find(i)==i);
		if(s>2) return ;
		int res=0;
		for(int i=1;i<=n;i++) res=max(res,DFS(i,i));
		ans=min(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(cnt+1);
		vis[i]=0;
	}
	return ;
}

void solve(){
	cin>>n>>k;
	ans=LLONG_MAX;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		cin>>e[i].u>>e[i].v;
		g[e[i].u].push_back(e[i].v);
		g[e[i].v].push_back(e[i].u);
	}
	dfs(0);
	cout<<ans<<"\n";
	return ;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int C,T=1;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}

