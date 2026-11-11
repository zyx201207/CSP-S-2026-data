#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
#define int long long 

inline int read()
{
	int x(0);
	char ch(getchar());
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

const int N=(int)(5e5)+505;
class eg
{
public:
	int to,w;
};
class Node
{
public:
	int x,val;
	bool operator<(const Node& tmp)const
	{
		return val>tmp.val;
	}
};
int c,n,m,d,q,dis[505][N],w[N];
vector<eg>nbr[N],to[N];
bool vis[N];

void dijkstra(int st,int dis[])
{
	for(int i=1;i<=n+m;i++)
		dis[i]=1e18,vis[i]=false;
	priority_queue<Node>pq;
	pq.push({st,0});
	dis[st]=0;
	while(pq.empty()==false)
	{
		int cur=pq.top().x;
		pq.pop();
		if(vis[cur]==true)
			continue;
		vis[cur]=true;
		for(auto dat:nbr[cur])
		{
			int nxt=dat.to,w=dat.w;
			if(dis[cur]+w<dis[nxt])
			{
				dis[nxt]=dis[cur]+w;
				pq.push({nxt,dis[nxt]});
			}
		}
	}
	return ;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k(read()),x,t;
		while(k--)
		{
			x=read(),t=read();
			nbr[m+i].push_back({x,t});
			nbr[x].push_back({m+i,t});
		}
	}
	// cerr<<"???\n";
	for(int i=1;i<=n;i++)
		dijkstra(m+i,dis[i]);
	while(q--)
	{
		int x(read()),y(read()),ans=1e18;
		for(auto dat:nbr[y])
			ans=min(ans,dis[dat.to-m][x]+dat.w);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}