#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long dp[100001],a[100001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[1]=a[i];
		for(int j=m;j>=1;j--)
		{
			if(j-1==1&&i==n/m)
			{
				continue;
			}
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}



