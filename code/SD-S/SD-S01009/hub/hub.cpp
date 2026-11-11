#include<bits/stdc++.h>
using namespace std;
int C,t;
int n,k;
vector<int>e[15];
int c[15];
int b[15];
int dis[15];
int mx;
int ans;
void calc(int u,int fa)
{
	for(auto v:e[u])
		if(v!=fa)
		{
			dis[v]=min(dis[v],dis[u]+1);
			calc(v,u);
		}
}
void con(int u,int fa)
{
	b[u]=1;
	for(auto v:e[u])
		if(v!=fa&&c[v])
			con(v,u);
}
void dfs(int x,int cnt)
{
	if(cnt>k)
		return ;
	if(x>n)
	{
		if(cnt!=k)
			return ;
		for(int i=1;i<=n;i++)
			b[i]=0;
		int tmp=0;
		for(int i=1;i<=n;i++)
			if((!b[i])&&c[i])
			{
				con(i,0);
				tmp++;
			}
		if(tmp>2)
			return ;
		mx=0;
		for(int j=1;j<=n;j++)
			dis[j]=n+1;
		for(int i=1;i<=n;i++)
			if(c[i])
			{
				dis[i]=0;
				calc(i,0);
			} 
		for(int i=1;i<=n;i++)
			if(!c[i])
				mx=max(mx,dis[i]);
		ans=min(ans,mx);
		return ;
	}
	
	c[x]=1;
	dfs(x+1,cnt+1);
	c[x]=0;
	dfs(x+1,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&t);
	if(C<=3)
	{
		while(t--)
		{
			ans=n+1;
			scanf("%d%d",&n,&k);
			for(int i=1;i<=n;i++)
				e[i].clear();
			for(int i=1;i<n;i++)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				e[u].push_back(v);
				e[v].push_back(u);
			}
			dfs(1,0);
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
		}
		int p=n/2;
		if(k==n)
		{
			cout<<"0\n";
			continue;
		}
		if(k<p)
		{
			cout<<p-k<<"\n";
			continue;
		} 
		if(k>=p)
		{
			cout<<"1\n";
			continue;
		}
	}
	return 0;
}
