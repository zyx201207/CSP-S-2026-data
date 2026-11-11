#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,st[20],vis[20],cnt,res2,ans=1000000000,d[20];
vector<int>e[1000010];
void find(int x)
{
	vis[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		if(vis[e[x][i]]==0&&st[e[x][i]]==1)
		{
			find(e[x][i]);
		}
	}
}
void root(int x,int fa)
{
	vis[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		if(e[x][i]!=fa)
		{
			d[e[x][i]]=d[x]+1;
			root(e[x][i],x);
		}
	}
}
void dfs(int x,int sum)
{
	if(sum>k)
	{
		return;
	}
	if(x==n+1)
	{
		if(sum!=k)
		{
			return;
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(st[i]==1&&vis[i]==0)
			{
				cnt++;
				find(i);
			}
		}
		if(cnt>2)
		{
			return;
		}
		int res1=0;
		for(int i=1;i<=n;i++)
		{
			res2=1000000000;
			d[i]=0;
			root(i,0); 
			for(int j=1;j<=n;j++)
			{
				if(st[j]==1)
				{
					res2=min(res2,d[j]);	
				}
			}
			res1=max(res1,res2);
		}
		ans=min(ans,res1);
		return;
	}
	st[x]=0;
	dfs(x+1,sum);
	st[x]=1;
	dfs(x+1,sum+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			vis[i]=0;
		}
		ans=1000000000;
	}
	return 0;
}
