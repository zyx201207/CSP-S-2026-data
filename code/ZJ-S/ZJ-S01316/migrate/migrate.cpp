#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000005];
int dp[5005][5005],vis[5005][5005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		if(n>5e4)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)vis[i][j]=1,dp[i][j]=1;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				cout<<dp[i][j]<<" ";
//			}cout<<endl;
//		}
		for(int l=1;l<=n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				if(vis[l][r])continue;
				for(int k=l+1;k<r;k++)
				{
//					cout<<l<<" "<<r<<" "<<k<<endl;
//					cout<<dp[l][r]<<" "<<dp[l][k]<<" "<<dp[k+1][r]<<endl;
					dp[l][r]+=dp[l][k]*dp[k][r];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
//				cout<<dp[i][j]<<" ";
				if(dp[i][j]==2)ans++;
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
