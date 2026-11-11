#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		int mx=INT_MIN;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>mx) mx=a[i]&a[j];
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		int f=a[1];
		for(int i=2;i<=n;i++)
		{
			f=f&a[i];
		}
		cout<<f;
		return 0;
	}
	if(m==n-1)
	{
		int mx=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			int f;
			if(i==1)
			{
				f=a[2];
				for(int j=3;j<=n;j++)
				{
					f=f&a[j];
				}
			}
			else
			{
				f=a[1];
				for(int j=2;j<=n;j++)
				{
					if(i!=j)f=f&a[j];
				}
			}
			if(f>mx)mx=f;	
		}
		cout<<mx;
		return 0;
	}
	return 0;
}