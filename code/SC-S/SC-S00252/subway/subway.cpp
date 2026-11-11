#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=504;
const int maxm=5e5+9;
const int INF=1e18;
int n,m,dd,qq;
int w[maxm];
int k[maxn];
struct edge
{
	int v,x;
	bool operator<(const edge ii)const{
		return x>ii.x;
	}
};
priority_queue<edge> q;
vector<edge> e[maxm+maxn];
int di[maxn][maxn];
int dis[maxm+maxn];
int tot=0;
void dijkstra(int x)
{
	for(int i=1;i<=n+m;i++) dis[i]=INF;
	dis[x]=0;
	edge tmp;tmp.v=x,tmp.x=0;
	q.push(tmp);
	while(!q.empty())
	{
		int u=q.top().v;q.pop();
		for(auto v:e[u])
		{
			int a=v.x;
			if(dis[v.v]>dis[u]+a)
			{
				dis[v.v]=dis[u]+a;
				q.push({v.v,a});
			}
		}
	}
	for(int i=1;i<=n;i++) di[x][i]=di[i][x]=dis[i];
}
vector<int> a[maxn],t[maxn];
vector<int> fa[maxm];
map<int,int> d[maxn];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int guan;
	cin>>guan>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	tot=n;
	for(int i=1;i<=n;i++) 
	{
		cin>>k[i];
		tot+=k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			e[i].push_back({a[i][j]+n,t[i][j]});
			e[a[i][j]+n].push_back({i,t[i][j]});
			fa[a[i][j]].push_back(i);
			d[i][a[i][j]]=t[i][j];
		}
	}
	for(int i=1;i<=n;i++) dijkstra(i);
	while(qq--)
	{
		int ans=INF;
		int x,y;
		cin>>x>>y;
		for(int i=0;i<fa[x].size();i++)
		{
			for(int j=0;j<fa[y].size();j++)
			{
				int u=fa[x][i];
				int v=fa[y][j];
				/*
				cout<<"upd\n";
				cout<<u<<' '<<v<<'\n';
				*/
				//cout<<t[u][i+1]<<" "<<t[v][j+1]<<'\n';
				ans=min(ans,di[u][v]+d[u][x]+d[v][y]+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	/*
	cout<<"G";
	for(int i=1;i<=m;i++) 
	{
		cout<<i<<'\n';
		for(auto v:fa[i]) cout<<v<<' '<<t[v][i]<<'\n';
		cout<<'\n';
	}
	for(int i=1;i<=n;i++) 
	{
		for(int j=i;j<=n;j++)
		{
			cout<<i<<" "<<j<<'\n';
			cout<<di[i][j]<<'\n';
		}
		cout<<'\n';
	}
	*/
	return 0;
}