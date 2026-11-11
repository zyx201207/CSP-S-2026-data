#include <bits/stdc++.h>
#define int long long
#define pc __builtin__popcountll
#define PII pair<long long,long long>
#define fi first
#define se second
using namespace std;
const int N=2e6+10;
const int INF=1e18;
int n,k,ans,res,co[N],dis[N];
vector<int>g[N];
vector<PII>es;
struct DSU{
	int n;vector<int>fa;
	DSU(int nn){
		n=nn;fa.resize(n+1);
		for(int i=0;i<=n;i++) fa[i]=i;
	}
	int Find(int x){
		return fa[x]==x?x:fa[x]=Find(fa[x]);
	}
	void Union(int x,int y){
		x=Find(x),y=Find(y);
		if(x==y) return;
		fa[x]=y;
	}
};
bool check(){
	DSU ds(n);
	for(auto xx:es){
		int u=xx.fi,v=xx.se;
		if(co[u]&&co[v]){
			ds.Union(u,v);
		}
	}
	set<int>s;
	for(int i=1;i<=n;i++){
		if(!co[i]) continue;
		s.insert(ds.Find(i));
	}
	return s.size()<=2;
}
void dfs1(int u,int fa){
	dis[u]=INF;
	if(co[u]) dis[u]=0;
	for(int v:g[u]){
		if(v==fa) continue;
		dfs1(v,u);
		dis[u]=min(dis[u],dis[v]+1);
	}
}
void dfs(int u,int fa,int d){
	vector<int>pre(g[u].size()+3,INF);
	vector<int>suf(g[u].size()+3,INF);
	int cnt=0;
	for(int i=1;i<=g[u].size();i++){
		if(g[u][i-1]==fa) continue;
		cnt++;
		pre[cnt]=suf[cnt]=dis[g[u][i-1]]+1;
	}
	for(int i=1;i<=cnt;i++){
		pre[i]=min(pre[i-1],pre[i]);
	}
	for(int i=cnt;i>=1;i--){
		suf[i]=min(suf[i+1],suf[i]);
	}
	res=max(res,min(d,dis[u]));
	cnt=0;
	for(int i=1;i<=g[u].size();i++){
		if(g[u][i-1]==fa) continue;
		cnt++;
		int val=min({pre[cnt-1],suf[cnt+1],d});
		if(co[u]) val=0;
		dfs(g[u][i-1],u,val+1);
	}
}
void bfs(int x,int num){
	if(x==n+1){
		if(num!=k) return;
		if(!check()) return;
		res=0;
		dfs1(1,0);dfs(1,0,INF);
		ans=min(ans,res);
		return;
	}
	co[x]=0;bfs(x+1,num);
	co[x]=1;bfs(x+1,num+1);
}
void solve(){
	cin>>n>>k;
	es.clear();
	for(int i=1;i<=n;i++) g[i].clear();
	ans=res=0;
	for(int i=1;i<=n;i++) co[i]=dis[i]=0;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		es.push_back({u,v});
	}
	ans=INF;bfs(1,0);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int cid,T;cin>>cid>>T;
	while(T--) solve();
	return 0;
}
