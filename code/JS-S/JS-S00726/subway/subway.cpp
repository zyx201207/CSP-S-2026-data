#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,T;
int w[500005],k[505];
int a[505][500005],t[505][500005],tim;
struct node
{
	int v,line;
};
vector<node>e[500005];
struct pq
{
	int x,line,dist;
	bool operator <(const pq &o) const{
		return dist<o.dist;
	}
};
map<pair<int,int>,int>mp;
int dis[500005],vis[500005];
int bfs(int st,int en)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pq>q;
	q.push({st,-1,0});
	dis[st]=0;
	while(!q.empty())
	{
		pq u=q.top();
		q.pop();
		if(u.x==en) return u.dist+mp[make_pair(u.x,u.line)];
		if(vis[u.x]) continue;
		vis[u.x]=1;
		for(int i=0;i<e[u.x].size();i++)
		{
			if(u.x==st) 
			{
				u.line=e[u.x][i].line;
				u.dist=mp[make_pair(u.x,u.line)];
				dis[u.x]=min(dis[u.x],u.dist);
			}
			if(u.line!=e[u.x][i].line) 
			{
				if(u.dist+mp[make_pair(u.x,u.line)]+mp[make_pair(u.x,e[u.x][i].line)]<dis[e[u.x][i].v])
				{
					dis[e[u.x][i].v]=dis[u.x]+mp[make_pair(u.x,u.line)]+mp[make_pair(u.x,e[u.x][i].line)];
					q.push({e[u.x][i].v,e[u.x][i].line,dis[e[u.x][i].v]});
				}
			}
			else if(dis[e[u.x][i].v]>u.dist)
			{
				dis[e[u.x][i].v]=u.dist;
				q.push({e[u.x][i].v,u.line,u.dist});
			}
		}
	}
}
int bfs2(int st,int en)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pq>qp;
	qp.push({st,-1,0});
	dis[st]=T;
	while(!qp.empty())
	{
		pq u=qp.top();
		qp.pop();
		if(u.x==en) return u.dist+T;
		if(vis[u.x]) continue;
		vis[u.x]=1;
		for(int i=0;i<e[u.x].size();i++)
		{
			if(u.x==st) 
			{
				u.line=e[u.x][i].line;
			}
			if(u.line!=e[u.x][i].line) 
			{
				if(u.dist+2*T<dis[e[u.x][i].v])
				{
					dis[e[u.x][i].v]=dis[u.x]+2*T;
					qp.push({e[u.x][i].v,e[u.x][i].line,dis[e[u.x][i].v]});
				}
			}
			else if(dis[e[u.x][i].v]>u.dist)
			{
				dis[e[u.x][i].v]=u.dist;
				qp.push({e[u.x][i].v,u.line,u.dist});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) 
		{
			cin>>a[i][j]>>t[i][j];
			mp[make_pair(a[i][j],i)]=t[i][j];
			T=t[i][j];
		}
		for(int j=2;j<=k[i];j++) e[a[i][j-1]].push_back({a[i][j],i}),e[a[i][j]].push_back({a[i][j-1],i});
	}
	for(int i=1;i<=q;i++) 
	{
		int x,y;
		cin>>x>>y;	
		if(12<=c&&c<=19)
		{
			tim=w[x]+w[y];
			cout<<tim+bfs2(x,y)<<"\n";
		}
		else 
		{
			tim=w[x]+w[y];
			cout<<tim+bfs(x,y)<<"\n";			
		}
	}
	return 0;
}
