#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
 	int arr[200010]={};
	int dp[m+10][n+10]={};
	for(int i=1;i<n+1;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==1&&j!=1)
			{
				dp[i][j]=max(dp[i][j-1],arr[j]);
			}else
			if(j<=i&&j!=1)
			{
				dp[i][j]=dp[i][j-1]^arr[j];
			}
			else if(j==1)
			{
				dp[i][j]=arr[1];
			}
			else{
				dp[i][j]=max(dp[i-1][j-1]^arr[j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[m][n]; 
	return 0;
}
