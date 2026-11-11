#include <bits/stdc++.h>

using namespace std;
int n,m,a[200005],dp[20005][20005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=INT_MAX;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min(i,m);j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	//for(int i=0;i<=n;i++)
	//{
	//	for(int j=0;j<=m;j++)
	//	{
	//		cout<<dp[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}//
	cout<<dp[n][m];
	return 0;
}
//Hello,Hello,Helloween!!! 
//Hello,Hello,Helloween!!! 
//Hello,Hello,Helloween!!! 
//Trick||Treat!
//Trick||Treat!
//Trick||Treat!
