#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[10000000],ans,x,q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	x=n;
	for (int i=1;i<=n;i++)
	{
		if (n%2==1)
		{
			q=a[(n+1)/2];
			for (int j=1;j<=n;j++)
			{
				if (j<=(n+1)/2)
				{
					b[j]=a[(n+1)/2]-a[j];	
				}
				else
				{
					b[j]=a[j]-a[(n+1)/2];
				}
			}
		}
		else
		{
			q=a[n/2];
			for (int j=1;j<=n;j++)
			{
				if (j<=n/2)
				{
					b[j]=a[n/2]-a[j];	
				}
				else
				{
					b[j]=a[j]-a[n/2];
				}
			}
		}
	}
	for (int i=n;i>=0;i--)
	{
		if (a[i]==q)
		{
			ans++;
		}
		if (a[i]<q)
		{
			if (x>0)
			{	
				x-=b[i];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
 } 
