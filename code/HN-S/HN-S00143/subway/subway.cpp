#include<bits/stdc++.h>
using namespace std;
long long int time_z[500005];//»Î’æ ±º‰ 
long long int time_l[500005],time_ans[500005];
struct node
{
	long long int v,w;
};
vector<node> e[50005];
struct BFS
{
	long long int time,x;
};
long long int vis[500005];
int bfs(long long int x,long long int y)
{
	queue<BFS> q;
	q.push({0,x});
	vis[x]=0;
	while(!q.empty())
	{
		BFS t=q.front();
		if(t.x==y)
		{
			cout<<vis[t.x]<<"\n";
			return 0;
		}
		t.time+=time_z[t.x];
		q.pop();
		for(long long int i=0;i<e[t.x].size();i++)
		{
			long long int next_x=e[t.x][i].v;
			if(e[t.x][i].w+t.time<vis[next_x])
			{
				vis[next_x]=e[t.x][i].w+t.time;
				q.push({vis[next_x],next_x});
			}
		}
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>time_z[i];
	}
	while(n--)
	{
		long long int k;
		cin>>k;
		for(long long int i=1;i<=k;i++)
		{
			long long int s;
			cin>>time_l[i]>>time_ans[i];
		}
		for(long long int i=1;i<=k;i++)
		{
			for(long long int j=i+1;j<=k;j++)
			{
				e[time_l[i]].push_back({time_l[j],time_ans[j]});
			}
		}
	}
	while(q--)
	{
		for(long long int i=0;i<=m;i++)
		{
			vis[i]=1e18;
		}
		long long int x,y;
		cin>>x>>y;
		cout<<"\n";
		bfs(x,y); 
		for(long long int i=0;i<=m;i++)
		{
			cout<<vis[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
