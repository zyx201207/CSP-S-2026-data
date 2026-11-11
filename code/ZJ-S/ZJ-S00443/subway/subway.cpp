#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge
{
	int to;
	int qz;
};
int c,n,m,d,q,w[500505],a,t,k[505];
vector<edge> tr[500505];
vector<edge> gt[500505];
int x,y;
int dis[505][505];
signed main()
{
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++)
	{ 
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin>>k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin>>a>>t;
			tr[i].push_back({a,t});
			gt[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i = 1;i <= n;i++)
	{
		dis[i][i] = 0;
		for(auto j : tr[i])
		{
			for(auto jj : gt[j.to])
			{
				dis[i][jj.to] = dis[jj.to][i] = min(dis[i][jj.to],j.qz+jj.qz);
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int mid = 1;mid <= n;mid++)
		{
			for(int j = 1;j <= n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][mid]+dis[mid][j]);
			}
		}
	}
	while(q--)
	{
		cin>>x>>y;
		int ans = 1e18;
		for(auto i : gt[x])
		{
			for(auto j : gt[y])
			{
				ans = min(ans,i.qz+j.qz+dis[i.to][j.to]);
			}
		}
		cout<<(ans+w[x]+w[y])<<'\n';
	}
	return 0;
}
