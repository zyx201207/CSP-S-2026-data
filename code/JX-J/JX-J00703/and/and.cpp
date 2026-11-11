#include<bits/stdc++.h>
using namespace std;
int a[200200];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==1)
	{
		cout<<a[1];
		return 0;
	}
	if(m==1)
	{
		cout<<a[n];
	}
	if(n==2)
	{
		cout<<(a[1] & a[2]);
		return 0;
	}
	if(m==n)
	{
		sum=a[1] & a[2];
		for(int i=3;i<=m;i++)
		{
			sum=sum & a[i];
		}
		cout<<sum;
		return 0;
	}
	sum=a[n] & a[n-1];
	for(int i=n-2;i>=n-m+1;i--)
	{
		sum=sum & a[i];
	}
	cout<<sum;
	return 0;
}
