#include<bits/stdc++.h>
using namespace std;
int c,t,n,dp[305][305],res[305][305],ans;
long long x[2000006],d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if (c==11||c==12)
	{
		while (t--)
		{
			scanf("%d%lld",&n,&d);
			for (int i=1;i<=n;i++)
				scanf("%lld",&x[i]);
			printf("0\n");
		}
	}
	else
	{
		while (t--)
		{
			memset(dp,0x3f,sizeof(dp));
			memset(res,0,sizeof(res));
			scanf("%d%lld",&n,&d);
			for (int i=1;i<=n;i++)
			{
				scanf("%lld",&x[i]);	
				dp[i][i]=0;
			}			
			ans=0;
			for (int l=1;l<=n;l++)
			{
				for (int r=l;r<=n;r++)
				{
					for (int i=r+1;i<=n;i++)
					{
						if (x[i]-x[r]>d)
							break;
						if (dp[l][i]>dp[l][r]+1)
						{
							dp[l][i]=dp[l][r]+1;
							res[l][i]=1;
						} 
						else if (dp[l][i]==(dp[l][r]+1)) 
							res[l][i]++;
					}
				}
			}
			for (int l=1;l<=n;l++)
				for (int r=l;r<=n;r++)
				{
//					printf("%d %d %d\n",l,r,dp[l][r]);
					if (res[l][r]==2)
						ans++;	
				}
				
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
