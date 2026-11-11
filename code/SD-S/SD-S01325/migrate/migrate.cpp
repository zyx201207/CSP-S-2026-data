#include<bits/stdc++.h>
using namespace std;
int c,t,x[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&c);
	scanf("%d",&t);
	if((c==11)||(c==12))
	{
		for(int p=1;p<=t;p++)
		{
			int n;
			long long d;
			scanf("%d",&n);
			scanf("%lld",&d);
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&x[i]);
			}
			int dd=x[2]-x[1];
			int k=d/dd,ans=0;
			for(int i=1;i<=n-1;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(((j-i)/k+1==2)&&(j-i)%k!=0)
					{
						ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
