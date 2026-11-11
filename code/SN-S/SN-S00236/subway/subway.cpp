#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int maxn=5e5+5;
int c, n, m, d, q, w[maxn], mp[505][505];
vector<pair<int,int> > vec[maxn];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			int x, y;
			cin>>x>>y;
			vec[x].push_back(make_pair(i, y));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) mp[i][j]=1e18;
		mp[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto x:vec[i])
		{
			for(auto y:vec[i])
			{
				if(x.fi==y.fi) continue;
				mp[x.fi][y.fi]=mp[y.fi][x.fi]=min(mp[x.fi][y.fi], x.se+y.se);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mp[i][j]=min(mp[i][j], mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--)
	{
		int x, y;
		cin>>x>>y;
		int ans=1e18;
		for(auto i:vec[x])
		{
			for(auto j:vec[y])
			{
				ans=min(ans, mp[i.fi][j.fi]+i.se+j.se);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
