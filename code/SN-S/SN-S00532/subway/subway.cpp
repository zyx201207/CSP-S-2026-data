#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<long long,int>
#define mp make_pair
const ll INF=1e18;
const int MAXN=510;
const int N=500510;
const int M=1000010;
int c,n,m,d,q;
struct edge
{
	int to,nxt;
	int ww;
}e[M];
int cnt=0;
vector<int> vec[N];
ll dis[MAXN][N];
int head[N];
bool vis[N];
int xxx[N];
void add(int u,int v,int x)
{
	e[++cnt]={v,head[u],x};
	head[u]=cnt;
}
void dijkstra(int s)
{
	for(int i=1;i<=n+m;i++)  vis[i]=0;
	for(int i=1;i<=n+m;i++)  dis[s][i]=INF;
	priority_queue<pi> q;
	dis[s][s]=0;
	q.push(mp(0,s));
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])  continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;int w=e[i].ww;
			if(dis[s][u]+w<dis[s][v])
			{
				dis[s][v]=dis[s][u]+w;
				q.push(mp(-dis[s][v],v));
			}
		}
	}
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)  cin>>xxx[i];
	//i+m
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a;int t;cin>>a>>t;
			add(a,i+m,t);add(i+m,a,t);
			vec[a].push_back(i+m);
		}
	}
	for(int i=1;i<=n;i++)  dijkstra(i+m);
	for(int i=1;i<=q;i++)
	{
		int x,y;cin>>x>>y;
		ll ans=INF;
		for(int i=0;i<vec[x].size();i++)
		{
			int sub=vec[x][i];
			if(dis[sub][x]==INF)  continue;
			ll now=dis[sub][x]+dis[sub][y]+xxx[x]+xxx[y];
			ans=min(ans,now);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
