//SN-J00773 林靖轩 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2010;
int n,m,ans=0;
int a[N],dp[N][2][N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		dp[i][1][1]=a[i];
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cout<<dp[i][0][j]<<" "<<dp[i][1][j]<<"\n";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			dp[i][0][j]=max(dp[i-1][0][j],dp[i-1][1][j]&a[i-1]);
			if(j!=1)
				dp[i][1][j]=(max(dp[i-1][0][j-1],dp[i-1][1][j-2]&a[i-1]))&a[i];
		}
	
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cout<<dp[i][0][j]<<" "<<dp[i][1][j]<<"\n";
	for(int i=m;i<=n;i++)
	{
		ans=max(dp[i][0][m],ans);
		ans=max(dp[i][1][m],ans);
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
*/
