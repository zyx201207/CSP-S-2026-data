#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,TEXT_NUM,t,m,a[N],f[N],l,g[N],ans,r,sum,mx;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	ans=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=0;
		g[i]=1;
		l=i,r=i;
		for(int v=i+1;v<=n;v++)
		{
			sum=0;
			mx=n+4;
			for(int z=i;z<v;z++)
			{
				if(a[v]-a[z]<=m)mx=min(mx,f[z]);
			}
			for(int z=i;z<v;z++)
			{
				if(a[v]-a[z]<=m&&f[z]==mx)sum+=g[z];
			}
			f[v]=mx+1,g[v]=sum;
//			cout<<i<<" "<<v<<": "<<f[v]<<" "<<l<<"\n";
			if(g[v]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>TEXT_NUM>>t;
	while(t--)solve();
	return 0;
}