#include<bits/stdc++.h>
#define Sparkle int main()
#define Sparxie return 0;
#define ll int
#define Aha cerr<<"hahaha"<<'\n'
#define Lv(x) cerr<<#x<<"="<<x<<'\n'
#define pb push_back
using namespace std;
const int maxn=505;
const int maxm=500005;
const int maxq=100005;
//const int mod=1000000007;
ll n;//地铁线路数
ll m;//地铁站数
ll d;//每个地铁站最多被几条线路经过
ll T;//出行计划数
ll w[maxm];//从每个地铁站的地铁口走到站厅需要的时间
//ll a[maxn][maxm];//a[i][0]表示第 i 条线路经过的地铁站数，a[i][j]第 i 条线路经过的第 j 个地铁站
//ll t[maxn][maxm];//t[i][0]表示第 i 条线路经过的地铁站数，t[i][j]表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
ll x[maxq],y[maxq];//起点，终点
struct Edge
{
	ll v,val;
};
vector<Edge> q[500505];
ll dis[500505];
bool vis[500505];
struct Node
{
	ll v,s;
	//感觉应该是正解，但重载运算符忘了怎么写了
	//好吧n，m看反了，时间复杂度不对，大概60pts? 
	bool operator < (const Node& oth) const
	{
		return s>oth.s;
	}
};

inline ll Dij(ll s,ll t)
{
	for(int i=1;i<=n+m;i++)
	{
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	dis[s]=0;
	priority_queue<Node> p;
	p.push({s,0});
	Node now;
	while(!p.empty())
	{
		now=p.top();
		p.pop();
		if(vis[now.v])
			continue;
		vis[now.v]=1;
		for(Edge v:q[now.v])
		{
			if(dis[v.v]>dis[now.v]+v.val)
			{
				dis[v.v]=dis[now.v]+v.val;
				p.push({v.v,dis[v.v]});
			}
		}
	}
	return dis[t]+w[s]+w[t];
}
inline void solve()
{
	cin>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	ll num,a,t;
	for(int i=1;i<=n;i++)
	{
		//第i条线路缩成点m+i,点m+i连接所有该线路上的地铁站 
//		cin>>a[i][0];
//		t[i][0]=a[i][0];
		cin>>num;
//		for(int j=1;j<=a[i][0];j++)
//		{
//			cin>>a[i][j]>>t[i][j];
//			q[m+i].pb({a[i][j],t[i][j]});
//			q[a[i][j]].pb({m+i,t[i][j]});
//		}
		for(int j=1;j<=num;j++)
		{
			cin>>a>>t;
			q[m+i].pb({a,t});
			q[a].pb({m+i,t});
		}
	}
	for(int i=1;i<=T;i++)
	{
		cin>>x[i]>>y[i];
		cout<<Dij(x[i],y[i])<<'\n';
	}
	
}

Sparkle
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,_=1;
	cin>>c;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	Sparxie
}
