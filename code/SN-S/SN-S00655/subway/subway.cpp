#include <bits/stdc++.h>
using namespace std;
int const N=1005;
int a[N];
int dp[N];
int main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=10000;i++)
	{
		cin>>a[i];
	}
	dp[0]=0;
	dp[1]=a[1];
	for(int i=2;i<=10000;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+a[i]);
	}
	cout<<dp[N];
	return 0;
}
