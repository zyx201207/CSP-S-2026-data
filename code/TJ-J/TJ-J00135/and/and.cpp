#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100010];
int dp[100010][1010];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) dp[1][i]=a[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>0)
			{
				dp[i][j]=max(dp[i-1][j-1]&a[i],a[i]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
