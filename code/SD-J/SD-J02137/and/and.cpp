#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<int> a;
vector<vector<int>> dp;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a.assign(n+5,0);
	dp.assign(m+5,vector<int>(n+5,0));
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		dp[1][i]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<j;k++) dp[i][j]=max(dp[i][j],(dp[i-1][j]&a[k]));
		}
	}
	cout<<dp[m][n];
} 

