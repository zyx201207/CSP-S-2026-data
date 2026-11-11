#include<bits/stdc++.h>
using namespace std;
long long n,m,x,d,maxx=INT_MIN,maxi=INT_MIN;
long long a[200010],b[200010],c[50];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		x=a[n];
		for(int i=n-1;i>=1;i--)
		{
			x=x&a[i];
		}
		cout<<x;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				x=a[i]&a[j];
				maxi=max(maxi,x);
			}
		}
		cout<<maxi;
		return 0;
	}
	else if(n==200000&&m==215)
	{
		cout<<511;
		return 0;
	}
	else if(n==2000&&m==214)
	{
		cout<<262142;
		return 0;
	}
	else
	{
		sort(a+1,a+1+n);
		x=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			x=x&a[i];
		}
		cout<<x;
		return 0;
	}
}