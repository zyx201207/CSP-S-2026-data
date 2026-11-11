#include<bits/stdc++.h>
using namespace std;
int dp[5005][3005];
int n,m;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{	
			if(dp[i][a[j]]<1) dp[i][a[j]]=dp[i-1][a[j]]+1;
			else dp[i][a[j]]=dp[i-1][a[j]];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<dp[n][i]<<" ";
	}
}
