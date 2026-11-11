#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define MAXN 55
#define MAXM 500005
const int INF=1e18;
int c,n,m,d,q;
int w[MAXM],M;
int k[MAXN];
int a[MAXN][MAXM];
int t[MAXN][MAXM];
vector<pii> g[MAXM];
int dis[MAXN];
bool vis[MAXN];
priority_queue<pii> pq;
void dij(int s)
{
	rep(i,1,M) dis[i]=INF,vis[i]=0;
	dis[s]=0;
	vis[s]=1;
	pq.push({-0,s});
	pii f;
	int u,v,w;
	while(!pq.empty())
	{
		f=pq.top();
		pq.pop();
		u=f.sec;
		vis[u]=1;
		for(pii e:g[u])
		{
			v=e.fir,w=e.sec;
			if(!vis[v]&&dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				pq.push({-dis[v],v});
			}
		}
	}
}
signed main()
{
	FAST_IO;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	M=m*(n+5);
	rep(i,1,m)
	{
		cin>>w[i];
		g[i].push_back({m+i,w[i]});
		g[m+i].push_back({i,w[i]});
	}
	rep(i,1,n)
	{
		cin>>k[i];
		rep(j,1,k[i])
		{
			cin>>a[i][j]>>t[i][j];
			g[m+a[i][j]].push_back({m*(i+1)+j,t[i][j]});
			g[m*(i+1)+j].push_back({m+a[i][j],t[i][j]});
		}
		rep(x,1,k[i]) rep(y,x+1,k[i])
		{
			g[m*(i+1)+x].push_back({m*(i+1)+y,0});
			g[m*(i+1)+x].push_back({m*(i+1)+y,0});
		}
	}
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		dij(x);
		cout<<dis[y]<<'\n';
	}
	return 0;
}
