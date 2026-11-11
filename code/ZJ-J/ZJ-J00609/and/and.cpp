#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
bool bj[1000005];
long long ans;
long long k=0;
void dfs(long long x,long long p)
{
	if(x==0)
	{
		cout<<ans;
		return ;
	}
	if(p%2==0) k&=p;
	else 
	{
		k &= p;
		k+1;
	}
	ans=max(ans,k);

	for(int i=1;i<=n;i++)
	{
		if(bj[i]==0)
		{
			bj[i]=1;
			dfs(x-1,a[i]);
			bj[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(m,a[1]);
	/*
	dp[m-1]=a[1];
	for(long long i=1;i<=n;i++)
	{
		for(long long j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],f(dp[j-1],a[i]));
		}
	}
	cout<<dp[1];
	*/
	return 0;
}
