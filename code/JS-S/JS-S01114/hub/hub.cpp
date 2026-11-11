#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,a[2000010];
bool vis[2000010],vis2[2000010];
int dis[2000010];
int ret;
vector<int>b[2000010];
void dfs2(int x,int fa)
{
	for(int i=0;i<b[x].size();i++)
	{
		int to=b[x][i];
		if(to==fa||!vis2[to]||vis[to])
		{
			continue;
		}
		vis[to]=1;
		//~ cout<<to<<" ";
		dfs2(to,x);
	}
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=vis2[i]=0;
	}
	for(int i=1;i<=k;i++)
	{
		vis2[a[i]]=1;
		//~ cout<<a[i]<<" ";
	}
	//~ cout<<endl;
	int cnt=0;
	for(int i=1;i<=k;i++)
	{
		if(!vis[a[i]])
		{
			vis[a[i]]=1;
			if(cnt==2)
			{
				return 0;
			}
			//~ cout<<a[i]<<"|---  ";
			//cout<<endl;
			dfs2(a[i],-1);
			cnt++;
		}
	}
	//~ cout<<cnt<<endl;
	if(cnt>2)
	{
		return 0;
	}
	return 1;
}
void dfs4(int x,int fa)
{
	for(int i=0;i<b[x].size();i++)
	{
		int to=b[x][i];
		if(to==fa)
		{
			continue;
		}
		if(dis[to]>dis[x]+1)
		{
			dis[to]=dis[x]+1;
			dfs4(to,x);
		}
	}
}
int maxd()
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=0x3f3f3f3f;
	}
	for(int i=1;i<=k;i++)
	{
		dis[a[i]]=0;
		dfs4(a[i],-1);
	}
	int r=0;
	for(int i=1;i<=n;i++)
	{
		r=max(r,dis[i]);
	}
	return r;
}
void dfs(int x,int s)
{
	if(s>k)
	{
		return;
	}
	if(n-x+1<(k-s))
	{
		return;
	}
	if(x==n+1)
	{
		if(s==k)
		{
			//~ cout<<check()<<endl;
			if(check())
			{
				
				//~ cout<<maxd()<<endl;
				//~ for(int i=1;i<=n;i++)
				//~ {
					//~ cout<<dis[i]<<" ";
				//~ }
				//~ cout<<endl<<endl;
				ret=min(ret,maxd());
			}
		}
		return;
	}
	dfs(x+1,s);
	if(s==k)
	{
		return;
	}
	a[s+1]=x;
	dfs(x+1,s+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ret=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			b[u].push_back(v);
			b[v].push_back(u);
		}
		dfs(1,0);
		cout<<ret<<"\n";
		for(int i=1;i<=n;i++)
		{
			b[i].clear();
		}
	}
	return 0;
}
