#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=505,M=5e5+5;
int c,n,m,d,q,k,u,l;
int w[M];
int v[N][N],dis[N][N];
vector<pair<int,int>> g[N],b[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>u>>l;
			g[i].push_back({u,l});
			b[u].push_back({i,l});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		for(auto u:g[i])
		{
			int to=u.first,w1=u.second;
			for(auto y:b[to])
			{
				if(y.first==i) continue;
				v[i][y.first]=w1+y.second;
				dis[i][y.first]=w1+y.second;
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		int ans=1e18;
		for(auto i:b[x])
		{
			for(auto j:b[y])
			{
				ans=min(ans,w[x]+w[y]+dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}