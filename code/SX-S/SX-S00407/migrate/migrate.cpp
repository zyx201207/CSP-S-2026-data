#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
int c1[2010][2010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,m,ans;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		memset(c1,0,sizeof(c1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(a[i]-a[j]<=m)
				{
					c1[i][j]++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(c1[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}