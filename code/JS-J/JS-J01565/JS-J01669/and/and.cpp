#include <bits/stdc++.h>
using namespace std;
int a[200010];
int dp[200010][2];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int k=1;k<=n;k++)
	{
		cin>>a[k];
	}
	int ans=0;
	int f=0;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(j==1)
			{
				dp[i][0]=a[i];
				ans=max(ans,dp[i][0]);
			}
			else if(f==0)
			{
				int u=a[i];
				int x=dp[i-1][0];
				dp[i][1]=max((u&x),u);
				ans=max(ans,dp[i][1]);
			}
			else
			{
				int u=a[i];
				int x=dp[i-1][1];
				dp[i][0]=max((u&x),u);
				ans=max(ans,dp[i][0]);
			}
		}
		if(f==0) f=1;
		else f=0;
	}
	cout<<ans;
	return 0;
}
