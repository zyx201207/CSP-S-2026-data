#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int v,w;
	bool operator<(const node &x)const
	{
		return w>x.w;
	}
};
struct node1
{
	int x,t1,t2;
};
int C,n,m,d,q,w[500005],xx[505],t[505],vis[500005],dis[500005];
vector<node1>vec[500005];
void dij(int sx,int ex)
{
	priority_queue<node>que;
	dis[sx]=0;
	que.push({sx,dis[sx]});
	while(!que.empty())
	{
		node q1=que.top();
		que.pop();
		if(q1.v==ex)
		return;
		if(vis[q1.v])
		continue;
		vis[q1.v]=true;
		for(int i=0;i<vec[q1.v].size();i++)
		{
			int v=vec[q1.v][i].x;
			int w=vec[q1.v][i].t1+vec[q1.v][i].t2;
			if(dis[v]>dis[q1.v]+w)
			{
				dis[v]=dis[q1.v]+w;
				que.push({v,dis[v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	int kkk,x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>kkk;
		for(int j=1;j<=kkk;j++)
		cin>>xx[j]>>t[j];
		for(int j=1;j<=kkk;j++)
		{
			for(int k=j+1;k<=kkk;k++)
			{
				vec[xx[j]].push_back({xx[k],t[j],t[k]});
				vec[xx[k]].push_back({xx[j],t[k],t[j]});
			}
		}
	}
	while(q--)
	{
		for(int i=1;i<=m;i++)
		dis[i]=1e9,vis[i]=false;
		cin>>x>>y;
		dij(x,y);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
