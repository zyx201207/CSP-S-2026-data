#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<vector<long long> > dp(n+1,vector<long long>(m+1,0));
	vector<long long> nums(n+1);
	for(long long i=1;i<=n;i++)
	{
		cin>>nums[i];
		dp[i][1]=dp[i-1][1];
		if(nums[i]>dp[i][1])
		{
			dp[i][1]=nums[i];
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=2;j<=m;j++)
		{
			dp[i][j]=max(nums[i]&dp[i-1][j-1],dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
