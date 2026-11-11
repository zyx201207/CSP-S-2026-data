#include <bits/stdc++.h>

using namespace std;

const int N=2e6+5;

int opt,t,n,cnt[N];

long long a[N],f[N],ans,m;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>opt>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				f[j]=1e18;
				cnt[j]=0;
			}
			f[i]=0;
			for(int j=i+1;j<=n;j++)
			{
				for(int k=i;k<j;k++)
				{
					if(a[j]-a[k]<=m&&f[j]>=f[k]+1)
					{
						if(f[j]==f[k]+1)
						{
							cnt[j]++;
						}
						else
						{
							cnt[j]=1;
							f[j]=f[k]+1;
						}
					}
				}
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
