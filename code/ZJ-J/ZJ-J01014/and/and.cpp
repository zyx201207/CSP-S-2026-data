#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010],s[100],s1[200010][50],dp[200010][410];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==m)
	{
		ll z=a[1];
		for(int i=1;i<=n;i++)
		{
			z&=a[i];
		}
		cout<<z;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ll a1=a[i],x=1;
		while(a1)
		{
			if(a1%2==1)
			{
				s[x]++;
				s1[i][x]=1;
			}
			a1/=2;
			x++;
		}
	}
	if(m==n-1)
	{
		ll ff=0;
		for(int i=30;i>=1;i--)
		{
			if(s[i]==m)
			{
				for(int j=1;j<=n;j++)
				{
					if(s1[j][i]==0)
					{
						ff=j;
						break;
					}
				}
				break;
			}
		}
		ll z=a[1];
		if(ff=1)
		{
			z=a[2];
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=ff)
			{
				z&=a[i];
			}
		}
		cout<<z;
		return 0;
	}
	if(m==2)
	{
		ll ma=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					ma=max(ma,a[i]&a[j]);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=a[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=min(i,m);j++)
		{
			dp[i][j]=max(dp[i][j],max(dp[i-1][j-1]&a[i],dp[i][j-1]&a[i]));
		}
	}
	cout<<dp[n][m];
	return 0;
}
