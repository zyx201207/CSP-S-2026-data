#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,m;
ll a[N],ans;
ll check(int s)
{
	int num=0,su=0,pl=0;
	for(int i=0;i<n;i++)
	{
		if ((s>>i)&1)
		{
			num++;
			if (su==0)
			{
				pl=a[i+1];
				su=1;
			}
			else
			{
				pl=pl&a[i+1];
			}
		}
	}
	if (num==m)
	{
		return pl;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool z=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if (a[i]!=i-1)
		{
			z=0;
		}
	}
	sort(a+1,a+n+1);
	if (n<=20)
	{
		ll sum=1<<n;
		for (int i=1;i<sum;i++)
		{
			ans=max(ans,check(i));
		}
		cout << ans;
	}
	else if (m==1)
	{
		cout << a[n];
	}
	else if (m==n)
	{
		ans=a[1];
		for (int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		return 0;
	}
	else if (m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ll l=a[i]&a[j];
				ans=max(ans,l);
			}
		}
		cout << ans;
		return 0;
	}
	else if (z)
	{
		cout < 0;
		return 0;
	}
	else
	{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			ans=ans&a[i];	
		}
		cout << ans;
		return 0;
	}
	return 0;
}
