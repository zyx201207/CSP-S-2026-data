#include <bits/stdc++.h>
#define int long long
using namespace std;
/*====================*/
const int N=5e3+50;
int c;
int a[N];
int dp[N][N];
int ans[N][N];
/*====================*/
void Solve(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=1e18;
			ans[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=m)
			{
				dp[i][j]=dp[j][i]=1;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==k||i==j||j==k)
				{
					continue;
				}
//				cout<<k<<" "<<i<<" "<<j<<endl;
				if(dp[i][j]==dp[i][k]+dp[k][j])
				{
					ans[i][j]++;
//					cout<<"_______"<<i<<" "<<j<<" "<<k<<endl;
				}
				else if(dp[i][j]>dp[i][k]+dp[k][j])
				{
					dp[i][j]=dp[i][k]+dp[k][j];
					ans[i][j]=1;
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
//			cout<<ans[i][j]<<" ";
			if(ans[i][j]==2)
			{
				cnt++;
			}
		}
//		cout<<endl;
	}
	cout<<cnt/2<<endl;
}
/*====================*/
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	int T=1; cin>>T;
	while(T--) Solve();
	return 0;
}
/*
0 1
6 5
-5 -4 -3 1 6 11

*/
