#include<bits/stdc++.h>
using namespace std;
long long a[500001],dp[500001]={0};
int main()
{
	int n,m,b=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int f=m;
			if(abs(a[j]-a[j-1])==i&&f>j)
			{
				dp[j-1]+=i;
				f-=j;
				break;
			}
		}
	}
	sort(a,a+n);
		int g=0;
	for(int j=0;j<n;j++)
	for(int i=g;i<n;i++)
	{
		if(a[i]==a[i-1])
		dp[i]++;
		if(a[i]!=a[i-1])
		{
		g=i;
		b++;
		break;
		}
	}
	sort(dp,dp+b);
	cout<<dp[b-1]-1;
}