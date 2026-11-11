#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10;
int c,n,m,d,q;
ll w[M],e[N][N];
vector<pair<int,ll>>g[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,t;
			cin>>x>>t;
			g[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			e[i][j]=e[j][i]=1e18;
		}
		e[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int u=g[i][j].first;
			ll tu=g[i][j].second;
			for(int k=j+1;k<g[i].size();k++)
			{
				int v=g[i][k].first;
				ll tv=g[i][k].second;
				e[v][u]=e[u][v]=min(e[u][v],tu+tv);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		ll ans=1e18;
		cin>>x>>y;
		if(x==y)
		{
			cout<<"0\n";
			continue;
		}
		for(auto xx:g[x])
		{
			int u=xx.first;
			ll tu=xx.second;
			for(auto yy:g[y])
			{
				int v=yy.first;
				ll tv=yy.second;
				ans=min(ans,tu+tv+e[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}