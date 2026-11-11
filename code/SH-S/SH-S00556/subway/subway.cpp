#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	ll p,w,mid;
	bool operator<(const node&x)const
	{
		return w>x.w;
	}
};
int n,m;
const int N=505;
const int M=500005;
ll w[M];
vector<node>a[N];
vector<pair<int,int>>line[M];
ll dis[N];
int pre[N];
bool v[N];
ll dis2[N][N];
int pre2[N][N];
priority_queue<node>q;
void dijkstra(int x)
{
	memset(dis,0x3f,sizeof dis);
	memset(v,0,sizeof v);
	dis[x]=0;
	q.push({x,0});
	while(!q.empty())
	{
		int u=q.top().p;
		q.pop();
		if(v[u]) continue;
		v[u]=1;
		for(auto edg:a[u])
		{
			int k=edg.p;
			int w=edg.w;
			int mid=edg.mid;
			if(k==u) continue;
			if(dis[k]>dis[u]+w)
			{
				dis[k]=dis[u]+w;
				pre[k]=mid;
				q.push({k,dis[k]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=x)
		{
			dis2[x][i]=dis[i];
			pre2[x][i]=pre[i];
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int s,t;
			cin>>s>>t;
			line[s].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(line[i].size()>=2)
		{
			for(int x=0;x<line[i].size();x++)
			{
				for(int y=x+1;y<line[i].size();y++)
				{
					a[line[i][x].first].push_back({line[i][y].first,line[i][y].second+line[i][x].second,i});
					a[line[i][y].first].push_back({line[i][x].first,line[i][y].second+line[i][x].second,i});
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=LLONG_MAX;
		for(auto i:line[x])
		{
			for(auto j:line[y])
			{
				ll tmp=0;
				tmp+=i.second*(pre2[j.first][i.first]==x ? -1 : 1);
				tmp+=j.second*(pre2[i.first][j.first]==y ? -1 : 1);
				ans=min(ans,tmp+dis2[i.first][j.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
