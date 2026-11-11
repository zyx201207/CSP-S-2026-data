#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=50010,INF=0x3f3f3f3f3f3f3f3f;
struct Edge
{
	ll w;//w表示从地铁口走到站厅的时间 
	ll tot,h[510];//id表示是第几号线路,h表示从站厅走到站台的时间 
};
Edge eg[N];
ll id[N][510];
ll c,n,m,d,q,dist[N],a[510][N],t[510][N];
bool vis[N],vi[N];
vector<ll> e[N],same,way[N],xian[N];
ll sum;
void dfs(int u,int lst)
{
	bool flag=true;
	vi[v]=true;
	if(u==lst)
	{
		way[sum].push_back(u);
		sum++;
		return;
	}
	for(ll v:e[u])
	{
		if(!vi[v]) f=false;
		if(vi[i]) continue;
		dfs(v,lst);
	}
	if(f)
	{
		way[sum].clear();
		xian[sum].clear();
		return;
	}
}
void dijk(int sta,int lst)
{
	bool flag=false;
	for(int i=1;i<=eg[sta].tot;i++)
	{
		for(int j=1;j<=eg[lst].tot;j++)
		{
			if(id[sta][j]==id[lst][j])
			{
				flag=true;
				same.push_back(id[lst][j]);
			}
		}
	}
	if(flag)
	{
		ll minn=INF,mn2=INF;
		for(ll x:same)
		{
			minn=min(minn,eg[sta].h[x]);
			mn2=min(mn2,eg[lst].h[x]);
		}
		dist[lst]=eg[sta].w+minn+mn2+eg[lst].w;
		return;
	}
	ll minn=INF;
//	for(int i=1;i<=eg[sta].tot;i++) minn=min(minn,eg[sta].h[i]);
//	dist[sta]=eg[sta].w+minn;
	ll res=0;
	for(int i=1;i<=sum;i++)
	{
		ll len1=(int)way[i].size(),len2=(int)way[i].size(),gone=0;
		for(!way[i].empty())
		{
			int u=way[len1].back(); way[i].pop_back(); len1--;
			gone=way[i].back();
			flag=false;
			if(len1==(len2-2))
			{
				ll xian=0;
				for(int i=1;i<=eg[u].tot;i++)
				{
					for(int j=1;j<=eg[gone].tot;j++)
					{
						if(id[u][j]==id[gone][j])
						{
							flag=true;
							xian=id[u][j];
							break;
						}
					}
				}
				if(!flag) res+=eg[u].w+eg[u].h[xian];
			}
		}
		dist[lst]=min(dist[lst],res);
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		ll w;
		cin>>w;
		eg[i].w=w;
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			eg[a[i][j]].tot++;
			id[a[i][j]][eg[a[i][j]].tot]=i;
			eg[a[i][j]].h[eg[a[i][j]].tot]=t[i][j];
			for(int k=1;k<j;k++)
			{
				e[a[i][k]].push_back(a[i][j]);
				e[a[i][j]].push_back(a[i][k]);
			}
		}
	}
	while(q--)
	{
		for(int i=1;i<=m;i++) dist[i]=INF,vis[i]=false,vi[i]=false;
		sum=0;
		ll sta,lst;
		cin>>sta>>lst;
		dfs(sta,lst);
		dijk(sta,lst);
		cout<<dist[lst]<<'\n';
	}
	return 0;
}
