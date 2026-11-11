#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int c,n,m,d,q;
vector<pair<ll,int>> in[N];
ll g[505][505];
ll cst[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>cst[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=0;j<k;j++)
		{
			int u;ll w;
			cin>>u>>w;
			in[u].emplace_back(w,i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int sz=in[i].size();
		for(int j=0;j<sz;j++)
		{
			for(int k=j+1;k<sz;k++)
			{
				g[in[i][j].second][in[i][k].second]=min(g[in[i][j].second][in[i][k].second],in[i][j].first+in[i][k].first);
				g[in[i][k].second][in[i][j].second]=g[in[i][j].second][in[i][k].second];
			}
		}
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=i+1;j<=n;j++)
			{
				if(k==j) continue;
				if(g[i][k]+g[k][j]<g[i][j])
				{
					g[i][j]=g[i][k]+g[k][j];
					g[j][i]=g[i][j];
				}
			}
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		ll res=0x3f3f3f3f3f3f3f3f;
		for(auto i:in[u])
		{
			for(auto j:in[v])
			{
				res=min(res,g[i.second][j.second]+i.first+j.first);
			}
		}
		cout<<res+cst[u]+cst[v]<<'\n';
	}
	return 0;
}
