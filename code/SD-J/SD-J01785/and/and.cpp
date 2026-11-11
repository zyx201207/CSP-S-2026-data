#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[200005],dp[200005][5],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dp[i][1]=a[i];
	for(int k=2;k<=m;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				dp[i][k%2]=max(dp[i][k%2],dp[j][!(k%2)]&a[i]);
			}
		}
	}
	for(int i=1;i<=n;i++)maxn=max(maxn,dp[i][m%2]);
	cout<<maxn;
	return 0;
} 
