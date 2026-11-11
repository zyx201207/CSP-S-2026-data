#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1010;
const int INF=1e9;
int c,n,m,d,q;
int idx;
int w[N],sum[N],f[N][22],dep[N];
struct node{
	int v,w;
};
vector<node> g[N];
void add(int u,int v,int w){
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i].v;
		if(v==fa) continue;
		sum[v]=sum[u]+g[u][i].w;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(dep[f[u][i]]>=dep[v]){
			u=f[u][i];
		}
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i],v=f[v][i];
		}
	}
	return f[u][0];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	idx=n+m;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		int a,t;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			add(a,n+i,t);
		}
	}	
	dfs(1,0);
	while(q--){
		int u,v;
		cin>>u>>v;
		int lc=lca(u,v);
		cout<<sum[u]+sum[v]-2*sum[lc]+w[u]+w[v]<<'\n';
	}
}


