#include<bits/stdc++.h>
using namespace std;
const int maxN=1e4+1;
int n,m;
long long a[maxN];
long long dp[maxN][maxN];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n>maxN)
	{
		cout<<0;
		return 0;
	 } 
	for(int i=1;i<=n;i++) cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dp[i][1]=a[i];
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=i;j++)
		{
			if(dp[i-1][j]<=(dp[i-1][j-1]&a[i]))
			{
				dp[i][j]=(dp[i-1][j-1]&a[i]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][m];
	return 0;
} 
