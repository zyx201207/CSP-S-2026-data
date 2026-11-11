#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;
int n,m,a[N],dp[N];

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	
	dp[0]=1;
	for(int i=0;i<30;i++)
	{
		dp[0]=(dp[0]<<1)+1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	printf("%lld",dp[m]);
	return 0;
}
