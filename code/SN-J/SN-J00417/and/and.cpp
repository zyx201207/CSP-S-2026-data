#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=200050;
int n,m,a[MAXN],sum=0,dp[20050][2050];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) dp[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][1]=a[i];
		for(int j=2;j<=m;j++)
		{
			for(int k=1;k<i;k++) dp[i][j]=max((dp[i-k][j-1]&a[i]),dp[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum=max(dp[i][m],sum);
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<dp[n-1][m]<<" ";*/
	cout<<sum;
	return 0;
}
