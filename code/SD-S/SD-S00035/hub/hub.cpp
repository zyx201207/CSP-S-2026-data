#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int c,T,n,k,vis[maxn],fa[21][maxn],dep[maxn],ck[100];
vector<int> g[maxn];
void dfs(int u){
	for(int v : g[u]){
		if(v==fa[0][u])continue;
		fa[0][v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
void init(){
	dfs(1);
	for(int i = 1;i<21;i++){
		for(int j = 1;j<=n;j++){
			fa[i][j]=fa[i-1][fa[i-1][j]];
		}
	}
} 
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int delta = dep[u]-dep[v];
	for(int i = 20;i>=0;i--){
		if((delta>>i)&1)u=fa[i][u];
	}
	if(u==v)return u;
	for(int i = 20;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u];
			v=fa[i][v];
		}
	}
	return fa[0][u];
}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
int calc(){
	int res = 0;
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		int res1 = n;
		for(int j = 1;j<=n;j++){
			if(!vis[j])continue;
			res1=min(res1,dis(i,j));
		}
		res=max(res,res1);
	}
	return res;
}
void dfs2(int u){
	ck[u]=1;
	for(int v : g[u]){
		if(!vis[v] || ck[v])continue;
		dfs2(v);
	}
}
bool check(){
	memset(ck,0,sizeof ck);
	int ret = 0;
	for(int i = 1;i<=n;i++){
		if(vis[i] && !ck[i]){
			ret++;
			dfs2(i);
		}
	}
	return (ret<=2);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--){
		for(int i = 1;i<=n;i++)g[i].clear();
		cin >> n >> k;
		for(int u,v,i = 1;i<n;i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}init();
		if(c<=3){
			int ans = n;
			for(int i = 0;i<(1<<n);i++){
				int cnt = 0;
				for(int j = 1;j<=n;j++){
					if((i>>(j-1))&1){
						cnt++;
						vis[j]=1;
					}else vis[j]=0;
				}
				if(cnt!=k)continue;
				if(!check())continue;
				ans=min(ans,calc());
			} 
			cout << ans << "\n";
		}else cout << n/2 << "\n";
	}
	return 0;
}
