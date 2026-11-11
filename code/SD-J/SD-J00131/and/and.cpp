#include <iostream>
#include <cstdio>
using namespace std;
long long dp[5010][5010];
long long n,m,a,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		dp[i][1]=a;
	}
	for(int k=2;k<=m;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				dp[i][k]=max(dp[i][k-1]&dp[j][k-1],dp[i][k]);
			}
		}	
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][m]);
	}
	printf("%lld",ans);
	return 0;
}
