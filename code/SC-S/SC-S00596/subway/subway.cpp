#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define ll long long
#define endl '\n'
using namespace std;
struct Edge
{
	int v;
	ll w;
};
struct cmp
{
	bool operator()(Edge x,Edge y)
	{
		return x.w>y.w;
	}
};
const int N=2e4+5,M=505;
int c,n,m,d,Q,k,x,y,a[N];
int pre[N];
ll w,t,dis[N*M];
bool vis[N*M];
vector<Edge> g[N*M];
priority_queue<Edge,vector<Edge>,cmp > q;
int id(int i,int j)
{
	return (i+1)*n+j;
}
void add(int u,int v,ll w)
{
	g[u].push_back((Edge){v,w});
}
ll dijkstra(int s,int t)
{
	memset(pre,0,sizeof(pre));
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=(n+2)*m;i++)
		dis[i]=1e18;
	dis[s]=0;
	q.push((Edge){s,0});
	while(!q.empty())
	{
		Edge head=q.top();
		q.pop();
		int now=head.v;
		if(vis[now])
			continue;
		vis[now]=true;
		for(int i=0;i<g[now].size();i++)
		{
			int v=g[now][i].v;
			ll w=g[now][i].w;
			if(dis[now]+w<dis[v])
			{
				dis[v]=dis[now]+w;
				pre[v]=now;
				q.push((Edge){v,dis[v]});
			}
		}
	}
	//cout<<t<<" ";
	return dis[t];
}
/*pair<int,int> get(int x)
{
	return {x/n-1,x%n};
}
void print(int x)
{
	if(x==0)
		return;
	print(pre[x]);
	cout<<"->("<<get(x).first<<","<<get(x).second<<")";
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w;
		add(id(-1,i),id(0,i),w);
		add(id(0,i),id(-1,i),w);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t;
			add(id(0,a[j]),id(i,a[j]),t);
			add(id(i,a[j]),id(0,a[j]),t);
		}
		for(int j=2;j<=k;j++)
			add(id(i,a[j-1]),id(i,a[j]),0);
	}
	while(Q--)
	{
		cin>>x>>y;
		/*cout<<x<<" "<<y<<"(";
		cout<<id(-1,x)<<","<<id(-1,y)<<"  ";*/
		cout<</*"ans = "<<*/dijkstra(id(-1,x),id(-1,y))/*<<"   road : "*/<<"\n";
		/*print(id(-1,y));
		cout<<")\n";*/
	}
	return 0;
}