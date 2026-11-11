#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N=2e6+5;
#define pii pair<ll,ll>
#define x first
#define y second
inline void read(ll &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
}
ll C,T,n,k,ans,p[N],ds[20][20];
bool vis[N];
ll fa[N],dep[N],top[N],siz[N],hson[N];
vector<int> g[N];
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1;fa[u]=f;siz[u]=1;
	for(int v:g[u])
	{
		if(v==f)
			continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]])
			hson[u]=v;
	}
}
void dfs2(int u,int f,int tp)
{
	top[u]=tp;
	if(hson[u])
		dfs2(hson[u],u,tp);
	for(int v:g[u])
		if(v!=f&&v!=hson[u])
			dfs2(v,u,v);
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])
			u=fa[top[u]];
		else
			v=fa[top[v]];
	}
	if(dep[u]<dep[v])
		return u;
	return v;
}
bool check()
{
	int ct=0;
	for(int i=1;i<=k;i++)
		for(int v:g[p[i]])
			if(vis[v]&&p[i]>v)
				ct++;
	return ct==k-1||ct==k-2;
}
void dfs(int c,int m)
{
	if(c==k+1)
	{
		if(!check())
			return;
		ll an=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				ll mi=1e18;
				for(int j=1;j<=k;j++)
					mi=min(mi,ds[p[j]][i]);
				an=max(an,mi);
				if(an>ans)
					break;
			}
		ans=min(an,ans);
		return;
	}
	for(int i=m;i<=n;i++)
	{
		p[c]=i;
		vis[i]=1;
		dfs(c+1,i+1);
		vis[i]=0;
	}
}
void solve()
{
	cin>>n>>k;ans=1e18;
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs1(1,0);dfs2(1,0,1);
	if(k==n)
	{
		cout<<0<<"\n";
	}
	else if(n<=10)
	{
		memset(ds,0,sizeof ds);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ds[i][j]=ds[j][i]=dep[i]+dep[j]-2*dep[lca(i,j)];
		dfs(1,1);
		cout<<ans<<"\n";
	}
	else
		cout<<1<<"\n";
	for(int i=1;i<=n;i++)
		g[i].clear(),dep[i]=fa[i]=siz[i]=top[i]=hson[i]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)
		solve();
	return 0;
}
