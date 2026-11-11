#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define MAXN 10005
const int INF=1e18;
int c,t;
int n,k;
vector<int> g[MAXN];
bool vis[MAXN];
int sz,cc[MAXN];
int f[MAXN];
int d[MAXN];
int dd[MAXN];
void dfs(int u,int fa)
{
	vis[u]=1;
	for(int v:g[u])
	{
		if(v!=fa&&!vis[v]) dfs(v,u);
	}
}
void build(int u,int fa)
{
	f[u]=fa;
	d[u]=d[fa]+1;
	for(int v:g[u])
	{
		if(v!=fa) build(v,u);
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
	while(d[x]>d[y]) x=f[x];
	if(x==y) return x;
	while(x!=y) x=f[x],y=f[y];
	return x;
}
int dis(int x,int y)
{
	int z=lca(x,y);
	return d[x]+d[y]-2*d[z];
}
void solve()
{
	cin>>n>>k;
	int u,v;
	rep(i,1,n) g[i].clear();
	rep(i,1,n-1)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	build(1,0);
	//cout<<lca(4,7)<<' '<<dis(2,8)<<'\n';
	int ans=INF,val;
	if(c<=3)
	{
		rep(mask,1,(1LL<<n)-1)
		{
			val=-1;
			if(__builtin_popcountll(mask)!=k) continue;
			rep(i,1,n) vis[i]=1;
			sz=0;
			rep(i,1,n)
			{
				if(mask&(1LL<<(i-1))) vis[i]=0,cc[++sz]=i;
			}
			int cnt=0;
			rep(i,1,n)
			{
				if(!vis[i]) dfs(i,0),cnt++;
				if(cnt>2) break;
			}
			if(cnt>2) continue;
			rep(i,1,n)
			{
				dd[i]=INF;
				rep(j,1,sz) dd[i]=min(dd[i],dis(i,cc[j]));
			}
			rep(i,1,n) val=max(val,dd[i]);
			ans=min(ans,val);
		}
		cout<<ans<<'\n';
	}
}
signed main()
{
	FAST_IO;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
