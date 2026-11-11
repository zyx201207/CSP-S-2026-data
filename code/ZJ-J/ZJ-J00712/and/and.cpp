#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,dp[2005],ans,mx,p;
ll a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1)
	{
		cout<<mx;
	}
	else if(m==n)
	{
		p=a[1];
		for(ll i=2;i<=m;i++)
		{
			p=p&a[i];
		}
		cout<<p;
	}
	else if(m==2)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(n<=2000)
	{
		dp[0]=2e50-1;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=min(i,m);j>=1;j--)
			{
				dp[j]=max(dp[j],(dp[j-1]&a[i]));
			}
		}
		cout<<dp[m];
	}
	else
	{
		
	}
	return 0;
}
