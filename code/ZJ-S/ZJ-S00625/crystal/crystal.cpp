#include<bits/stdc++.h>
using namespace std;
const long long TNF=1e8;
long long n,m,maxx=0,a[500005],dp[500005],ans=0,maxi[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	bool vis=0;
	long long mai;
	for (int i=1;i<=n;i++)//A
	{
		if (a[i]!=i) vis=1;
	}
	if (vis==0)
	{
		for (int i=1;i<=n;i++)
		{
			if (2*m>=i*(i+1))
			{
				mai=i+1;
			}
			else
			{
				cout<<mai;
				return 0;
			}
		}
	}
	vis=0;
	long long h=a[2]-a[1];
	for (int i=3;i<=n;i++)//B
	{
		if (h!=a[i]-a[i-1]) vis=1;
	}
	if (vis==0)
	{
		for (int i=1;i<=n;i++)
		{
			if (2*m>=i*(a[i]+a[1]))
			{
				mai=i+1;
			}
			else
			{
				cout<<mai;
				return 0;
			}
		}
	}
	//Õý³£ 
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<i;j++) dp[j]=0;
		for (int j=1;j<i;j++)
		{
			long long x=a[i]-a[j];
			dp[j]=x;
		}
		sort(dp+1,dp+i+1);
		for (int j=1;j<i;j++)
		{
			if (ans+dp[j]<=m)
			{
				ans+=dp[j];
				maxi[i]++;
			}
			else break;
		}
	}
	for (int i=1;i<=n;i++)
	{
		maxx=max(maxx,maxi[i]);
	}
	cout<<maxx+1;
	
	return 0;
}
