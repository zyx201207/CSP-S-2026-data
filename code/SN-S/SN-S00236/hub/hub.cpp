#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c, T, n, k, fl[maxn], fa[maxn];
struct edge{
	int nxt, to;
}edge[maxn<<1];
int head[maxn], edgenum;
void add(int from,int to)
{
	edge[++edgenum].nxt=head[from];
	edge[edgenum].to=to;
	head[from]=edgenum;
}
pair<int,int> mp[maxn];
int dep[maxn], f[maxn][20];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=18;i++)
	{
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa) continue;
		dfs(v, u);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x, y);
	for(int i=18;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=18;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i], y=f[y][i];
		}
	}
	return f[x][0];
}
int getdis(int x,int y)
{
	return dep[x]+dep[y]-2*dep[LCA(x, y)];
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x), y=find(y);
	if(x==y) return ;
	fa[x]=y;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		edgenum=0;
		for(int i=1;i<=n;i++) 
		{
			head[i]=dep[i]=0;
			for(int j=0;j<20;j++) f[i][j]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u, v;
			cin>>u>>v;
			add(u, v), add(v, u);
			mp[i]={u, v};
		}
		if(n<=10)
		{
			dfs(1, 0);
			int ans=1e9;
			for(int i=1;i<(1<<n);i++)
			{
				int cnt=0;
				for(int j=1;j<=n;j++)
				{
					fl[j]=0;
					fa[j]=j;
					if(i>>(j-1)&1) fl[j]=1,cnt++;
				}
				if(cnt!=k) continue;
				for(int j=1;j<n;j++)
				{
					if(fl[mp[j].first]&&fl[mp[j].second]) merge(mp[j].first, mp[j].second);
				}
				cnt=0;
				for(int j=1;j<=n;j++)
				{
					if((i>>(j-1)&1)&&fa[j]==j) cnt++;
				}
				if(cnt>2) continue;
				int t=0;
				for(int j=1;j<=n;j++)
				{
					if(i>>(j-1)&1) continue;
					int res=1e9;
					for(int k=1;k<=n;k++)
					{
						if(i>>(k-1)&1) res=min(res, getdis(j, k));
					}
					t=max(t, res);
				}
				ans=min(ans, t);
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
