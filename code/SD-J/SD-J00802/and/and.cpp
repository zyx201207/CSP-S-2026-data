#include<bits/stdc++.h>
using namespace std;
int a[20006],dp[20006][20006]={0};
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[1][i]=a[i];
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=(dp[i-1][j]&dp[i-1][j-1]);
		}
	}
	cout<<dp[m][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
