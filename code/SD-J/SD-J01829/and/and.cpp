#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%ld%ld",&n,&m); 
	for(int i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
	}
	dp[0]=0x3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	printf("%d",dp[m]);
	return 0;
}
