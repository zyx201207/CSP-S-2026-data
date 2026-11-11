#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int j=1;j<=t;j++)
	{
		int n;
		scanf("%d",&n);
		ll d;
		scanf("%lld",&d);
		for(int i=1;i<=n;i++)
		{
			ll b;
			scanf("%lld",&b);
			x[i]=b;
		}
		if(c==11||c==12||c==0)
		{
			ll D=x[2]-x[1];
			if(D>d)printf("0\n");
			else
			{
				int num=4;
				while(D<d)
				{
					D*=2;
					num++;
				}
				printf("%d\n",n-num+1);
			}
		}
	}
	return 0;
}
