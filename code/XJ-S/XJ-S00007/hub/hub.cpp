#include<bits/stdc++.h>
using namespace std;
int fa[500010][21],n,k,lg[500010],fa_bcj[500010],d[500010];
vector<int> mp[500010];
bool flag[500010];
int find(int x)
{
	return (x==fa_bcj[x]?x:fa_bcj[x]=find(fa_bcj[x]));
}
void merge(int x,int y)
{
	fa_bcj[find(x)]=find(y);
}
void initbcj()
{
	for(int i=1;i<=n;i++)
	{
		fa_bcj[i]=i;
	}
}
void dfs(int x,int f=0)
{
	fa[x][0]=f;
	d[x]=d[f]+1;
	for(int i=1;i<=lg[d[x]];i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i:mp[x])
	{
		if(i!=f)
		{
			dfs(i,x);
		}
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y])
	{
		swap(x,y);
	}
	while(d[x]>d[y])
	{
		x=fa[x][lg[d[x]-d[y]]];
	}
	if(x==y)
	{
		return x;
	}
	for(int i=lg[d[x]];i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int dist(int x,int y)
{
	return d[x]+d[y]-d[lca(x,y)]*2;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(int i=2;i<=500000;i++)
	{
		lg[i]=lg[i/2]+1;
	}
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			mp[i].clear();
			d[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		dfs(1);
		int ans=INT_MAX;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1)))
				{
					cnt++;
				}
			}
			if(cnt!=k)
			{
				continue;
			}
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1)))
				{
					flag[j]=true;
				}
				else
				{
					flag[j]=false;
				}
			}
			initbcj();
			for(int j=1;j<=n;j++)
			{
				if(flag[j])
				{
					for(int k:mp[j])
					{
						if(flag[k])
						{
							merge(j,k);
						}
					}
				}
			}
			int cnt1=0;
			for(int j=1;j<=n;j++)
			{
				if(flag[j]&&find(j)==j)
				{
					cnt1++;
				}
			}
			if(cnt1<=2)
			{
				int now=0;
				for(int j=1;j<=n;j++)if(!flag[j])
				{
					int min1=INT_MAX;
					for(int k=1;k<=n;k++)if(flag[k])
					{
						min1=min(min1,dist(j,k));
					}
					now=max(now,min1);
				}
				ans=min(ans,now);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

