#include<bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int  c,n,m,dd,q,w[500005];
long long a[505][505];
vector<array<int,2> > va[500005];
void solveB()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=inf;
		}
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto g : va[i])
		{
			for(auto h : va[i])
			{
				a[g[0]][h[0]]=min(a[g[0]][h[0]],0ll+g[1]+h[1]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		for(const auto i : va[x])
		{
			for(const auto j : va[y])
			{
				ans=min(ans,a[i[0]][j[0]]+i[1]+j[1]);
			}	
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			va[a].push_back({i,t});
		}
	}
	solveB();
	return 0;
}
