#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int x[2000005],b[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;(x[j]-x[i])<=d&&j<=n;j++)
			{
				b[j]++;
			}
		}
		int ans=0;
		for(int i=4;i<=n;i++) if(b[i]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}