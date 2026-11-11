#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int N=100;
vector<int> p[N];
int c,T,n,k,ans,fa[N],dep[N],tr_fa[N];
bool vis[N],used[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void pfs(int u,int f){
	dep[u]=dep[f]+1;
	for(int to:p[u]){
		if(to==f) continue;
		tr_fa[to]=u;
		pfs(to,u);
	}
}
void dfschk(int u,int f){
	for(int to:p[u]){
		if(to==f) continue;
		if(used[u]&&used[to])
			fa[find(u)]=find(to);
		dfschk(to,u);
	}
}
bool check(){
	int gs=0;
	for(int i=1;i<=n;i++) gs+=used[i];
	if(gs!=k) return false;
	for(int i=1;i<=n;i++) fa[i]=i;
	dfschk(1,0);
	int res=0;
	for(int i=1;i<=n;i++)
		if(used[i]) vis[find(i)]=1;
	for(int i=1;i<=n;i++) res+=vis[i],vis[i]=0;
	return res<=2;
}
int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]) u=tr_fa[u];
	while(u!=v) u=tr_fa[u],v=tr_fa[v];
	return u;
}
int calc(){
	int res=0;
	for(int i=1;i<=n;i++){
		int r=INF;
		for(int j=1;j<=n;j++)
			if(used[j]){
				r=min(r,dep[i]+dep[j]-2*dep[LCA(i,j)]);
			}
		res=max(res,r);
	}
	return res;
}
void dfs(int x){
	if(x>n){
		if(!check()) return ;
		ans=min(ans,calc());return ;
	}
	used[x]=1;dfs(x+1);
	used[x]=0;dfs(x+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>c>>T;
	while(T--){
		memset(fa,0,sizeof(fa));memset(tr_fa,0,sizeof(tr_fa));
		memset(dep,0,sizeof(dep));
		cin>>n>>k;
		for(int i=0;i<=n;i++) p[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			p[u].push_back(v);
			p[v].push_back(u);
		}
		pfs(1,0);
		ans=INF;
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
