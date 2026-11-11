#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],dp[2005][2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
		int mx=0;
		for(int i=1;i<=n;i++)
		  mx=max(a[i],mx);
		cout<<mx;
	}else
	if(n==m)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		  ans=ans&a[i];
		cout<<ans;
	}else
	if(m==2)
	{
		int mx=0;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		    mx=max(mx,a[i]&a[j]);
		cout<<mx;
	}else
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		  cin>>a[i];
		for(int i=1;i<=n;i++)
		  dp[i][1]=a[i];
		for(int i=2;i<=n;i++)
		  for(int j=1;j<min(i,m);j++)
			for(int k=i+1;k<=n;k++)
		      dp[k][j+1]=max(dp[k][j+1],dp[i][j]&a[k]);
		cout<<dp[n][m];
	}else
	{
		int ans=(1<<21)-1;
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++)
		  ans&=a[i];
		cout<<ans;
	}
}