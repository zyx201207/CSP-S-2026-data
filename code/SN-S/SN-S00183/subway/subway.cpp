#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[405];
int a[405][405];
int dxy[405][405];
void solve()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				dxy[j][k]=min(dxy[j][i]+dxy[i][k],dxy[j][k]);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
//	if(c<=8)
//	{
		for(int i=1;i<=405;i++)
		{
			for(int j=1;j<=405;j++)
			{
				a[i][j]=0x3f3f3f3f;
				dxy[i][j]=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int x;
				cin>>x;
				cin>>a[i][x];
			}
		}
		solve();
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			int ans;
			ans=w[x]+w[y];
			ans+=dxy[x][y];
			cout<<ans<<"\n";
		}
//	}
	
	return 0;
}
