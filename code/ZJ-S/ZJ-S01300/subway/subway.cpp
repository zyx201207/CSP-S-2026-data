#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll INF=LLONG_MAX>>4;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	vector<vector<pair<int,ll>>> f(m+1);
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a;ll t;
			cin>>a>>t;
			f[a].push_back({i,t});
		}
	}
	vector<vector<ll>> g(n+1,vector<ll>(n+1,INF));
	for(int i=1;i<=n;i++)
	{
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto[x,tx]:f[i])
		{
			for(auto[y,ty]:f[i])
			{
				g[x][y]=min(g[x][y],tx+ty);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		ll ans=INF;
		for(auto[x,tx]:f[u])
		{
			for(auto[y,ty]:f[v])
			{
				ans=min(ans,w[u]+w[v]+tx+ty+g[x][y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}