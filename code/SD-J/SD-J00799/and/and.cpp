#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],s[200005],m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=(s[i-1]&a[i]);
	}
	if(m==n)cout<<s[n];
	else if(m==1)
	{
		long long d=0;
		for(int i=1;i<=n;i++)d=max(a[i],d);
		cout<<d;
	}
	else if(m==2)
	{
		long long d=0;
		for(int i=1;i<=n;i++)
		 for(int j=i+1;j<=n;j++)
		 {
		 	d=max((a[i]&a[j]),d);
		 }
		 
		cout<<d;
	}
	else if(m==n-1)
	{
		long long d=0;
		for(int i=1;i<=n;i++)
		{
			d=max((a[i-1]&(a[n]&a[i])),d);
		}
		cout<<d;
	}
	return 0;
} 
