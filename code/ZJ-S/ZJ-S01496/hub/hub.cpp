#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,f[110][25],dep[110],Lg[110],ans=1e9,vis[110],vis1[110],d[110][110];
vector<int> v[110];
void init(int x,int fa)
{
	f[x][0]=fa;dep[x]=dep[fa]+1;
	for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i:v[x])
	{
		if(i==fa) continue;
		init(i,x);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) return LCA(y,x);
	while(dep[x]>dep[y])
	{
		x=f[x][Lg[dep[x]-dep[y]]];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[y][0];
}
void dfs1(int x)
{
	if(vis1[x]==1) return;
	vis1[x]=1;
	for(int i:v[x])
	{
		if(vis[i]==1) dfs1(i);
	}
}
void dfs(int pos,int cnt)
{
	if(pos==n+1)
	{
		if(cnt!=k) return;
		int c=0;
		for(int i=1;i<=n;i++) vis1[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1&&vis1[i]==0)
			{
				if(c==2)
				{
					return;
				}
				c++;
				dfs1(i);
			}
		}
		int ret=0;
		for(int i=1;i<=n;i++)
		{
			int mn=1e9;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]==1)
				{
					mn=min(mn,d[i][j]);
				}
			}
			ret=max(ret,mn);
		}
		ans=min(ans,ret);
		return;
	}
	if(cnt!=k)
	{
		vis[pos]=1;
		dfs(pos+1,cnt+1);
	}
	vis[pos]=0;
	dfs(pos+1,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=2;i<=100;i++) Lg[i]=Lg[i/2]+1;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++) 
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(c<=3)
		{
			init(1,0);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					d[i][j]=dep[i]+dep[j]-dep[LCA(i,j)]*2;
				}
			}
			ans=1e9;
			dfs(1,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/