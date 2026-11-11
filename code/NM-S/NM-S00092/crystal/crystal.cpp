#include<bits/stdc++.h>
using namespace std;
int a[500010],c[500010];
int main()
{
	long long n,m,i,d,h,z=0,x=0,q=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[i+1])
		{
			h=a[i];
			a[i]=a[i+1];
			a[i+1]=h;
		}
	}
	for(i=1;i<=n-1;i++)
	{
		c[i]=a[i+1]-a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(c[i]+c[i+1]>z&&c[i]+c[i+1]<=m)
		{
			z=c[i]+c[i+1];
			d=3;
		}
		if(c[i]+c[i+1]+c[i+2]>x&&c[i]+c[i+1]+c[i+2]<=m)
		{
			x=c[i]+c[i+1]+c[i+2];
			d=4;
		}
		if(c[i]+c[i+1]+c[i+2]+c[i+3]>q&&c[i]+c[i+1]+c[i+2]+c[i+3]<=m)
		{
			q=c[i]+c[i+1]+c[i+2];
			d=5;
		}
	}
	cout<<d;
	return 0;
}
