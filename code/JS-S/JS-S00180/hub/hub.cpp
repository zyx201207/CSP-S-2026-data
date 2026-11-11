#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=25;
vector<int> g[N];
int n,k;
int fa[N],dep[N],lian[N][N];
void dfs(int u,int f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v!=f) dfs(v,u);
	}
}
int p[N],k1,ans=1e18;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(p[i]==1){
			for(int j=i+1;j<=n;j++){
				if(p[j]==1){
					cnt+=lian[i][j];
				}
			}
		}
	}
	return cnt>=k-2;
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]) u=fa[u];
	while(u!=v) u=fa[u],v=fa[v];
	return u;
}
void dfs1(int len){
	if(len==n+1){
		if(k1==k && check()){
			int res=0;
			for(int i=1;i<=n;i++){
				int minn=1e18;
				for(int j=1;j<=n;j++){
					if(p[j]==1){
						int d=dep[i]+dep[j]-2*dep[lca(i,j)];
						minn=min(minn,d);
					}
				}
				res=max(res,minn);
			}
			ans=min(ans,res);
		}
		return ;
	}
	p[len]=0;
	dfs1(len+1);
	p[len]=1;
	k1++;
	dfs1(len+1);
	k1--;
}
void solve(){
	memset(lian,0,sizeof lian);
	ans=1e18,k1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) while(!g[i].empty()) g[i].pop_back();
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(fa[i]==j || fa[j]==i)
				lian[i][j]=lian[j][i]=1;
	dfs1(1);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
