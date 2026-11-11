#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=2*m+n;i++)
	{
		for (int j=1;j<=2*m+n;j++)
		{
			dp[i][j]=0x3f3f3f3f;
			if (i==j)
			{
				dp[i][j]=0;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
		dp[i][i+m]=min(dp[i][i+m],w);
		dp[m+i][i]=min(dp[i+m][i],w);
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			dp[2*m+i][a+m]=min(dp[2*m+i][a+m],t);
			dp[a+m][2*m+i]=min(dp[a+m][2*m+i],t);
		}
	}
	for (int k=1;k<=2*m+n;k++)
	{
		for (int i=1;i<=2*m+n;i++)
		{
			for (int j=1;j<=2*m+n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

