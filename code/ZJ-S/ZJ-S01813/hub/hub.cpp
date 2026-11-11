#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,t,n,k,fa[N],faa[20][N],dep[N];
bool choose[N];
vector<int>g[N];
vector<int>node[N];

void init(int n)
{
	for(int i=1;i<=n;i++) fa[i]=i;
}


int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void merge(int u,int v)
{
	if(find(u)==find(v)) return;
	fa[find(u)]=find(v);
}

void dfs2(int u,int pre)
{
	faa[0][u]=pre;
	for(auto v:node[u])
	{
		if(v==pre) continue;
		dep[v]=dep[u]+1;
		dfs2(v,u);
	}
}

int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int dis=dep[u]-dep[v];
	for(int i=20;i>=0;i++)
	{
		if(dis&(1<<i)) u=faa[i][u];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i++)
	{
		if(faa[i][u]!=faa[i][v])
		{
			u=faa[i][u];
			v=faa[i][v];
		}
	}
	return faa[0][u];
}

void dfs(int now)
{
	if(now==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++) node[i].clear();
		init(n);
		for(int i=1;i<=n;i++) dep[i]=0;
		for(int u=1;u<=n;u++)
		{
			if(choose[u])
			{
				cnt++;
				for(auto v:g[u])
				{
					merge(u,v);
					node[u].push_back(v);
					node[v].push_back(u);
				}
			}
		}
		if(cnt!=k) return;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(choose[i])
			{
				if(i==fa[i]) cnt++;
			}
		}
		if(cnt>2) return;
		for(int i=1;i<=n;i++)
		{
			if(choose[i])
			{
				if(i==fa[i]) dep[i]=1,dfs2(i,-1);
			}
		}
		for(int j=1;j<=20;j++)
		{
			for(int i=1;i<=n;i++)
			{
				faa[j][i]=faa[j-1][faa[j-1][i]];
			}
		}
		
		return;
	}
	choose[now]=0;
	dfs(now+1);
	choose[now]=1;
	dfs(now+1);
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear(),choose[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
	}
	return 0;
}
//0 2
//5 2
//1 2
//2 3
//3 4 
//4 5
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10