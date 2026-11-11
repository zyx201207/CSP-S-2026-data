#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define ls (rt*2)
#define rs (rt*2+1)
const int M=5e5+5;
const int N=505;
const int INF=1e17;
const int Mod=1e9+7;
int n,m,d,q;
int w[M],k[N];
struct Edge
{
	int v,w;
};
vector<Edge> G[M];
int dis[N][N];
void floyd()
{
	for(int p=1;p<=n;p++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}
	return;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C;cin>>C;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;cin>>a>>t;
			G[a].push_back(Edge{i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int siz=G[i].size();
		for(int j=0;j<siz;j++)
		{
			int nd1=G[i][j].v,val1=G[i][j].w;
			for(int p=j+1;p<siz;p++)
			{
				int nd2=G[i][p].v,val2=G[i][p].w;
				dis[nd1][nd2]=min(dis[nd1][nd2],val1+val2);
				dis[nd2][nd1]=min(dis[nd2][nd1],val1+val2);
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++)
	{
		int x,y;cin>>x>>y;
		int ans=INF;
		for(auto idx1:G[x])
		{
			int nd1=idx1.v,val1=idx1.w;
			for(auto idx2:G[y])
			{
				int nd2=idx2.v,val2=idx2.w;
				ans=min(ans,val1+val2+dis[nd1][nd2]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
