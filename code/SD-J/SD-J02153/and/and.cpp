#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long int dp[5005][5005]={};
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++) dp[1][j]=a[j];
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=max(dp[i-1][j-1]&a[j],dp[i][j-1]);
		}
	}
	cout<<dp[m][n];
	return 0;
}

