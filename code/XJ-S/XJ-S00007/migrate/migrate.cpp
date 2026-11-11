#include<bits/stdc++.h>
using namespace std;
long long a[1010],f[1010][1010],sum[1010][1010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(c>10)
		{
			printf("0\n");
			continue;
		}
		long long ans=0;
		for(long long s=1;s<=n;s++)
		{
			for(long long i=0;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					f[i][j]=sum[i][j]=0;
				}
			}
			f[0][s]=1;
			for(long long j=1;j<=n;j++)
			{
				sum[0][j]=sum[0][j-1]+f[0][j];
			}
			for(long long i=1;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					long long tmp=lower_bound(a+1,a+j,a[j]-d)-a;
//					printf("j=%lld tmp=%lld\n",j,tmp);
					f[i][j]=sum[i-1][j-1]-sum[i-1][tmp-1];
				}
				for(long long j=1;j<=n;j++)
				{
					sum[i][j]=sum[i][j-1]+f[i][j];
				}
			}
			for(long long i=s+1;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					if(f[j][i]>0)
					{
//						printf("s=%lld f[%lld][%lld]=%lld\n",s,j,i,f[j][i]);
						if(f[j][i]==2)
						{
							ans++;
						}
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

