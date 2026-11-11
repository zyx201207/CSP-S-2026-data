#include<iostream>
using namespace std;
int dp[3100][3100];
int a[4100];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=0;
	for(int i=1;i<=n;i++)
	{
		int x=max(x,a[i]);
		dp[i][1]=x;
	}
	for(int i=2;i<=m;i++) dp[1][i]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<dp[n][m];
	return 0;
}
