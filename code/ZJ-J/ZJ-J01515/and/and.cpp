#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,a[N],dp[N][N],ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1][1]=a[1];
	if(m==1)
	{
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		dp[i][1]=a[i];
		for(int j=2;j<=min(i,m);j++)
		{
			for(int k=1;k<i;k++)
			{
				dp[i][j]=max({dp[i][j],dp[k][j-1]&a[i],dp[k][j]});
			}
		}
//		cout<<dp[i][1]<<" "<<dp[i][2];
//		cout<<'\n';
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}
