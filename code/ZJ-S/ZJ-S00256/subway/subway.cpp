#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
vector<pair<int,int> >v[500005];
int f[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int RP=0,n,m,d,q;
	cin>>RP>>n>>m>>d>>q;
	RP++;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				f[i][j]=2e18;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,j,k;
		for(pair<int,int> o:v[i])
		{
			for(pair<int,int> r:v[i])
			{
				x=o.first;
				y=r.first;
				j=o.second;
				k=r.second;
				if(x!=y)
				{
					f[x][y]=min(f[x][y],j+k);
					f[y][x]=min(f[y][x],j+k);
				}
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
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=2e18;
		int j,k;
		for(pair<int,int> o:v[x])
		{
			for(pair<int,int> r:v[y])
			{
				j=o.first;
				k=r.first;
				ans=min(ans,f[j][k]+o.second+r.second);
			}
		}
		ans+=a[x]+a[y];
		cout<<ans<<"\n";
	}
	return 0;
}//Ä¿±ê:O(m*d^2+n^3+q*d^2)
