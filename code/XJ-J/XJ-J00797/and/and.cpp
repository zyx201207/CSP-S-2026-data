#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],dp[200005],ans,t1,t2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			t1=t1&a[i];
			if(i<=m)
			{
				t2=t2&a[i];
			}
		}
		cout<<max(t1,t2);
		return 0;
	}
	else
	{
		dp[1]=a[1];
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=1;j--)
			{
				dp[j]=max(dp[j],dp[j-1]+dp[j-1]&a[i]);
			}
		}
		cout<<dp[m];
	}
	
	return 0;
} 
