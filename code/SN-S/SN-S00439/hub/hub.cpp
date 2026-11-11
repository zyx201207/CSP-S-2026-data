//SN-S00439 西安市铁一中 蒋雨曦 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 1000005 
using namespace std;
const ll inf=1e18;
ll c,T,n,k,f[maxn][22],dep[maxn],vis[maxn],ans,g[maxn];
vector<ll> edge[maxn];
ll find(ll now) {if(g[now]==now) return now; return g[now]=find(g[now]);}
void dfs(ll now,ll fa)
{
	f[now][0]=fa; dep[now]=dep[fa]+1;
	for(auto to:edge[now]) if(to^fa) dfs(to,now);
}
ll LCA(ll x,ll y)
{
	if(dep[x]<dep[y]) swap(x,y);
	ll cha=dep[x]-dep[y];
	for(int i=21;i>=0;i--) if((1<<i)&cha) x=f[x][i];
	if(x==y) return x;
	for(int i=21;i>=0;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
void cal()
{
	for(int i=1;i<=n;i++) g[i]=i;
	for(int i=1;i<=n;i++) if(vis[i])
	{
		for(auto to:edge[i]) if(vis[to]) g[find(i)]=find(to);
	}
	ll num=0;
	for(int i=1;i<=n;i++) if(find(i)==i&&vis[i]) num++;
	if(num>2||num==0) return;
	ll mx=0;
	for(int i=1;i<=n;i++) if(!vis[i])
	{
		ll mn=1e18;
		for(int j=1;j<=n;j++) if(vis[j])
		{
			ll lca=LCA(i,j);
			mn=min(mn,dep[i]+dep[j]-dep[lca]*2);
		}
		mx=max(mx,mn);
	}
	ans=min(ans,mx);
}
void dfs2(ll now,ll sum)
{
	if(now==n+1) {if(sum==k) cal(); return;}
	vis[now]=1; dfs2(now+1,sum+1);
	vis[now]=0; dfs2(now+1,sum);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("hub.in","r",stdin); freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k; for(int i=1;i<=n;i++) edge[i].clear();
		for(int i=1;i<n;i++)
		{
			ll u,v; cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(n==k) {cout<<"0\n"; continue;}
		ans=inf; dfs(1,1);
		for(int j=1;j<=21;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
		dfs2(1,0); cout<<ans<<"\n";
	}
	return 0;
}
