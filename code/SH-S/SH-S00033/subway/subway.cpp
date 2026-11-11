#include <bits/stdc++.h>
using namespace std;
#define ll long long

int c,n,m,d,q;
const int N=507,D=27,M=2e3+7;
ll w[M],dis[M][M*D];
bool vis[M*D];

struct Edge
{
	ll v,w;
	friend bool operator< (Edge A,Edge B)
	{
		return A.w>B.w;
	}
};
vector<Edge> e[M*D*D];
priority_queue<Edge> Q;

ll read()
{
	char ch=getchar();
	ll res=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}

void Dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	for(int s=1;s<=m;s++)
	{
		memset(vis,false,sizeof(vis));
		Q.push({s,0});
		dis[s][s]=0;
		while(!Q.empty())
		{
			int u=Q.top().v;
			Q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto it:e[u])
			{
				ll v=it.v,w=it.w;
				if(dis[s][v]>dis[s][u]+w)
				{
					dis[s][v]=dis[s][u]+w;
					Q.push({v,dis[s][v]});
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k=read();
		ll u,v,t;
		for(int j=1;j<=k;j++)
		{
			u=v;
			v=read(),t=read();
			e[v+m*i].push_back({v,t});
			e[v].push_back({v+m*i,t});//站台到站厅 
			if(j>=2)
			{
				e[u+m*i].push_back({(v+m*i),0});
				e[v+m*i].push_back({(u+m*i),0});
			}//地铁线路内部 
		}
	}
	Dijkstra();
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++)
	{
		ll x=read(),y=read();
		ll ans=dis[x][y]+w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
