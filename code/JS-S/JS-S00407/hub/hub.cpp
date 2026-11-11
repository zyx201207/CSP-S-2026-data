#include<bits/stdc++.h>
using namespace std;

const int MAXN=15,INF=0x3f3f3f3f;
int c,T,n,k,ans,fa[MAXN],depth[MAXN];
vector<int> G[MAXN];

void dfs(int u=1,int f=0)
{
	fa[u]=f;
	depth[u]=depth[f]+1;
	for(int v:G[u]) if(v!=f) dfs(v,u);
}

int lca(int u,int v)
{
	if(depth[u]<depth[v]) swap(u,v);
	while(depth[u]>depth[v]) u=fa[u];
	while(u!=v) u=fa[u],v=fa[v];
	return u;
}

int dis(int u,int v)
{
	return depth[u]+depth[v]-2*depth[lca(u,v)];
}

struct DSU
{
	int fa[MAXN];
	DSU()
	{
		for(int i=1;i<MAXN;i++) fa[i]=i;
	}
	int find(int x)
	{
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	bool merge(int x,int y)
	{
		if(find(x)==find(y)) return 0;
		fa[find(x)]=find(y);
		return 1;
	}
};

int calc(int S)
{
	DSU D;
	int res=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(((S>>i)&1)==0) continue;
		for(int j:G[i])
		{
			if(((S>>j)&1)==0) continue;
			cnt+=D.merge(i,j);
		}
	}
	if(k-cnt>2) return INF;
	for(int i=1;i<=n;i++)
	{
		int mn=INF;
		for(int j=1;j<=n;j++)
		{
			if(((S>>j)&1)==0) continue;
			mn=min(mn,dis(i,j));
		}
		res=max(res,mn);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		ans=INF;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs();
		for(int S=1;S<(1<<n);S++)
		{
			if(__builtin_popcount(S)!=k) continue;
			ans=min(ans,calc(S));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
