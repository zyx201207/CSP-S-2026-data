#include<bits/stdc++.h>
using namespace std;

long long n,m,ans=0;
long long a[500007];
long long dp[500007];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	dp[0]=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=i;j++)
		{
		
			long long x=dp[i]-dp[j-1];
			long long y=a[i]*(i-j+1);
			if(x+m>=y)
			{
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
