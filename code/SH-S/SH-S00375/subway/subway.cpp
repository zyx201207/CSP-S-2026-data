#include <bits/stdc++.h>
using namespace std;
long long w[50005];
unsigned long long a[50005][505];
unsigned long long t[50005][505];
bool vis[50005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=0;
		int x1;cin>>x1;
		for(int j=1;j<=x1;j++)
		{
			cin>>a[i][j]>>t[i][j];
//			cin>>t[i][j];
		}
	}
	long long ans=0;
	for(int i=0;i<q;i++)
	{
		int x,y;cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		for(int j=1;j<=n;j++)
		{
			for(int v=1;v<=n;v++)
			{
				if(a[j][v]==x||a[j][v]==y)
				ans+=t[j][v];
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
