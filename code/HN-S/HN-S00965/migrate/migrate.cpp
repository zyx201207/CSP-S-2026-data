#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100005],dd;
int d[1005][1005],f[1005][1005],ans;
void solve()
{
	cin>>n>>dd;
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=1;
			if(abs(a[i]-a[j])<=dd) d[i][j]=abs(a[i]-a[j]);
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n&&j!=i;j++)
			{
				if(d[i][k]+d[k][j]==d[i][j]) f[i][j]++;
				if(d[i][k]+d[k][j]<d[i][j])
				{
					
					f[i][j]=1;
					d[i][j]=d[i][k]+d[k][j];
				}
			}
	for(int j=1;j<=n;j++)
		for(int i=j+1;i<=n;i++)
		{
			cout<<f[i][j]<<'\n';
			if(f[i][j]==2)ans++;
		}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c>>t;
	while(t--) solve();
} 
