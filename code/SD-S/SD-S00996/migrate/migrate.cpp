#include <bits/stdc++.h>
using namespace std;
int c,t,n,m;
long long d;
int x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		int f=1;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
			if(i==2)
			{
				m=x[2]-x[1];
			}
			if(m!=0&&m!=x[i]-x[i-1])
			{
				f=0;
			}
		}
		if(f==1&&d>=m*2)
		{
			printf("%lld\n",(x[n]/m-x[0]/m+1)-3);
		}
		else if(f==1&&d<m*2)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",n-3);
		}
	}
	return 0;
} 
