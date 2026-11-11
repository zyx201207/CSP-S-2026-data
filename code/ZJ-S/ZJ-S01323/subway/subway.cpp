#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int M=5e5+5,N=505;
const ll inf=1e18;
int c,n,m,d,q;//n->500,m->5e5,\sum_{k_i}->5e5,d->20,q->1e5
int w[M];//w[i]->1e9
ll dis[N][N];
vector<P>g[M];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			g[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		int sz=g[i].size();
		for(int j=0;j<sz;j++)
		{
			for(int k=j+1;k<sz;k++)
			{
				int u=g[i][j].first,v=g[i][k].first;
				dis[u][v]=min(dis[u][v],(ll)g[i][j].second+(ll)g[i][k].second);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(dis[i][k]!=inf&&dis[k][j]!=inf)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<g[x].size();i++)
		{
			for(int j=0;j<g[y].size();j++)
			{
				ans=min(ans,(ll)g[x][i].second+(ll)g[y][j].second+dis[g[x][i].first][g[y][j].first]);
			}
		}
		cout<<ans+(ll)w[x]+(ll)w[y]<<'\n';
	}
	return 0;
}