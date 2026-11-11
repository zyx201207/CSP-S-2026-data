#include<bits/stdc++.h>
using namespace std;
long long a[500010]={};
long long dp[500010]={};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n=0;long long m=0;
	cin>>n>>m;
	bool deng=1;long long cha=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i!=0&&i!=1)
		{
			if(a[i]-a[i-1]!=cha)
			{
				deng=0;
			}
		}
		else
		{
			if(i==1)
			{
				cha=a[i]-a[0];
			}
		}
	}
	sort(a,a+n);
	int ans=1;
	if(deng)
	{
		dp[0]=0;
		for(int j=1;j<n;j++)
		{
			dp[j]=dp[j-1]+j*cha;
			if(dp[j]<=m&&j+1>ans)
			{
				ans=j+1;
			} 
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			dp[i]=0;
			for(int j=i+1;j<n;j++)
			{
				dp[j]=dp[j-1]+(j-i)*(a[j]-a[j-1]);
				if(dp[j]<=m&&j-i+1>ans)
				{
					ans=j-i+1;
				} 
			}
		}
	}
	cout<<ans;
	return 0;
}
