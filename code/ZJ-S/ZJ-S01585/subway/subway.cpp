#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define mk_p make_pair
using namespace std;
const int N=505,M=1e6+10;
struct node
{
	int v,w;
};
vector<pair<int,int> >G[M];
int T[M],f[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",T+i);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,t;
			scanf("%lld%lld",&x,&t);
			G[m+i].push_back(mk_p(x,t));
			G[x].push_back(mk_p(m+i,t));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<G[i].size()-1;j++)
		{
			for(int k=j+1;k<G[i].size();k++)
			{
				int u=G[i][j].fi-m,v=G[i][k].fi-m,w=G[i][j].se+G[i][k].se;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int s,e,mint=1e18;
		scanf("%lld%lld",&s,&e);
		for(int i=0;i<G[s].size();i++)
		{
			for(int j=0;j<G[e].size();j++)
			{
				int u=G[s][i].fi-m,v=G[e][j].fi-m,w=G[s][i].se+G[e][j].se;
				mint=min(mint,f[u][v]+w);
			}
		}
		cout<<mint+T[s]+T[e]<<'\n';
	}
	return 0;
}

