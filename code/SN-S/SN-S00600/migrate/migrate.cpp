#include<bits/stdc++.h>
using namespace std;
long long a[5005],dis[305];
vector<int> e[5005];
int n;
int bfs(int sta,int end)
{
	queue<int> q;
	q.push(sta);
	int ans=0;
	bool ok=0;
	for(int i=1;i<=n;i++)
	{
		dis[i]=-1;
	}
	dis[sta]=0;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		for(auto u:e[v])
		{
			if(dis[u]==-1)
			{
				q.push(u);
				dis[u]=dis[v]+1;
			}
			if(u==end)
			{
				if(dis[v]+1==dis[end])
				{
					ans++;
				}
			}
		}
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					e[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(bfs(i,j)==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
