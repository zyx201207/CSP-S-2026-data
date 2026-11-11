#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[j]);
		}
		if(n<=3)
		{
			printf("0\n");
		}
		else
		{
			long long u=a[2]-a[1];
			long long qw=d/u;
			if(qw<2)
			{
				printf("0\n");
			}
			if(n>=qw*2)
			{
				printf("%lld\n",n-(qw+1));
			}
			else if(n>=qw+1)
			{
				printf("%lld\n",n-(qw+1));
			}
			else
			{
				printf("0\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
