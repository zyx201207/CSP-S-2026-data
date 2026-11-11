#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>
#define ll long long
using namespace std;
const ll INF=1e16;
const int N=505,M=5e5+7;
int c,n,m,dm,q;
ll w[M],e[N][N],d[N][N];
vector<pair<int,ll>> stop[M];
//由于只考虑了步行时间，可以把地铁线路看做节点，把站点看做边，然后做最短路 
//还是用临界矩阵好
struct node
{
	int pos;
	ll dis;
};
bool operator<(const node &a,const node &b)
{
	return a.dis>b.dis;
}
void bfs(int st)
{
	bool vis[N]={};
	priority_queue<node> q;
	q.push({st,0ll});
	d[st][st]=0;
	while(!q.empty())
	{
		node now=q.top(); q.pop();
		if(vis[now.pos]) continue;
		vis[now.pos]=true;
		for(int ver=1;ver<=n;ver++)
		{
			if(e[now.pos][ver]==INF) continue;
			if(d[st][ver]>d[st][now.pos]+e[now.pos][ver])
			{
				d[st][ver]=d[st][now.pos]+e[now.pos][ver];
				q.push({ver,d[st][ver]});
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dm>>q;
	for(int i=1;i<=m;i++)
	  cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,a,t;j<=k;j++)//stop存这个站点有那几条地铁线路，站厅到站台的距离是多少
		{
			cin>>a>>t;
			stop[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    d[i][j]=e[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int len=stop[i].size();
		for(int u=0;u<len;u++)
			for(int v=u+1;v<len;v++)
			{
				int x=stop[i][u].first,y=stop[i][v].first;
		  		e[y][x]=e[x][y]=min(e[x][y],stop[i][u].second+stop[i][v].second);
			}
	}
	for(int i=1;i<=n;i++)//计算两条线路之间的最短路
	  bfs(i);
	while(q--)
	{
		int u,v,in,out;
		ll ans=INF;
		cin>>u>>v;
		for(int i=0;i<stop[u].size();i++)
		  for(int j=0;j<stop[v].size();j++)
		    ans=min(ans,stop[u][i].second+d[stop[u][i].first][stop[v][j].first]+stop[v][j].second);
		cout<<w[u]+ans+w[v]<<"\n";
	}
	return 0;
}