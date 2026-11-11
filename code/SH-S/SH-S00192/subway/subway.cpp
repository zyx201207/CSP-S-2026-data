#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,t;
};
long long c,n,m,d,q,ans;
long long w[500010],k[500010];
vector<node> g[100010];
int vis[500010];
void bfs(int x,int y)
{
	memset(vis,0,sizeof vis);
	queue<pair<int,int>>q;
	q.push({x,0});
	vis[x]=1;
	while(q.size())
	{
		int xx=q.front().first,time=q.front().second;
		q.pop();
		cout<<xx<<endl;
		if (xx==y)
		{
			ans=time;
			return ;
		}
		for (int i=0;i<g[x].size();i++)
		{
			int m=g[x][i].to,v=g[x][i].t;
			if (!vis[m])
			{
				q.push({m,v+time+w[m]});
				vis[m]=1;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			int to,t;
			cin>>to>>t;
			g[i].push_back({to,t});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long sum=0;
		for (int i=1;i<=m;i++)
		{
			sum+=w[i];
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=k[i];j++)
			{
				sum+=g[i][j].t;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
