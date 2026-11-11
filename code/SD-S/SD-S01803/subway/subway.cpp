//大抵是最短路 
//就是最短路
/*
	计划的时间(求)：进出站和换乘的步行时间之和
	注意到地铁线路上的点可以瞬移 
	分层图!
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define manm 500005
#define manq 100005
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
struct query//排序后离线处理 
{
	int st,fi,id,ans;
}que[manq];
bool cmp1(query a,query b)
{
	return a.st<b.st;
}
bool cmp2(query a,query b)
{
	return a.id<b.id;
}
priority_queue<pii,vector<pii>,greater<pii> > qq;
vector<pii> g[manm*21];
/*
g[i*1]表示第i个站的站厅层 
g[i*j](j>=2)表示第(j-1)号线的站台层 
*/
ll c,n,m,d,q;
int dis[manm*21],w[manm];
bool vis[manm*21];
void dijkstra(int s)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[s]=0;
	qq.push(make_pair(0,s));
	while(!qq.empty())
	{
		int u=qq.top().second;qq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(pii i:g[u])
		{
			int v=i.first;
			if(dis[v]>dis[u]+i.second)
			{
				dis[v]=dis[u]+i.second;
				qq.push(make_pair(dis[v],v));
			}
		}
	}
}
void add(int u,int v,int w)
{
	g[u].push_back(make_pair(v,w));
	g[v].push_back(make_pair(u,w));
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];//地铁口到站厅
	for(int i=1;i<=n;i++)//线路序号 
	{
		int k;cin>>k;//该线路的站点数量
		int aa,t;
		cin>>aa>>t;
		add(aa+m*i,aa,t);//单个站的站厅到站台 
		for(int j=2;j<=k;j++)
		{
			int a;cin>>a>>t;
			add(aa+m*i,a+m*i,0);//两站之间的地铁线路 
			add(a+m*i,a,t);//单个站的站厅到站台 
			aa=a;
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>que[i].st>>que[i].fi;
		que[i].id=i;
	}
	sort(que+1,que+q+1,cmp1);
	for(int i=1;i<=q;i++)
	{
		if(que[i].st!=que[i-1].st)
			dijkstra(que[i].st);
		que[i].ans=dis[que[i].fi]+w[que[i].st]+w[que[i].fi];
	}
	sort(que+1,que+q+1,cmp2);
	for(int i=1;i<=q;i++) cout<<que[i].ans<<'\n';
	
	return 0;
}
