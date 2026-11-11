//SN-S00531 张之奇 西安市铁一中学
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
const int inf=1e9;
int cas;
int n,k;
int vis[maxn],t[maxn];
vector<int> G[maxn];

void dfs(int u,int fa){
	vis[u]=1;
	for (int v:G[u]){
		if (vis[v]||!t[v])	continue;
		dfs(v,u);
	}
}

namespace LCA{
	int fa[maxn][21],dep[maxn];
	
	void dfs(int u,int f){
		fa[u][0]=f; dep[u]=dep[f]+1;
		for (int i=1;i<=20;i++)	fa[u][i]=fa[fa[u][i-1]][i-1];
		for (int v:G[u]){
			if (v==f)	continue;
			dfs(v,u);
		}
	}
	
	int lca(int u,int v){
		if (u==v)	return u;
		if (dep[u]<=dep[v])	swap(u,v);
		for (int i=20;i>=0;i--){
			if (dep[fa[u][i]]>=dep[v])	u=fa[u][i];
		}
		if (u==v)	return u;
		for (int i=20;i>=0;i--){
			if (fa[u][i]!=fa[v][i])	u=fa[u][i],v=fa[v][i];
		}
		return fa[u][0];
	}
}

void solve(){
	cin>>n>>k;
	for (int i=1;i<=n-1;i++){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=inf;
	for (int sta=0;sta<(1<<n);sta++){
		for (int i=1;i<=n;i++)	vis[i]=0,t[i]=((sta&(1<<(i-1)))!=0);
		int cnt=0;
		for (int i=1;i<=n;i++) if (vis[i]==0&&t[i])	dfs(i),cnt++;
		if (cnt>=3)	continue;
		int tot=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				
			}
		}
	}
	cout<<ans;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;for (cin>>cas>>T;T--;)
	solve();
	return 0;
} 
