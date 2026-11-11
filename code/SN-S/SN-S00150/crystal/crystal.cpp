#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5050;
int n,m,a[MAXN],dp[MAXN][MAXN],sum=0,ans=0,maxn=0,x=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=i;
	}
	for(int i=1;i<=n;i++)
	{
		if((a[i]-a[i-1])!=(a[i-1]-a[i-2])&&i>2) x=1;
		sum+=(a[i]-a[i-1])*(i-1);
		dp[i][0]=1;
		for(int j=1;j<=sum;j++)
		{
			dp[i][j]=max(dp[i-1][j-((a[i]-a[i-1])*ans)]+1,dp[i-1][j]);//
			//cout<<dp[i][j]<<" ";
		}
		//cout<<"        ans:"<<ans<<"  sum:"<<sum<<endl;
		ans+=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) maxn=max(maxn,dp[i][j]);
		//cout<<dp[i][m]<<" ";
	}
	if(x==0)
	{
		int y=0,num=0;
		while((num*(a[2]-a[1]))<=m&&y<=n)
		{
			y++;
			num+=y;
		}
		if((a[2]-a[1])==1)cout<<y-1;
		else cout<<y;
		return 0;
	}
	cout<<min(maxn+1,n);
	return 0;
} 
