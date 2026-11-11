#include <bits/stdc++.h>
using namespace std;
int w[500010];
vector< pair<int,int> > ma[500510];//结点 权值 
vector<int> dist[500510];
const int inf = 1e9;
int vis[1000];
int distpf[500][500];


int find(int a,vector< pair<int,int> > x)
{
	int minn =inf;
	for(int i=0;i<x.size();i++)
	{
		int u = x[i].first,w = x[i].second;
		if(!vis[u])
		{
			int tie = find(a,ma[u]);
			vis[u] = 1;
			minn = min(minn,tie);
		}
		else
		{
			minn = w;
		}
	}
	return minn;
}
//void zdlqj()
//{
//	for(int i=0;i<n;i++)//no n
//	{
//		
//	}
//}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
//	priority_queue<int> test;
	
	int c,n,m,d,q;//测试点  线路数  站数  地铁站经过数  查询数 
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
			int u,t;
			cin>>u>>t;
			ma[u].push_back({i+m,t});
			ma[i+m].push_back({u,t});
		}
	}
	if(c<=6)
	{
		int ans = 0;
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<find(x,ma[x])+w[x]+w[y]<<endl;
		}
		return 0;
	}
	
	
	
	
//	zdlqj();
	for(int i=1;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]<<endl;
	}
	
	
	return 0;
}
