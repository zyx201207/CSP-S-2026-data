#include<bits/stdc++.h>
using namespace std;

long long f[505][505];
long long s[505][505];
long long a[1000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		memset(f,0x3f,sizeof(f));
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				if(abs(a[j]-a[i])<=d)
				{
					f[i][j]=1;
				}
			}
		}
		for(long long k=1;k<=n;k++)
		{
			for(long long i=1;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
				}
			}
		}
		memset(s,0,sizeof(s));
		for(long long k=1;k<=n;k++)
		{
			for(long long i=1;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					if(f[i][k]+f[k+1][j]==f[i][j])
					{
						s[i][j]++;
					}
				}
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				if(s[i][j]==3)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
