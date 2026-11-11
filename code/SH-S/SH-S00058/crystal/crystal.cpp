#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
long long a[500010];
long long ch[500010];
long long dc[500010];
long long dp[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000)
	{
		long long c=a[2]-a[1];
		for(int i=n;i>=1;i--)
		{
			if(i*(i+1)/2*c<=m)
			{
				cout<<i+1<<endl;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ch[i]=a[i]-a[i-1];
		dc[i]=dc[i-1]+ch[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[1]+=(i-1)*ch[i];
	}
	for(int k=n-1;k>=1;k--)
	{
		dp[n-k+1]=dp[n-k]-dc[n]+dc[n-k-1];
		if(dp[n-k+1]<=m)
		{
			cout<<k<<endl;
			return 0;
		}
		for(int i=1;i<=n-k;i++)
		{
			dp[i]-=k*ch[i+k];
			if(dp[i]<=m)
			{
				cout<<k<<endl;
				return 0;
			}
		}
	}
	return 0;
}
