#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[5005],dp[5005],sum[5005];

int siu(int ai)
{
	if (ai==0)
	{
		return 1;
	}
	else
	{
		if (((ai-1)*a[ai]-sum[ai-1])<=m)
			return ai;
		else
			siu(ai-1);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	sum[1] = a[1];
	for (int i = 2;i <= n;i++)
	{
		sum[i] = sum[i-1] + a[i];
	}
	dp[1] = 1;
	for(int i = 2;i <= n;i++)
	{
		dp[i] = siu(i);
	}
	cout << dp[n];
	return 0;
}
