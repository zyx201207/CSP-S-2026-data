#include<bits/stdc++.h>
using namespace std;
const int N=1000+5;
int n,k,f[N],d[N][N],dep[N],fa[N];
bool g[N][N];
vector<int>e[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u,int p){fa[u]=p,dep[u]=dep[p]+1;for(int&v:e[u])if(v!=p)dfs(v,u);}
int get(int s){
	int cnt=0;
	for(int i=0;i<n;++i)if(s>>i&1)++cnt;
	if(cnt!=k)return 1e9;
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=n;++i)if(s>>i-1&1)
		for(int j=i+1;j<=n;++j)if(s>>j-1&1)
			if(g[i][j])f[find(i)]=find(j);
	cnt=0;for(int i=1;i<=n;++i)if((s>>i-1&1)&&f[i]==i)++cnt;
	if(cnt>2)return 1e9;
	int ans=0;
	for(int i=1;i<=n;++i)if(!(s>>i-1&1)){
		int res=1e9;
		for(int j=1;j<=n;++j)if(s>>j-1&1)res=min(res,d[i][j]);
		ans=max(ans,res);
	}
	return ans;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]=g[i][j]=0;
	for(int i=1,u,v;i<n;++i)cin>>u>>v,g[u][v]=g[v][u]=1,
		e[u].push_back(v),e[v].push_back(u);
	dfs(1,0);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
		int u=i,v=j;
		while(u!=v){
			if(dep[u]>dep[v])u=fa[u];
			else v=fa[v];
			++d[i][j];
		}
	}
	int ans=1e9;for(int s=0;s<(1<<n);++s){
		ans=min(ans,get(s));
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i)fa[i]=0,dep[i]=0,e[i].clear();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int C,T;cin>>C>>T;while(T--)solve();
	return 0;
}
