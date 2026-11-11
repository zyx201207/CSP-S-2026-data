#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,gunmu,d,q,countt,ans,val[500010],x,u,v,z,dis[500510],dist[510][510],vis[500510];
vector<int> e[500510],w[500510];
void dijkstra(int x)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,x});
	dis[x]=0;
	while(!q.empty())
	{
		pair<int,int> t=q.top();
		q.pop();
		for(int i=0;i<e[t.second].size();i++)
		{
			countt++;
			if(dis[e[t.second][i]]>dis[t.second]+w[t.second][i])
			{
				dis[e[t.second][i]]=dis[t.second]+w[t.second][i];
				if(!vis[e[t.second][i]])
				{
					q.push({dis[e[t.second][i]],e[t.second][i]});
				}
			}
		}
		vis[t.second]=1;
	}
	for(int i=1;i<=n;i++)
	{
		dist[x-m][i]=dist[i][x-m]=dis[i+m];
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>gunmu>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>val[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>u>>z;
			e[m+i].push_back(u);
			w[m+i].push_back(z);
			e[u].push_back(m+i);
			w[u].push_back(z);
		}
	}
	for(int i=m+1;i<=m+n;i++)
	{
		for(int j=1;j<=n+m;j++)
		{
			dis[j]=0x3f3f3f3f3f3f3f3f;
			vis[j]=0;
		}
		dijkstra(i);
	}
	cout<<countt;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<i<<" "<<j<<" "<<dist[i][j]<<"\n";
//		}
//	}
	for(int i=1;i<=q;i++)
	{
		cin>>u>>v;
		ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<e[u].size();j++)
		{
			for(int k=0;k<e[v].size();k++)
			{
				ans=min(ans,val[u]+val[v]+w[u][j]+w[v][k]+dist[e[u][j]-m][e[v][k]-m]);
//				if(i==1&&val[u]+val[v]+w[u][j]+w[v][k]+dist[e[u][j]-m][e[v][k]-m])
//				{
//					cout<<e[u][j]<<" "<<e[v][k]<<" "<<w[u][j]<<" "<<w[v][k]<<" "<<dist[j-m][k-m]<<"\n";
//				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//start: 14:47
//end1: 15:50
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/ 
