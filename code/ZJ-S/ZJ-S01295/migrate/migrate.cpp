#include<bits/stdc++.h>
using namespace std;
int c,T,n,ans,dp[2000005],p[2000005];
long long d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[1]=0;
		int i=1;
		while(i<n)
		{
			int j;
			for(j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d) break;
				dp[j]=dp[i]+1;
			}
			i=j;
			i--;
		}
		if(n!=1&&dp[n]==0) 
		{
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			memset(p,0,sizeof(p));
			int j=i;
			while(j<n)
			{
				int k;
				for(k=j+1;k<=n;k++)
				{
					if(a[j]-a[i]>d) break;
					p[j]=p[i]+1;
				}
				j++;
			}
		}
		ans=dp[n];
		printf("%d\n",ans);
	}
	return 0;
}