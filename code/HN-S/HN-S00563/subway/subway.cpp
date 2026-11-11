#include<bits/stdc++.h>
using namespace std;
//我常常追忆过去 
//两个站之间不用时间吗？那就看成一个点吧； 
//16:09 45pts
struct nd{
	int v,w;
	bool operator <(const nd &x)const{
		return w<x.w; 
	}; 
};
vector<nd>g[600001];
int dis[501][600001];
int vis[600001];
int w[500001];
void dij(int sta)
{
	dis[sta][sta+500000]=0;
	priority_queue<nd>q;
	q.push({sta+500000,0});
	vis[sta+500000]++;
	while(!q.empty())
	{
		nd p=q.top();
		q.pop();
		vis[p.v]--;
		for(auto e:g[p.v])
		{
			if(dis[sta][e.v]>dis[sta][p.v]+e.w)
			{
				dis[sta][e.v]=dis[sta][p.v]+e.w;
				if(!vis[e.v])
				{
					q.push({e.v,dis[sta][e.v]});
					vis[e.v]++;
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			g[i+500000].push_back({v,w}); 
			g[v].push_back({i+500000,w});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dij(i);
	}
	for(int tt=1;tt<=q;tt++)
	{
		int s,t;
		cin>>s>>t;
		int minn=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			minn=min(minn,dis[i][s]+dis[i][t]+w[s]+w[t]);
		}
		cout<<minn<<endl;
	}
	return 0;
}
