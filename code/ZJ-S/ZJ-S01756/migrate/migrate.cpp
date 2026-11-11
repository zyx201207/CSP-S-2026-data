#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000010];
vector<int> v[2000010];
long long dis[2000010];
long long f[2000010];
int vis[2000010];
void dijkstra(int x)
{
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
	for(int i=x;i<=n;i++)
	{
		vis[i]=0;
		dis[i]=1e9;
		f[i]=0;
	}
	q.push({0,x});
	f[x]=1;
	dis[x]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x])
		{
			continue;
		}
		vis[x]=1;
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				f[y]=f[x];
				q.push({dis[y],y});
			}
			else if(dis[y]==dis[x]+1)
			{
				f[y]+=f[x];
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			v[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					v[i].push_back(j);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			dijkstra(i);
			for(int j=i;j<=n;j++)
			{
				if(f[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
