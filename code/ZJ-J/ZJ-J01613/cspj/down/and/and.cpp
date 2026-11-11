#include<bits/stdc++.h>
using namespace std;
long long n,m;/*
long long x(long long a[],long long s,long long w,long long h)//数组，当前层数，当前乘积，当前位置 
{
	if(s>m-1)
	{
		return w;
	}
	long long z=0;
	for(long long i=h+1;i<=n+s-m+1;i++)
	{
		z=max(z,x(a,s+1,w&a[i],i));
	}
	return z;
}
*/
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long z=0;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+2);
	z=a[n];
	for(long long i=n-1;i>=n-m+1;i--)
	{
		z=z&a[i];
	}
	/*
	for(long long i=1;i<=n-m+1;i++)
	{
		z=max(z,x(a,1,a[i],i));
	}*/
	cout<<z;
	return 0;
}
