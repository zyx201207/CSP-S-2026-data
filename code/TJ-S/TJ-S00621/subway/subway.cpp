#include<bits/stdc++.h>
using namespace std;
int const N=1e6+505;
int vis[N],d[N];
vector<pair<int,int>> e[N];//*2
void dijikstra(int x,int y)
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	priority_queue<pair<int,int>> q;//С
	d[x]=0;
	q.push({d[x],x});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int u=now.second();
		if(u==y)
		{
			printf("%d\n",d[y]);
			return;
		}
		vis[u]=1;
		for(auto h:e[u])
		{
			int v=h.first;
			int w=h.second;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push(d[v],v);
			}
		}
	}
}
int main()
{
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
		e[i].push_back({i+m,w});
		e[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++)
	{
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back({2*m+i,t[i][j]});
			e[2*m+i].push_back({a[i][j],t[i][j]});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x+=m;
		y+=m;
		dijikstra(x,y);
	}
}
