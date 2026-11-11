#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long
#define endl '\n'
using namespace std;
int C,N,M,D,q,W[505],K[505],A[505][505],T[505][505],anss[505][505],dis[505],st,ed,ans;
bool vist[505][505];
vector<int> ve[505];
struct Edge
{
	int to,w;
};
vector<Edge> E[505];
struct Node
{
	int u,dis,id;
};
struct Node2
{
	int id,dis;
	bool operator < (const Node2 &a)const
	{
		return dis>a.dis;
	}
};
void bfs()
{
	queue<Node> Q;
	for(int x:ve[st])
	{
		Q.push({st,T[st][x],x});
	}
	while(!Q.empty())
	{
		int u=Q.front().u,dis=Q.front().dis,id=Q.front().id;Q.pop();
		if(dis>=ans)
		{
			continue;
		}
		vist[u][id]=1;
		for(int i=1;i<=K[id];i++)
		{
			int v=A[id][i];
			if(v==ed)
			{
				ans=min(ans,dis+T[ed][id]);
				continue;
			}
			if(ve[v].size()>1)
			{
				for(int ln:ve[v])
				{
					if(ln!=id)
					{
						if(dis+T[v][id]+T[v][ln]>=ans||vist[v][ln])
						{
							continue;
						}
						Q.push({v,dis+T[v][id]+T[v][ln],ln});
					}
				}
			}
		}
	}
}
void bfs2(int s)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue<Node2> Q;Q.push({s,0});dis[s]=0;
	while(!Q.empty())
	{
		int u=Q.top().id,ds=Q.top().dis;Q.pop();
		if(dis[u]<ds)
		{
			continue;
		}
		for(Edge x:E[u])
		{
			int v=x.to,w=x.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				Q.push({v,dis[v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>N>>M>>D>>q;
	for(int i=1;i<=M;i++)
	{
		cin>>W[i];
	}
	for(int i=1;i<=N;i++)
	{
		cin>>K[i];
		for(int j=1;j<=K[i];j++)
		{
			cin>>A[i][j]>>T[A[i][j]][i];
			ve[A[i][j]].push_back(i);
		}
	}
	if(C<=8)
	{
		while(q--)
		{
			cin>>st>>ed;ans=1e18;bfs();
			cout<<W[st]+ans+W[ed]<<endl;
			for(int i=1;i<=M;i++)
			{
				for(int j=1;j<=N;j++)
				{
					vist[i][j]=0;
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=M;i++)
	{
		for(int u:ve[i])
		{
			for(int v:ve[i])
			{
				if(u!=v)
				{
					E[u].push_back({v,T[1][1]*2});
					E[v].push_back({u,T[1][1]*2});
				}
			}
		}
	}
	memset(anss,0x3f,sizeof(anss));
	for(int i=1;i<=N;i++)
	{
		bfs2(i);
		for(int j=1;j<=N;j++)
		{
			anss[i][j]=min(anss[i][j],dis[j]);
		}
	}
	while(q--)
	{
		cin>>st>>ed;
		ans=1e18;
		for(int x:ve[st])
		{
			for(int y:ve[ed])
			{
				ans=min(ans,W[st]+W[ed]+T[1][1]*2+anss[x][y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
Name: 
Copyright: 
Author: The Pioneer,The Concluder 
Date: 18/08/26 10:10
Description: 
*/