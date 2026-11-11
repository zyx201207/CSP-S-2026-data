#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int i,j,s,t,d=1,n,m;
	cin>>n>>m;
	int a[n+1],b[n+1];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=1;i<n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	for(i=1;i<n;i++)
	{
		t=1;
		s=0;
		for(;i+t<=n;t++)
		{
			s=s+b[i+t-1]*t;
			if(s>m)
			break;
		}
		d=max(d,t);
	}
	cout<<d;
}
